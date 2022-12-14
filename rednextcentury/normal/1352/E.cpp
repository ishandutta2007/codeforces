#include<bits/stdc++.h>

using namespace std;

int a[8001];
bool h[8001];
int p[8001];
int main()
{
  ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
long n;
long q;
cin>>q;
long k=0;
p[0]=0;
for(long y=0;y<q;y++)
{
    cin>>n;
    k=0;
    for(long i=1;i<=n;i++)
    {
h[i]=0;
        cin>>a[i];

        p[i]=p[i-1]+a[i];
    }
    for(long u=0;u<=n;u++)
    for(long i=u+2;i<=n;i++)
    {
if (p[i]-p[u]<=n)
        h[p[i]-p[u]]=1;

    }
    for(long i=1;i<=n;i++)
    {
        if(h[a[i]]==1)
        {
            k++;

        }
    }
    cout<<k<<endl;
}
}