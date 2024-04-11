#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int kol[N],x[N],ans[N];
vector<int> v1,v2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n+m; i++)
        cin>>x[i];
    for (int i=1; i<=n+m; i++)
    {
        int t;
        cin>>t;
        if (t==0) v1.pb(x[i]); else v2.pb(x[i]);
    }
    int pos=0;
    for (int j=0; j<v1.size(); j++)
    {
        while (pos+1<v2.size()&&v2[pos+1]<v1[j])
            pos++;
        int t;
        if (pos==v2.size()-1) t=pos; else
        {
            int l=v2[pos],r=v2[pos+1];
            if (abs(l-v1[j])<=abs(r-v1[j])) t=pos; else t=pos+1;
        }
        ans[t+1]++;
    }
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<" ";
        cout<<endl;
}