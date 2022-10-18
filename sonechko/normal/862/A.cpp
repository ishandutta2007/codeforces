#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
#define sqr(a) ((a)*(a))

const int N = 1e6 + 11;
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x;
    cin>>n>>x;
    for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            use[l]++;
        }
    int ans=0;
    for (int i=0; i<x; i++)
    {
        if (use[i]==0) ans++;
    }
    ans+=use[x];
    cout<<ans<<endl;
}