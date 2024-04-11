#include <iostream>
#include <cmath>
using namespace std;
pair<double,double> a[1000];
int l[1000];
double n,x,y,k,b,ans;
void kb(int i)
{
if (a[i].first!=x) {k=(a[i].second-y)/(a[i].first-x); b=y-k*x;}
else {b=10001;}
}

int main()
{cin>>n>>x>>y;
for (int i=0; i<n; i++ )
cin>>a[i].first>>a[i].second;
for (int i=0; i<n; i++)
{if (l[i]==1) continue;
kb(i); int ch=1;
for (int j=i; j<n; j++)
{if (b==10001) {if (fabs(a[j].first-x)<0.000001) l[j]=1;} else
if(fabs(a[j].second-k*a[j].first-b)<0.000001) l[j]=1;
if (l[j]==0) ch=0;
}
ans++;
if (ch==1) break;

}
cout<<ans<<endl;
}