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
#define MN 505
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m,k;
int f[MN],pre[MN];
queue<int>Q;
vector<int>p;
void getj(int x){
	if(x==0)return;
	int j=pre[x];
	getj(x-(j-(k-j)));
	p.pb(j);
}
bool vis[MN];
signed main(){
	n=read();k=read();
	memset(f,0x3f,sizeof(f));
	Q.push(0);f[0]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int j=1;j<=k;++j){
			if(x+j>n||x<(k-j))continue;
			int to=x+j-(k-j);
			if(f[to]>f[x]+1){
				f[to]=f[x]+1;
				pre[to]=j;
				Q.push(to);
			}
		}
	}
	if(f[n]>1e9)puts("-1");
	else{
		getj(n);
		int ans=0;
		cerr<<"siz: "<<p.size()<<endl;
		for(auto j:p){
			vc A(0),B(0);
			for(int i=1;i<=n;++i)
				if(!vis[i])A.pb(i);
				else B.pb(i);
			cout<<"? ";
			for(int i=0;i<j;++i){
				cout<<A[i]<<" ";vis[A[i]]=1;
			}
			for(int i=0;i<k-j;++i){
				cout<<B[i]<<" ";vis[B[i]]=0;
			}
			cout<<endl;
			int a=0;cin>>a;ans^=a;
		}
		cout<<"! "<<ans<<endl;
	}
	return 0;
}