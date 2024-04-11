#include <bits/stdc++.h>
using namespace std;
long long LINF=(1LL<<55);
int INF=1e9;


int a[1000000];
int main()
{
    int n,d;
    cin>>n>>d;
    int ret=2;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (i>0 && a[i]-a[i-1]>=2*d)
            ret+=2-(a[i]-a[i-1]==2*d);
    }
    cout<<ret<<endl;
}