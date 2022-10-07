#include<bits/stdc++.h>
using namespace std;				
long long n,b,t[200009],d[200009],ans[200009];
priority_queue <pair<long long,long long> > q;
queue<long long> p;
main()
{
cin>>n>>b;
for (long long i=1; i<=n; i++)
{cin>>t[i]>>d[i];
q.push(make_pair(-t[i],-i));
}long long c=0; long long l=0;
while(q.size()>0)
{long long x=-q.top().first,y=q.top().second; 
//out<<x<<" "<<y<<" "<<c<<endl;
q.pop();
if(y<0) {y=-y; if (c==b) ans[y]=-1; else
if (l==0) {q.push(make_pair(-(x+d[y]),y)); l=1;}
else {p.push(y); c++;}}
else
{
ans[y]=x;
l=0;
if (c==0) continue;
q.push(make_pair(-(x+d[p.front()]),p.front()));
l=1;
p.pop();
c--;}
}
for (long long i=1; i<=n; i++)
cout<<ans[i]<<" ";
  
}/*5 1
2 9
4 8
10 9
15 2
19 1

*/