#include<bits/stdc++.h>
using namespace std;
#define MN 55
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
#define Mod 998244353
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		x>>=1;
		w=w*w%Mod;
	}
	return ans;
}
int n,a[MN],b[MN],v[MN<<1],N;
LL f[MN],g[MN],inv[MN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);b[i]++;
		v[++N]=a[i];v[++N]=b[i];
	}
	sort(v+1,v+1+N);
	N=unique(v+1,v+1+N)-v-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(v+1,v+1+N,a[i])-v,b[i]=lower_bound(v+1,v+1+N,b[i])-v;
		inv[i]=ksm(i,Mod-2);
//		cerr<<"inv "<<i<<": "<<inv[i]<<endl;
	}
	f[0]=1;
	for(int j=N-1;j;--j){
		int len=v[j+1]-v[j]-1;
		g[0]=1;
		for(int i=1;i<=n;++i)g[i]=g[i-1]*(len+i)%Mod*inv[i]%Mod;
		for(int i=n;i;--i)
			if(a[i]<=j&&j<b[i])	
				for(int c=1,k=i-1;k>=0;--k,c++){
			//		cerr<<"???"<<j<<" "<<i<<" "<<k<<endl;
					f[i]=(f[i]+g[c]*f[k])%Mod;
					if(a[k]>j||b[k]<=j)break;
				}
	}
//	cerr<<"? "<<f[n]<<endl;
	LL tmp=1;
	for(int i=1;i<=n;++i)tmp=tmp*(v[b[i]]-v[a[i]])%Mod;
	printf("%lld\n",f[n]*ksm(tmp,Mod-2)%Mod);
	return 0;
}