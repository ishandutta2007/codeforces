#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;
int use[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int d1=9,d2=9;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        use[l]++;
        d1=min(d1,l);
    }
    int res=99;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        if (use[l]==1) res=min(res,l);
        d2=min(d2,l);
    }
    res=min(res,min(d1,d2)*10+max(d1,d2));
    cout<<res<<endl;
}