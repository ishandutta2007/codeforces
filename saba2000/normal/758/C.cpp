#include<iostream>
#include<cmath>
using namespace std;
long long a[109][109],n,m,k,x,y,mi,ma,t;
main()
{cin>>n>>m>>k>>x>>y;
if (n==1) t=m;
else t=(2+(n-2)*2)*m;
mi=k; ma=0;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
if (i==0 || i==n-1) a[i][j]+=k/t;
else a[i][j]+=(k/t)*2;
k%=t;

for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
{if (k>0) a[i][j]++;
k--;}
for (int i=n-2; i>=0; i--)
for (int j=0; j<m; j++)
{if (k>0) a[i][j]++;
k--;
}
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
{mi=min(mi,a[i][j]);
ma=max(ma,a[i][j]);
}
cout<<ma<<" "<<mi<<" "<<a[x-1][y-1]<<endl;

}