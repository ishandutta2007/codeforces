#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v1,v2;
    int k1=0;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        int mini=2e9,maxi=-2e9,t=0;
        for (int j=1; j<=k; j++)
        {
            int l;
            cin>>l;
            if (l>mini) t=1;
            mini=min(mini,l);
            maxi=max(maxi,l);
        }
        if (t==1) k1++; else
        {
            v1.pb(mini);
            v2.pb(maxi);
        }
    }
    ll ans=0;
    ans+=k1*1ll*n;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int pos=0;
    for (int j=0; j<v1.size(); j++)
    {
        while (pos<v2.size()&&v2[pos]<=v1[j])
            pos++;
        ans+=1ll*(v2.size()-pos)+1ll*k1;
    }
    cout<<ans;
}