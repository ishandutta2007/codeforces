#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back

const int N = 2e5 + 11;

int dp[N];

void up()
{
    int n;
    cin>>n;
    string s="";
    while (n>3)
    {
        s+="1";
        n-=2;
    }
    if (n==2) s+="1"; else
    if (n==3) s+="7";
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}