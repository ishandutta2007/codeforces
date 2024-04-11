#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e6 + 11;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int res=0;
    int ans=0;
    for (int i=n; i>=1; i--)
        if (res==0) {ans++; res=a[i];} else
    {
        res--;
        res=max(res,a[i]);
    }
    cout<<ans<<endl;
}