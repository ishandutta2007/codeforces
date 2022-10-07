#include<iostream>
#include<queue>
using namespace std;
queue<int>q;
int n,m,a[500][500],f[500],t;
main()
{cin>>n>>m;
for (int i=0; i<m; i++)
{int x,y;
cin>>x>>y;
a[x][y]=1; a[y][x]=1;}
if (a[1][n]==0) t=1; else t=0;
f[1]=1;
q.push(1);
while (q.size()>0)
{int x=q.front(); q.pop();
for (int i=1; i<=n; i++)
if (a[x][i]==t && f[i]==0) {q.push(i); f[i]=f[x]+1;}
}
cout<<f[n]-1<<endl;
}