#include <iostream>
using namespace std;
int p[500][500];
int ma(int i,int m)
{int l=0; if (p[i][0]==1) l=1;
int max=0; for (int j=1; j<m; j++)
if (p[i][j-1]==1 && p[i][j]==1) l++; else {if(max<l) max=l; l=0; if (p[i][j]==1) l++;}  
if (l>max) max=l;
return max;
}
int main ()
{ int n,m,q,l,max=0,k[501]={0},a,b,z=0,max2=0;
cin>>n>>m>>q;
for (int i=0; i<n; i++)
{for (int j=0; j<m; j++)
cin>>p[i][j];
k[ma(i,m)]++;
}
for (int i=0; i<q; i++)
{cin>>a>>b; a--; b--; int s=ma(a,m);
if (p[a][b]==1) p[a][b]=0; else p[a][b]=1;
int t=ma(a,m);

k[s]--; k[t]++; int j;
for (j=500; j>=0; j--)
if (k[j]>0) break;
cout<<j<<endl;
}
return 0;
}