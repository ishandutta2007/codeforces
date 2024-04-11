#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int d=1; d<=n; d++)
        if (n%d==0) reverse(s.begin(),s.begin()+d);
    cout<<s<<endl;
}


/// 999 B