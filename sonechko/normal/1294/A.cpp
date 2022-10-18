#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        int mx=max(a,max(b,c));
        n-=mx-a;
        n-=mx-b;
        n-=mx-c;
        if (n<0||n%3!=0) cout<<"NO\n"; else cout<<"YES\n";
    }
}