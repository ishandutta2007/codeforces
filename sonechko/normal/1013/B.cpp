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

int use1[N],use2[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x;
    cin>>n>>x;
    int ans=-1;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (use1[a[i]]==1) ans=0;
        if (use2[a[i]]==1) {if (ans!=0) ans=1;}
        if (use1[a[i]&x]==1) {if (ans!=0) ans=1;}
        if (use2[a[i]&x]==1) {if (ans==-1) ans=2;}
        use1[a[i]]=1;
        use2[a[i]&x]=1;
    }
    cout<<ans<<endl;
}