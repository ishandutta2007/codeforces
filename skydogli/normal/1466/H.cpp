#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 45
#define Mod 1000000007
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,a[MN],F[MN],siz[MN];
int fac[MN],dfac[MN],inv[MN],C[MN][MN];
int c[MN][MN][MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
#define vc vector<int>
map<vc,int>f[MN];
vector<vc >st[MN];
void dfs(int s,vc v,int p){
	if(s==n||p==v.size())return;
	for(int i=p;i<v.size();++i){
		vc tmp=v;
		int ad=0;
		for(int j=1;j<=v[i];++j){
			tmp[i]--;
			ad+=i;
			st[s+ad].push_back(tmp);
			dfs(s+ad,tmp,i+1);
		}
	}
}
int tax[MN];
void DFS(int I,vector<pii>use_J,int K,vector<int>&tmp,int p){
	if(I+K==n||p==tmp.size())return;
	for(int i=p;i<tmp.size();++i){
		vc to=tmp;
		int ad=0,vv=0;
		vector<pii >temp=use_J;
		for(int j=tmp[i]-1;j>=0;--j){
			to[i]--;	
			ad+=i;
			int dt=tmp[i]-j;
//			cerr<<"dt: "<<dt<<endl;
//			int tv=prod;
			vector<pii >tv=use_J;
			//C[tmp[i]][dt];
			int ret=0;
			for(int k=1;k<=dt;++k)
				for(auto &T:tv){
					T.y=T.y*c[I][T.x][i]%Mod;
				}
			for(auto &T:tv){
				T.y=T.y*C[tmp[i]][dt]%Mod;
				ret=(ret+T.y);
			}
	//		cerr<<"ret: "<<ret<<" "<<C[tmp[i]][dt]<<endl;
			(f[K+ad][to]+=ret)%=Mod;
			DFS(I,tv,K+ad,to,i+1);
		}
		use_J=temp;
	}
}
signed main(){
//	freopen("1.in","r",stdin);
	cin>>n;
	fac[0]=fac[1]=dfac[0]=dfac[1]=inv[1]=1;
	for(int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=n;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;	
		}
	}
	for(int i=1;i<=n;++i)F[i]=i,siz[i]=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int fa=Find(a[i]),fi=Find(i);
		if(fa!=fi){
			F[fi]=fa;
			siz[fa]+=siz[fi];
		}
	}
	vector<int>v;v.resize(n+1);
	for(int i=0;i<=n;++i)v[i]=0;
	for(int i=1;i<=n;++i)
		if(Find(i)==i){
			v[siz[i]]++;
			tax[siz[i]]++;
		}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j)
			for(int k=1;i+k<=n;++k){
			if(i){				
				int tmp=0;
				for(int o=0;o<=i;++o){
					tmp=(tmp+C[i][o]*fac[o]%Mod*fac[n-o-1])%Mod;
				}
				tmp=ksm(tmp,k);
				int sub=0;
				for(int o=0;o<=i-j;++o){
					sub=(sub+C[i-j][o]*fac[o]%Mod*fac[n-o-1])%Mod;
				}
				sub=ksm(sub,k);
				c[i][j][k]=(tmp-sub+Mod)%Mod;
			}
			else{
				c[i][j][k]=ksm(fac[n-1],k);	
			}
			}
	st[0].push_back(v);
	f[0][v]=1;
	dfs(0,v,1);
	int ans=0;
	for(int i=0;i<=n;++i){
		for(auto v:st[i]){
			vector<pii > use_j(0);
			for(int j=0;j<=n;++j){
				if(!f[j].count(v))continue;
				use_j.push_back(mp(j,f[j][v]));
				//DFS(i,j,0,1,v,1,f[j][v]);	
				if(i==n)ans=(ans+f[j][v])%Mod;
			}
			DFS(i,use_j,0,v,1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}