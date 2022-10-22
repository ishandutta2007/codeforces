#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define Mod 998244353
#define MN 1000005
int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
const int G=3,invG=(Mod+1)/3;
int n,m;
int a[MN],_a[MN],A[MN<<2],r[MN<<2];
void NTT(int *f,int n,int op){
	for(int i=0;i<n;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(int len=1;len<n;len<<=1){
		int p=len<<1,w=ksm(op?G:invG,(Mod-1)/p);
		for(int i=0;i<n;i+=p){
			LL buf=1;
			for(int l=i;l<i+len;++l){
				int TMP=buf*f[l+len]%Mod;
				f[l+len]=(f[l]-TMP+Mod)%Mod;
				f[l]=(f[l]+TMP)%Mod;
				buf=buf*w%Mod;
			}
		}
	}
	if(!op){
		int inv=ksm(n,Mod-2);
		for(int i=0;i<n;++i)f[i]=1ll*f[i]*inv%Mod;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		_a[a[i]]=A[a[i]]=1;
//		cerr<<"? "<<a[i]<<endl;
	}
	int len=1;
	while(len<=m*2)len<<=1;
//	cerr<<"len: "<<len<<endl;
	for(int i=0;i<len;++i)r[i]=(r[i>>1]>>1)|((i&1)?(len>>1):0);
	NTT(A,len,1);
	for(int i=0;i<len;++i)A[i]=1ll*A[i]*A[i]%Mod;
	NTT(A,len,0);
//	for(int i=0;i<=m;++i)cerr<<i<<": "<<A[i]<<endl;
	vector<int>ans;
	for(int i=0;i<=m;++i){
		if(A[i]&&!_a[i]){/*cerr<<"? "<<i<<endl;*/puts("NO");return 0;}
		if(!A[i]&&_a[i])ans.push_back(i);
	}
	puts("YES");
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();++i)
		printf("%d ",ans[i]);
	return 0;
}