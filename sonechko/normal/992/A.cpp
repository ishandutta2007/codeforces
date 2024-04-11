#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    use[100000]=1;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (use[l+100000]==0) {ans++; use[l+100000]=1;}
    }
    cout<<ans<<endl;
}