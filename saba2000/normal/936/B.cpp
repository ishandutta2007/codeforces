#include<bits/stdc++.h>
#define psi  pair < string ,int>
#define fi first
#define se second
#define pb push_back
#define sz size
using namespace std;
int f[200009][2];
int w[200009][2];
int F[200009];
vector<int> v[200009];
int fl=0;
void dfs(int x,int d)
{
    f[x][d]= 1;
    for (int i = 0; i < v[x].size(); i++)
    {
        if(f[v[x][i]][1-d]==0)
        {
            w[v[x][i]][1-d]=x;
            dfs(v[x][i],1-d);
        }
    }
}
void dfs2(int x)
{
    F[x]=1;
    for (int i = 0 ;i<v[x].size(); i++)
    {
        if(F[v[x][i]]==1) fl=1;
        if(F[v[x][i]]==0) dfs2(v[x][i]);
    }
    F[x]=2;
}
main()
{
    int n,m,s;
    cin >> n >> m;
    for (int i = 1 ;i <= n; i++)
    {
        int d;
        cin >>d;
        for (int j=0; j<d; j++)
        {

            int a;
            cin>>a;

        v[i].push_back(a);
        }
    }
    cin >>s;
    dfs(s,0);
    dfs2(s);
    for (int i =1; i<=n; i++)
    {
        if(v[i].size()) continue;

        if(f[i][1]==1)
        {
            cout<<"Win"<<endl;
            vector<int> m;
            m.push_back(i);
            int d =1,x = i;
            while(x!=s || d!=0)
            {

                x=w[x][d];
                d=1-d;
                m.push_back(x);
            }
            reverse(m.begin(),m.end());
            for(int i=0; i<m.size(); i++)
                cout<<m[i]<<" ";
            cout<<endl;
            return 0;
        }
    }
    if(fl) cout<<"Draw"<<endl;
    else cout<<"Lose"<<endl;
}