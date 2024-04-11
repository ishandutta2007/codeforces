#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 500 + 11;

map<int,bool> mt[N];
ll n;
ll ans=0;

void rec(int l, int x)
{
    if (mt[l][x]==1) return;
    mt[l][x]=1;
    if (l==n+1) {ans++; return;}
    rec(l+1,x+1);
    rec(l+1,x+5);
    rec(l+1,x+10);
    rec(l+1,x+50);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1) cout<<4;
    if (n==2) cout<<10;
    if (n==3) cout<<20;
    if (n==4) cout<<35;
    if (n==5) cout<<56;
    if (n==6) cout<<83;
    if (n==7) cout<<116;
    if (n==8) cout<<155;
    if (n==9) cout<<198;
    if (n==10) cout<<244;
    if (n==11) cout<<292;
    if (n==12) cout<<341;
    if (n>12) {cout<<341+(n-12)*49;}
    cout<<endl;
    return 0;
    rec(1,0);
    cout<<ans<<endl;
}