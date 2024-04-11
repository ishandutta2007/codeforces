#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,s,t;
        cin>>n>>s>>t;
        int c=s+t-n;
        s-=c;
        t-=c;
        cout<<max(s,t)+1<<"\n";
    }
}