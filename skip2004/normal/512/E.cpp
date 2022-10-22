#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
typedef std::pair<int, int> pr;
const int N=1005;
int n,t;
std::vector<pr>v0,v1;
int a[N],b[N];
int e[N][N];
inline void flip(int x, int y, std::vector<pr>&vec) {
	int a=0,b=0;
	rep(i,1,n)if(e[i][x]&&e[i][y]) (a?b:a)=i;
	if(t) vec.push_back(pr(a,b));
	else vec.push_back(pr(x,y));
	e[a][b]=e[b][a]=1;
	e[x][y]=e[y][x]=0;
}
inline void run(std::vector<pr>&vec){
	for(int i=1;i<n-2;++i)cin>>a[i]>>b[i];
	memset(e,0,sizeof e);
	rep(i,1,n)e[i][i%n+1]=e[i%n+1][i]=1;
	rep(i,1,n-3)e[a[i]][b[i]]=e[b[i]][a[i]]=1;
	rep(i,2,n)for(int j=n;j>i+1;--j)if(e[1][i]&&e[1][j]&&e[i][j]){
		flip(i,j,vec);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	run(v0), t = 1, run(v1);
	reverse(v1.begin(), v1.end());
	cout<<v0.size()+v1.size()<<'\n';
	for(auto x:v0)cout<<x.first<<' '<<x.second<<'\n';
	for(auto x:v1)cout<<x.first<<' '<<x.second<<'\n';
}