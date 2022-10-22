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
#define MN 2005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int d[MN];
bool vis[MN];
vc e[MN];
void ask(int x){
	cout<<"? "<<x<<endl;
	for(int i=1;i<=n;++i)cin>>d[i];

}
bool fk[MN];
signed main(){
    cin>>n;
	vc p(0),q(0);
	ask(1);
	for(int i=2;i<=n;++i)
		if(d[i]%2==0)p.pb(i);
		else q.pb(i);
	if(p.size()<q.size()){
		for(int i=2;i<=n;++i)if(d[i]==1)e[1].pb(i);
		for(auto i:p){
			ask(i);
			for(int j=1;j<=n;++j)if(d[j]==1)e[i].pb(j);
		}
	}
	else{
		for(auto i:q){
			ask(i);
			for(int j=1;j<=n;++j)if(d[j]==1)e[i].pb(j);
		}
	}
	cout<<"!"<<endl;
	for(int i=1;i<=n;++i)
		for(auto j:e[i])cout<<i<<" "<<j<<endl;
	return 0;
}