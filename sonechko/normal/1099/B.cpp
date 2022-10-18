#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=2e9;
    for (int d=1; d<=(int)sqrt(n); d++)
    {
        int d1=d;
        int d2=n/d+(n%d!=0);
        ans=min(ans,d1+d2);
    }
    cout<<ans<<endl;
}
/**
n*m
n+m-min
n*m>=k
**/