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
    string a,b,c;
    cin>>a>>b>>c;
    for (int i=0; i<c.size(); i++)
    {
        if (a[i]==b[i]&&a[i]==c[i]) {} else
        if (a[i]==c[i]) {} else
        if (b[i]==c[i]) {} else {cout<<"NO\n"; return;}
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