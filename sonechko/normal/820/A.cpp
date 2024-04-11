#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c,v0,v1,a,l;
    cin>>c>>v0>>v1>>a>>l;
    int k=0;
    for (int i=1; i<=10000000; i++)
    {
        if (k==0) k=v0; else k=k-l+min(v0,v1);
        v0=min(v0+a,v1);
        if (k>=c) {cout<<i<<endl; return 0;}
    }
}