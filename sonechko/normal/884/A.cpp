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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,t;
    cin>>n>>t;
    int res=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        res-=l;
        res+=86400;
        if (res>=t) {cout<<i<<endl; return 0;}
    }
}