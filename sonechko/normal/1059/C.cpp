#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

vector<int> res;

void up(int n, int t)
{
    if (n==1) {res.pb(t); return;}
    if (n==2) {res.pb(t); res.pb(t*2); return;}
    if (n==3) {res.pb(t); res.pb(t); res.pb(t*3); return;}
    for (int i=1; i<=(n+1)/2; i++)
        res.pb(t);
    up(n/2,t*2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    up(n,1);
    for (int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
}