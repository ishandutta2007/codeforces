#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ans=min(k-1,n-k)*2+max(k-1,n-k);
    ans+=n+1;
    ans+=n;
    cout<<ans<<endl;
}