#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define ld long double
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD



const int N = 2e5 + 11;



int main() {
    int n,k,t;
    cin>>n>>k>>t;
    if (t<=k) cout<<t<<endl; else
    if (t<=n) cout<<k<<endl; else
        cout<<n+k-t<<endl;
}