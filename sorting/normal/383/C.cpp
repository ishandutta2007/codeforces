#include<iostream>
#include<vector>

#define endl "\n"

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

using namespace std;

const long long N = 200010;

long long n,m;
long long a[N];

vector<long long> v[N];
vector<long long> discover;
long long Begin[N],End[N];
long long t=1;

long long fen[N];
long long lvl[N];

void update(long long pos,long long val)
{
    for(;pos<=n;pos+=pos&(-pos))
        fen[pos]+=val;
}

long long query(long long pos)
{
    long long res=0;

    for(;pos>=1;pos-=pos&(-pos))
        res+=fen[pos];

    return res;
}

void dfs(long long u,long long p,long long level)
{
    discover.push_back(u);
    Begin[u]=t;
    lvl[u]=level;
    t++;

    for(long long i=0;i<v[u].size();i++)
    {
        if(p==v[u][i])
            continue;

        dfs(v[u][i],u,level+1);
    }

    End[u]=t;
}

int main ()
{
    long long i,x,y,val;

    cin>>n>>m;

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    discover.push_back(0);
    dfs(1,-1,1);

    for(i=0;i<m;i++)
    {
        cin>>x;

        if(x==1)
        {
            cin>>x>>val;

            //cout<<"--- "<<Begin[x]<<" "<<End[x]<<endl;

            if(lvl[x]%2==0)
            {
                update(Begin[x],val);
                if(End[x]!=n+1)
                    update(End[x],-val);
            }
            else
            {
                update(Begin[x],-val);
                if(End[x]!=n+1)
                    update(End[x],val);
            }
        }
        else
        {
            ///x=2
            cin>>x;

            if(lvl[x]%2==0)
                cout<<query(Begin[x])+a[x]<<endl;
            else
                cout<<-query(Begin[x])+a[x]<<endl;
        }
    }

    return 0;
}