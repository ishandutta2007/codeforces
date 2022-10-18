#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int j=1; j<=t; j++)
    {
        ll s,a,b,c;
        cin>>s>>a>>b>>c;
        ll p=s/c;
        cout<<p+(p/a)*b<<endl;
    }
}