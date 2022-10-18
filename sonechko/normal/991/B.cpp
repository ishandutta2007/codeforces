#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

int a[N];

bool good(int n)
{
    int sum=0;
    for (int i=1; i<=n; i++)
        sum+=a[i];
    long double x=(long double)sum/(long double)n;
    ll p=round(x);
    if (p==5) return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if (good(n)) {cout<<0<<endl; return 0;}
    for (int i=1; i<=n; i++)
    {
        a[i]=5;
        if (good(n)) {cout<<i<<endl; return 0;}
    }

}