#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define y1 y12312312
#define int ll

using namespace std;
const int N=100001;
const int inf=1e9+3;
const int md=1e9+7;
const ll linf = 1e18;

int n,k,res,m,z;

vector<char> ans;
main()
{
    bs
    cin>>n>>k;
    if(k==0)
    {
        for(int i=0;i<n;++i)
        {
            cout<<"()";
        }
        return 0;
    }
    if(n*(n-1)/2<k)
    {
        cout<<"Impossible";
        return 0;
    }

    for(int v=1;v<=n+3;++v)
    {
        if(v*(v-1)/2>k)
        {
            res=v-1;
            break;
        }
    }

    m=k;
    z=-1;
    for(int j=1;j<=res;++j)
    {
        z++;
        m-=z;
        ans.pb('(');
    }
    for(int j=res;j>=1;j--)
    {
        ans.pb(')');
        while(m>=z&&z!=0)
        {
            ans.pb('(');
            ans.pb(')');
            m-=z;
        }
        z--;
    }
    if(m!=0)return 1;

    while(ans.size()<n*2)
    {
        ans.pb('(');
        ans.pb(')');
    }
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i];
    }


}