#include<iostream>
using namespace std;
int n,m,q,x[109][109],y[109][109],p[109][109],f[109][109];
int g[109][109],h[109][109];
main()
{
int a,b,c,d;
cin>>n>>m>>q;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++){
x[i][j]=i; y[i][j]=j;
g[i][j]=i; h[i][j]=j;}
for (int i=0; i<q; i++)
{cin>>a;
if (a==1) {cin>>b;
b--;
int s=y[b][0],r=x[b][0];
for (int i=0; i<m-1; i++)
{y[b][i]=y[b][i+1];
x[b][i]=x[b][i+1];
}
y[b][m-1]=s;
x[b][m-1]=r;
}
if (a==2){cin>>b;
b--;
int s=x[0][b],r=y[0][b];
for (int i=0; i<n-1; i++)
{x[i][b]=x[i+1][b];
y[i][b]=y[i+1][b];
}
x[n-1][b]=s;
y[n-1][b]=r;
}
if (a==3) {
cin>>b>>c>>d;
b--; c--;
p[x[b][c]][y[b][c]]=d;
}/*
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
cout<<i<<" "<<j<<" - "<<x[i][j]<<" "<<y[i][j]<<endl;*/
}
for (int i=0; i<n; i++)
{for (int j=0; j<m; j++)
{cout<<p[i][j]<<" ";
}
cout<<endl;}

}