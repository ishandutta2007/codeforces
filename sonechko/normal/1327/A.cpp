#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void up()
{
    int n,k;
    cin>>n>>k;
    if (n%2!=k%2) {cout<<"NO\n"; return;}
    for (int j=1; j<=k; j++)
    {
        n-=j*2-1;
        if (n<0) {cout<<"NO\n"; return;}
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}