#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e6 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        k+=l;
    }
    int m;
    cin>>m;
    int ans=N;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        if (r>=k) ans=min(ans,max(k,l));
    }
    if (ans==N) {cout<<-1<<endl;} else cout<<ans<<endl;
}