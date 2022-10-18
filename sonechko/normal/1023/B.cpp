#include<bits/stdc++.h>
using namespace std;

#define y1 ojf
#define ld long double
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int N = 1e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    if (n>=k)
    {
        if (k%2==0) cout<<k/2-1; else cout<<k/2;
        return 0;
    }
    ll x=0;
    if (k%2==0) x=k/2-1; else x=k/2;
    ll l=k-x,r=k-1;
    if (n<l) cout<<0<<endl; else cout<<n-l+1<<endl;
}
/**
7
1 6
2 5
3 4

8
1 7
2 6
3 5
**/