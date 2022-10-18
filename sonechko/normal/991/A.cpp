#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCDD optimize("unroll-loops")


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD



int main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if (a<c||b<c) cout<<-1<<endl; else
    {
        int x=a+b-c;
        if (x>=n) cout<<-1<<endl; else cout<<n-x<<endl;
    }
}