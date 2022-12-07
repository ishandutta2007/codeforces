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
vector <vector <pint> > gr;
vector <pint> cl;
int ue[5100],yo[5100],pr[5100],ret[5100];
priority_queue <pint> q[5100];
bool sumi[5100];
vector <int> t;
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;
	t.pb(a);int i;//cout<<a<<endl;
	for(i=0;i<gr[a].size();i++){
		pint y=gr[a][i];
		if(!sumi[y.fi]){ue[y.fi]=a;yo[y.fi]=y.se;dfs(y.fi);}
	}
	return;
}
int main()
{
	int a,b,c,i,j,k,n;cin>>n;
	memset(sumi,false,sizeof(sumi));
	for(i=0;i<n+10;i++) gr.pb(cl);
	for(i=0;i<n;i++){
		scanf("%d",&pr[i]);
	}
	for(i=0;i<n-1;i++){
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		gr[a].pb(mp(b,c));gr[b].pb(mp(a,c));
	}
	dfs(0);//for(i=0;i<t.size();i++) cout<<t[i]<<endl;
	//for(i=0;i<n;i++) cout<<ue[i]<<' '<<yo[i]<<endl;
	for(i=0;i<n;i++) q[i].push(mp(-pr[i],i));
	for(i=0;i<5100;i++){
		while(!q[0].empty()){pint y=q[0].top();q[0].pop();ret[y.se]=i;}
		for(j=1;j<t.size();j++){
			int x=t[j];
			for(k=0;k<yo[x] && !q[x].empty();k++){
				pint y=q[x].top();q[x].pop();q[ue[x]].push(y);//cout<<i<<' '<<x<<' '<<y.se<<endl;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",ret[i]);if(i==n-1) cout<<endl;else printf(" ");
	}
	return 0;
}