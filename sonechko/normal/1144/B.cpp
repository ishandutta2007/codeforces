#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 3000 + 11;
const int MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x%2==0) v1.pb(x); else v2.pb(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if (v2.size()<v1.size()) swap(v1,v2);
    int x=v1.size();
    int ans=0;
    for (int i=0; i<(int)v2.size()-(x+1); i++)
        ans+=v2[i];
    for (int i=0; i<(int)v1.size()-(x); i++)
        ans+=v1[i];
    cout<<ans;
}