#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int gc[110][110],lc[110][110];
//lint lcp[110],gcp[110];
vector <int> now,cl;
bool sumi[110];
int zan[110];int n;
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;now.pb(a);int i;
	for(i=1;i<=n;i++){
		if(gc[a][i]>0) dfs(i);
	}
	return;
}
bool dfs2(int a,int b){
//	if(zan[a]>0 && zan[a]!=b) return false;
	if(zan[a]>0){
		if(zan[a]!=b) return false;return true;
	}
	zan[a]=b;int i;
	for(i=1;i<=n;i++){
		if(gc[a][i]>0){
			if(b%gc[a][i]>0 || lc[a][i]%b>0) return false;
			int t=lc[a][i]/b*gc[a][i];if(gcd(b,t)>gc[a][i]) return false;
			if(!dfs2(i,t)) return false;
		}
	}
	return true;
}
int main()
{
	int i,j,k,m,a,b,c,d;
	for(i=0;i<110;i++) zan[i]=-1;
	for(i=0;i<110;i++) for(j=0;j<110;j++) gc[i][j]=lc[i][j]=-1;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		gc[a][b]=gc[b][a]=c;lc[a][b]=lc[b][a]=d;
	}
	for(i=1;i<=n;i++){
		if(sumi[i]) continue;
		now=cl;dfs(i);int f=0;
		for(j=1;j<=1000000 && f<1;j++){
			if(dfs2(i,j)) f=1;
			else{
				for(k=0;k<now.size();k++) zan[now[k]]=-1;
			}
		}
		if(f<1){cout<<"NO"<<endl;return 0;}
	}
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++){
		cout<<zan[i];
		if(i<n) cout<<' ';else cout<<endl;
	}
	return 0;
}