#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,col[N],cnt[N],num;
int q[N],ql,qr;
vector<int> g[N];
set<int> tr;

void solve(int S)
{
	tr.erase(S); col[S]=++num;
	q[ql=0]=S;qr=1;
	while(ql<qr)
	{
		int u=q[ql++]; vector<int> tmp;
		for(int v:g[u])if(tr.count(v)) tmp.push_back(v);
		for(int v:tmp) tr.erase(v);
		for(int v:tr) col[q[qr++]=v]=col[u];
		tr.clear();
		for(int v:tmp) tr.insert(v);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++) tr.insert(i);
	for(int i=1;i<=n;i++) if(col[i]==0) solve(i);
	for(int i=1;i<=n;i++) cnt[col[i]-1]++;
	sort(cnt,cnt+num); cout<<num<<endl;
	for(int i=0;i<num;i++) cout<<cnt[i]<<" ";
	return 0;
}