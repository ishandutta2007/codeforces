#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
#define endl '\n'

using namespace std;

const int N=402;
const int inf=1e9+3;
const ll linf=1e18+3;
const int md=1e9+7;

int n,m,ans;
string s;
bool used['}'];
string a[1001];
bool g[1001];

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s;
    cin>>m;
    for(int j=0;j<n;++j)
    {
        if(s[j]!='*')
        {
            used[s[j]]=true;
        }
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a[i];
        g[i]=true;
        for(int j=0;j<n;++j)
        {
            if(used[a[i][j]]&&s[j]=='*')
            {
                g[i]=false;
                break;
            }
            if(s[j]=='*')continue;
            if(s[j]!=a[i][j])
            {
                g[i]=false;
                break;
            }
        }
    }
    for(char aa='a';aa<='z';++aa)
    {
        if(used[aa])continue;
        bool f=true;

        for(int i=1;i<=m;++i)
        {
            if(!g[i])continue;
            int gz=0;
            for(int j=0;j<n;++j)
            {
                if(a[i][j]==aa)
                {
                    gz++;
                }
            }
            if(gz==0)
            {
                f=false;
                break;
            }
        }

        ans+=f;
    }
    cout<<ans;
}