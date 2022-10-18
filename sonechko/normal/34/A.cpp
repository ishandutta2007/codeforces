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
const int N = 1e6 + 11;
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k1,k2;
    cin>>k1;
    k2=k1;
    int abs1=INT_MAX,ans1,ans2;
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        if (abs(l-k1)<abs1) {abs1=abs(l-k1); ans1=i-1; ans2=i;}
        k1=l;
    }
    if (abs(k2-k1)<abs1) {ans1=n; ans2=1;}
    cout<<ans1<<" "<<ans2<<endl;
}