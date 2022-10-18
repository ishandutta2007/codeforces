#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 2e6 + 11;

vector<int> v1[N],v2[N];
int num[N],kol[N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>num[i];
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v1[l].pb(r);
        v2[r].pb(l);
        if (r==num[n]) use[l]=1;
    }
    int kk=0,ans=0;
    for (int i=n-1; i>=1; i--)
        if (kol[num[i]]==kk&&use[num[i]]==1)
        {
            ans++;
        } else
        {
            for (int j=0; j<v2[num[i]].size(); j++)
                kol[v2[num[i]][j]]++;
            kk++;
        }
    cout<<ans<<endl;

}