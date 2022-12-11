#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int N = 100005;
const int mo = 1e9+7;

int k,n,m;
int key[N*4],u;
struct section{
	int l,r;
	friend bool operator < (section a,section b){return a.l!=b.l?a.l<b.l:a.r<b.r;}
}s1[N],s2[N];

void trs(section *s,int &n){
	if (!n)return;
	sort(s+1,s+1+n);
	int n_=1;
	fo(i,2,n){
		if (s[i].l==s[i-1].l)continue;
		while(n_&&s[n_].r>=s[i].r)n_--;
		s[++n_]=s[i];
	}
	n=n_;
}

int getw(int x){
	int ret=0,l=1,r=u;
	while(l<=r){
		int mid=(l+r)/2;
		if (key[mid]>=x)ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}

int L1[N*4],L2[N*4],R1[N*4],R2[N*4];
LL f[N*4],f1[N*4],f2[N*4];

LL quickmi(LL x,LL tim){
	LL ans=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ans=ans*x%mo;
	return ans;
}

int main(){
	k=get();n=get();m=get();
	fo(i,1,n){
		int l=get(),r=get();
		key[++u]=l-1;
		key[++u]=r;
		s1[i].l=l;s1[i].r=r;
	}
	fo(i,1,m){
		int l=get(),r=get();
		key[++u]=l-1;
		key[++u]=r;
		s2[i].l=l,s2[i].r=r;
	}
	sort(key+1,key+1+u);
	key[++u]=k;
	int u1=1;
	fo(i,2,u)if (key[i]>key[i-1])key[++u1]=key[i];
	u=u1;
	trs(s1,n);
	trs(s2,m);
	fo(i,1,n){
		int L=getw(s1[i].l),R=getw(s1[i].r);
		L1[R]=L;R1[L]=R;
	}
	fo(i,1,m){
		int L=getw(s2[i].l),R=getw(s2[i].r);
		L2[R]=L;R2[L]=R;
	}
	f[0]=1;
	fo(i,1,u){
		f2[i]=f2[i-1],f1[i]=f1[i-1];
		if (L1[i]){
			LL tmp=(f1[i]+mo-f1[L1[i]-1]+f[L1[i]-1])%mo;
			f[i]=(f[i]+mo-tmp)%mo;
			f1[i]=(f1[i]+mo-tmp)%mo;
		}
		if (L2[i]){
			LL tmp=(f2[i]+mo-f2[L2[i]-1]+f[L2[i]-1])%mo;
			f[i]=(f[i]+mo-tmp)%mo;
			f2[i]=(f2[i]+mo-tmp)%mo;
		}
		f[i]=(f[i]+f[i-1]*quickmi(2,key[i]-key[i-1])%mo)%mo;
	}
	printf("%I64d\n",f[u]);
	return 0;
}