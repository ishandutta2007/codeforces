#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 998244353;

vector<int> v[N];
int a[N];
map<int,int> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k1=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (mt[a[i]]==0) {k1++; mt[a[i]]=k1;}
        a[i]=mt[a[i]];
        v[a[i]].pb(i);
    }
    int dp=1;
    int pos=v[a[1]].back();
    for (int j=2; j<=n; j++)
    {
        if (pos<j) dp=(dp*2)%MOD;
        pos=max(pos,v[a[j]].back());
    }
    cout<<dp<<endl;
}