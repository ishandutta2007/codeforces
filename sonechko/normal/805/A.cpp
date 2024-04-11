#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MOD = 1e9 + 7;
#define mod %MOD
const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (n==m) {cout<<n<<endl; return 0;}
    int k1=m/3-(n-1)/3;
    int k2=m/2-(n-1)/2;
    if (k1>k2) cout<<3<<endl; else cout<<2<<endl;
}