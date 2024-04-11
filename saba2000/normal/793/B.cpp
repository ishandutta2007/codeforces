#include<bits/stdc++.h>
using namespace std;
int a[1009][1009],x,y,p,q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int an=0;
int f[1009][1009][4][3];
void go(int i, int j, int d, int t)
{
if(t>2) return;
if(f[i][j][d][t]) return;

f[i][j][d][t]=1;
if(i==p && j==q) {an=1; return;}
for(int o=0; o<4; o++)
{if(a[i+dx[o]][j+dy[o]]){if(d==o) go(i+dx[o],j+dy[o],o,t);
else go(i+dx[o],j+dy[o],o,t+1);
}
}
}
int main()
{int n,m;
cin>>n>>m;
for(int i=1; i<=n; i++)
for (int j=1; j<=m; j++)
{char c;
cin>>c;
if(c=='S') {x=i; y=j; a[x][y]=1;}
if(c=='T') {p=i; q=j; a[p][q]=1;}
if(c=='.') a[i][j]=1;
}
go(x,y,0,0); 
go(x,y,1,0);
go(x,y,2,0); 
go(x,y,3,0);
if(an)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}