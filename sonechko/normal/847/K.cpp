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

int n,a,b,k,f,num,sm;

int c[301];
int p[301];
int ss[301],g[301];

string s,t;
string last;
map<pair<string,string>,int > used;

bool cmp(int a,int b)
{
    return ss[a]>ss[b];
}

main()
{
    bs
    cin>>n>>a>>b>>k>>f;
    for(int i=1;i<=n;++i)
    {
        cin>>s>>t;
        if(last==s)
        {
            c[i]=b;
        }else c[i]=a;
        last=t;

        if(s>t)swap(s,t);
        if(!used[mp(s,t)])
        {
            num++;
            p[i]=num;
            used[mp(s,t)]=num;
        }else p[i]=used[mp(s,t)];

        sm+=c[i];
        ss[p[i]]+=c[i];
    }

    for(int i=1;i<=num;++i)
    {
        g[i]=i;
    }

    sort(g+1,g+num+1,cmp);

    for(int i=1;i<=min(num,k);++i)
    {
        if(f<ss[g[i]])
        {
            sm-=ss[g[i]];
            sm+=f;
        }
    }
    cout<<sm;
}