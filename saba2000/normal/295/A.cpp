#include<bits/stdc++.h>
#define FF first.first
#define FS first.second
#define S second
#define int long long
using namespace std;
int a[100009];
int l[100009],r[100009],d[100009];
int n,m,k;
pair<int,int> Q[100009];
pair<pair<int,int>,int> Q1[100009];
main()
{cin>>n>>m>>k;
for(int i=1; i<=n; i++)
cin>>a[i];
for(int i=1; i<=m; i++)
cin>>l[i]>>r[i]>>d[i];
for(int i=0; i<k; i++)
cin>>Q[i].first>>Q[i].second;
sort(Q,Q+k);int cur=0,u=0;
priority_queue<int> sw;
for(int i=1; i<=m; i++)
{while(Q[u].first==i) {cur++;sw.push(-Q[u].second-1); u++;}
while(sw.size() && sw.top()==-i) {sw.pop(); cur--;}
d[i]*=cur;
}
for(int i=1; i<=m; i++)
{Q1[i].FF=l[i];
Q1[i].FS=r[i];
Q1[i].S=d[i];}
sort(Q1+1,Q1+m+1);
priority_queue<pair<int,int> > SW;
u=1; cur=0;
for(int i=1; i<=n; i++)
{while(Q1[u].FF==i) 
{cur+=Q1[u].S;SW.push(make_pair(-Q1[u].FS-1,Q1[u].S)); u++;}
while(SW.size() && SW.top().first==-i) 
{cur-=SW.top().S; SW.pop();}
a[i]+=cur;}
for(int i=1; i<=n; i++)
cout<<a[i]<<" ";
return 0;}