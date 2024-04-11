#include<bits/stdc++.h>
using namespace std;
const int N = 250 + 11;
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
#define sqr(a) ((a)*(a))
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    int n,m;
    cin>>n>>m;
    if (n==0&&m==0) cout<<"NO"<<endl; else
    if (abs(n-m)<=1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}