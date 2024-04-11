#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define mn 505
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[mn<<1][mn];
int tax[mn][mn];
bool del[mn<<1],use[mn];
void DEL(int x){
	for(int i=1;i<=n*2;++i){
		if(!del[i])
			for(int j=1;j<=n;++j){
				if(a[x][j]==a[i][j]){
					del[i]=1;
					for(int k=1;k<=n;++k)tax[k][a[i][k]]--;
					break;
				}
			}
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();
		memset(tax,0,sizeof(tax));
		memset(del,0,sizeof(del));
		for(int i=1;i<=n*2;++i)
			for(int j=1;j<=n;++j){
				a[i][j]=read();
				tax[j][a[i][j]]++;
			}
		int ans=1;
		vector<int>p(0);
		for(int i=1;i<=n;++i){
			pii use=mp(0,0);
			for(int j=1;j<=n&&!use.x;++j){
				for(int k=1;k<=n;++k){
					if(tax[j][k]==1){
						use=mp(j,k);
						break;
					}
				}
			}
	//		cerr<<i<<": "<<use.x<<" "<<use.y<<endl;
			if(use.x){
				for(int j=1;j<=n*2;++j){
					if(!del[j]&&a[j][use.x]==use.y){
						DEL(j);
						p.pb(j);
						break;
					}
				}
			}
			else{
				for(int j=1;j<=n*2;++j)
					if(!del[j]){
						DEL(j);p.pb(j);ans=ans*2%998244353;
						break;
					}
			}
		}
		cout<<ans<<'\n';
		sort(p.begin(),p.end());
		for(auto i:p)cout<<i<<" ";
		cout<<'\n';
	}
	return 0;
}