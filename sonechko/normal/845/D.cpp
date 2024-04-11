#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    int kol=0;
    int A=0;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int l;
            cin>>l;
            while (v.size()>0&&v[v.size()-1]<l)
            {
                ans++;
                v.pop_back();
            }
            A=l;
        }
        if (t==2)
        {
            ans+=kol;
            kol=0;
        }
        if (t==3)
        {
            int l;
            cin>>l;
            if (l>=A) v.pb(l); else ans++;
        }
        if (t==4) kol=0;
        if (t==5) v.clear();
        if (t==6) kol++;
    }
    cout<<ans<<endl;
}