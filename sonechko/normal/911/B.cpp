#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define mp make_pair
const ll N = 100000 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int res=0;
    for (int p1=1; p1<n; p1++)
    {
        int ps1=a/p1;
        int ps2=b/(n-p1);
        res=max(res,min(ps1,ps2));
    }
    cout<<res<<endl;
}