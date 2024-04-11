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
vector <vector <int> > gr;
vector <int> cl;
bool sumi[110];
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;
	for(int i=0;i<gr[a].size();i++) dfs(gr[a][i]);
	return;
}
int main()
{
	int i,n,m,a,b;memset(sumi,false,sizeof(sumi));
	cin>>n>>m;
	if(n<3){cout<<"NO"<<endl;return 0;}
	if(n!=m){
		cout<<"NO"<<endl;return 0;
	}
	for(i=0;i<n+10;i++) gr.pb(cl);
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);gr[a].pb(b);gr[b].pb(a);
	}
	dfs(1);
	for(i=1;i<=n;i++){
		if(!sumi[i]){
			cout<<"NO"<<endl;return 0;
		}
	}
	cout<<"FHTAGN!"<<endl;return 0;
}