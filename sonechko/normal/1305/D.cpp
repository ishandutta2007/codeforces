#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1000 + 11;

vector<int> v[N];
int use[N];
int kk;

void dfs(int x, int pr)
{
    if (use[x]==1) return;
    use[x]=1;
    kk--;
    for (int j=0; j<v[x].size(); j++)
        if (v[x][j]!=pr) dfs(v[x][j],x);
}

int get(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    int p;
    cin>>p;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    kk=n;
    while (kk>1)
    {
        if (kk==2)
        {
            for (int i=1; i<=n; i++)
                if (use[i]==0)
                {
                    int c=0;
                    for (int j=0; j<v[i].size(); j++)
                        if (use[v[i][j]]==0) c=v[i][j];
                    int p=get(c,i);
                    cout<<"! "<<p<<endl;
                    return 0;
                }
        }

        int t1=0,t2=0,t3=0;
        for (int i=1; i<=n; i++)
            if (use[i]==0)
        {
            t1=i;
            t2=0;
            t3=0;
            for (int j=0; j<v[i].size(); j++)
                if (use[v[i][j]]==0)
            {
                t2=t3;
                t3=v[i][j];
            }
            if (t2!=0&&t3!=0) break;
        }
        int g=get(t2,t3);
        if (g==t1)
        {
            dfs(t2,t1);
            dfs(t3,t1);
        } else
        if (g==t2)
        {
            dfs(t1,t2);
        } else
        {
            dfs(t1,t3);
        }
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        cout<<"! "<<i<<"\n";
        return 0;
    }
}