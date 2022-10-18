#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 2e5 + 11;

ll a[N];

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll sum=0,ss=0,kol=0;
    for (int i=1; i<=k; i++)
    ss+=a[i];
    for (int i=1; i<=n-k+1; i++)
    {
        sum+=ss;
        kol++;
        ss-=a[i];
        ss+=a[i+k];
    }
    cout.precision(10);
    cout<<fixed;
    cout<<(ld)sum/(ld)kol<<endl;
}