#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l,r,a;
    cin>>l>>r>>a;
    for (int i=300; i>=0; i--)
    if (max(0,i-l)+max(0,i-r)<=a) {cout<<i*2<<endl; return 0;}
}