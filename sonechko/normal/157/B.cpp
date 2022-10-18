#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e2 + 11;
///-----------------------------------------------------------
int a[N],ans;
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
        if ((n-i)%2==0) ans+=a[i]*a[i]; else ans-=a[i]*a[i];
    ld res=ans*M_PI;
    cout.precision(10);
    cout<<fixed;
    cout<<res<<endl;
}