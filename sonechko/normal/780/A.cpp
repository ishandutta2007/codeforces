#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k=0,ans=0;
    for (int i=1; i<=n*2; i++)
    {
        int l;
        cin>>l;
        if (use[l]==0) {use[l]=1; k++;} else k--;
        ans=max(ans,k);
    }
    cout<<ans<<endl;
}