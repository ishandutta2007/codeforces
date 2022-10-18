#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;
const int MAX = -2e18;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        ans1+=l;
    }
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        ans2+=l;
    }
    if (ans1>=ans2) cout<<"Yes"; else cout<<"No";
}