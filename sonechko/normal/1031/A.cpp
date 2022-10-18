#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod %MOD

const int MOD = 1e9 + 7;
const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for (int i=k; i>=1; i--)
    {
        ans+=n*m-(n-2)*(m-2);
        n-=4;
        m-=4;
    }
    cout<<ans<<endl;
}