#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3005;
const int mo = 998244353;
const LL INF = 4ll*mo*mo;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
		if (tim&1)ret=ret*x%mo;
	return ret;
}

int n,m;
int a[N];
LL f[N][N],g[N][N];
LL sum[N][N];
int cnt[N];
LL mi[N],iv[N];
LL ny[N],ans[N];
int mul[N];

int main(){
//	freopen("data.in","r",stdin);
	n=get();m=get();
	fo(i,1,n)a[i]=get();
	mi[0]=1;
	fo(i,1,n)mi[i]=mi[i-1]*2%mo;
	fo(i,1,n)ny[i]=quickmi(mi[i]-1,mo-2);
	iv[0]=1;
	iv[1]=(mo+1)/2;
	fo(i,2,n)iv[i]=iv[i-1]*iv[1]%mo;
	int L=n/m;
	fo(i,1,n){
		fo(x,1,m)cnt[x]=0;
		int res=m;
		LL val=0;
		fo(j,i,n){
			int pr=res;
			cnt[a[j]]++;
			if (cnt[a[j]]==1)res--;
			if (!res){
				if (pr){
					val=1;
					fo(x,1,m)val=val*(mi[cnt[x]]-1)%mo;
				}
				else
					val=val*ny[cnt[a[j]]-1]%mo*(mi[cnt[a[j]]]-1)%mo;
			//	g[i][j]=val*ny[cnt[a[j]]]%mo;
				g[i][j]=val;
			}
		}
		fd(j,n,i)g[i][j]=dec(g[i][j],g[i][j-1]*2%mo);
	}
	if ((m>20)||(1<<m)>n){
		fo(i,1,n)f[i][1]=g[1][i];
		int L=n/m;
		fo(i,1,n)
			fd(j,i/m,2){
				fo(k,(j-1)*m,i-1){
					f[i][j]=(f[i][j]+f[k][j-1]*g[k+1][i]);
					if (f[i][j]>INF)f[i][j]-=INF;
				}
				f[i][j]=f[i][j]%mo;
			}
	}
	else{
		fo(i,1,n)f[i][1]=g[1][i];
		fo(i,1,n){
			fo(j,2,L)f[i][j]=sum[j-1][((1<<m)-1)^(1<<(a[i]-1))];
			fo(j,1,L){
				int r=(1<<(a[i])-1);
				for(int x=r;x<(1<<m);x=(x+1)|r)
					sum[j][x]=((sum[j][x]<<1)+sum[j][x^r])%mo;
				sum[j][0]=(sum[j][0]+f[i][j])%mo;
			}
		}
	}
	fo(i,1,n)
		fo(j,1,L){
			f[i][j]=(f[i][j]%mo+mo)%mo;
			ans[j]=(ans[j]+f[i][j]*mi[n-i])%mo;
		}
	fo(i,1,n)ans[i]=dec(ans[i],ans[i+1]);
	ans[0]=dec(mi[n],1);
	fo(i,1,L)ans[0]=dec(ans[0],ans[i]);
	fo(i,0,n)printf("%I64d%c",ans[i],i==n?'\n':' ');
	return 0;
}