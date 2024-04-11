#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define int long long
#define Mod 998244353
int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
const int G=3,invG=ksm(3,Mod-2);
int r[MN<<2];
void ntt(LL *f,int n,bool op){
	for(int i=0;i<n;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(int p=2;p<=n;p<<=1){
		int len=(p>>1);
		LL tmp=ksm(op?G:invG,(Mod-1)/p);
		for(int k=0;k<n;k+=p){
			LL buf=1;
			for(int l=k;l<k+len;++l){
				LL TMP=f[l+len]*buf%Mod;
				f[l+len]=(f[l]-TMP+Mod)%Mod;
				f[l]=(f[l]+TMP)%Mod;
				buf=buf*tmp%Mod;
			}
		}
	}
	if(!op){
		int inv=ksm(n,Mod-2);
		for(int i=0;i<n;++i)f[i]=f[i]*inv%Mod;
	}
}
LL a[MN<<2],b[MN<<2],f[MN<<2];
#define vc vector<int>
vc MUL(vc f,vc g){
	int n=f.size(),m=g.size();
	int N=1;
	while(N<n+m)N<<=1;
	for(int i=0;i<N;++i)r[i]=(r[i>>1]>>1)|((i&1)?(N>>1):0);
	for(int i=0;i<n;++i)a[i]=f[i];
	for(int i=0;i<m;++i)b[i]=g[i];
	for(int i=n;i<N;++i)a[i]=0;
	for(int i=m;i<N;++i)b[i]=0;
	ntt(a,N,1);
	ntt(b,N,1);
	for(int i=0;i<N;++i)
		a[i]=a[i]*b[i]%Mod;
	ntt(a,N,0);
	vc res;res.clear();res.resize(n+m-1);
	for(int i=0;i<n+m-1;++i)res[i]=a[i];
	return res;
}
vector<int> work(int l,int r){
	if(l==r){vc tmp;tmp.clear();tmp.push_back(l);tmp.push_back(1);return tmp;}
	int mid=(l+r)>>1;
	vc a1=work(l,mid),a2=work(mid+1,r);
	return MUL(a1,a2);
}
signed main(){
	int n,a,b;
	scanf("%lld%lld%lld",&n,&a,&b);n--;
	if(!n){puts((a==b&&a==1)?"1":"0");return 0;}
	if(!a||!b){puts("0");return 0;}
	if(a+b-2>n){puts("0");return 0;}
	int cnt=0;
	if(a+b-2<0){puts("0");return 0;}
	vector<int>ans=work(0,n-1);
	LL res=ans[a+b-2];
	for(int i=1;i<a;++i)res=res*(a+b-2-i+1)%Mod*ksm(i,Mod-2)%Mod;
	printf("%lld",res);
	return 0;
}