#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e5+5;
const int mo = 1e9+7;

LL js[N],inv[N];

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int n;
int a[N];
int pri[N],lst[N],k;
bool bz[N];
int cnt[N][20];
LL pre1[N],pre2[N],suf[N];

LL solve1(int l,int r){
	if (l>r)return 0;
	//i=l..r
	//b<a
	LL ret=0;
	if (r==0)return 0;
	ret=(pre1[r-1]*r+mo-pre2[r-1])%mo;
	if (l>1){
		l--;
		ret=dec(ret,(pre1[l-1]*l+mo-pre2[l-1])%mo);
	}
	return ret;
}

LL solve2(int l,int r){
	r=min(r,n-2);
	if (l>r)return 0;
	LL ret=0;
	int p=n-2-r;
	ret=(suf[p]+(p?pre1[p-1]:0ll)*(r+1))%mo;
	if (l){
		l--;
		int p=n-2-l;
		ret=dec(ret,(suf[p]+(p?pre1[p-1]:0ll)*(l+1))%mo);
	}
	return ret;
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	lst[1]=1;
	js[0]=js[1]=1;
	fo(i,2,3e5)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,3e5)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,3e5)inv[i]=inv[i]*inv[i-1]%mo;
	fo(i,0,n-1){
		pre1[i]=((i?pre1[i-1]:0)+calc(n-1,i))%mo;
		pre2[i]=((i?pre2[i-1]:0)+calc(n-1,i)*i)%mo;
	}
	fd(i,n-1,0){
		suf[i]=(suf[i+1]+calc(n-1,i)*(n-1-i))%mo;
	}
	fo(i,2,3e5){
		if (!bz[i]){
			pri[++k]=i;
			lst[i]=i;
		}
		fo(j,1,k){
			if (1ll*i*pri[j]>3e5)break;
			bz[i*pri[j]]=1;
			lst[i*pri[j]]=pri[j];
			if (i%pri[j]==0){
				break;
			}
		}
	}
	fo(i,1,n){
		int x=a[i];
		for(;x>1;){
			int p=lst[x];
			int t=0;
			for(;x%p==0;x/=p)t++;
			cnt[p][t]++;
		}
	}
	LL ans=0;
	fo(i,2,3e5)
	if (!bz[i]){
		cnt[i][0]=n;
		fo(j,1,18)cnt[i][0]-=cnt[i][j];
		int pre=cnt[i][0];
		fo(j,1,18)
		if (cnt[i][j]){
			LL v=dec(solve1(pre,pre+cnt[i][j]-1),solve2(pre,pre+cnt[i][j]-1));
			pre+=cnt[i][j];
			ans=(ans+v*j)%mo;
		}
	}
	cout<<ans<<endl;
	return 0;
}