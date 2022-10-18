#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=1000; i++)
    {
        int l=i*n+1;
        int tr=0;
        for (int j=2; j<=(int)sqrt(l); j++)
        if (l%j==0) {tr=1; break;}
        if (tr==1) {cout<<i<<endl; return 0;}
    }
}