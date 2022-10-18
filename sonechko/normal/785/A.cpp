#include<bits/stdc++.h>
using namespace std;
const int N = 500000 + 11;
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
    sync;
    int n,k=0;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        if (s[0]=='T') k+=4; else
        if (s[0]=='C') k+=6; else
        if (s[0]=='O') k+=8; else
        if (s[0]=='D') k+=12; else k+=20;
    }
    cout<<k<<endl;
}