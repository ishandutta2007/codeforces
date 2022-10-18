#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1000 + 11;
const int INF = 1e9;

int kk[27],kl[27];
vector<int> v[N];
int cost[N][N],capacity[N][N];
int d[N],p[N];
int n,s,t;
int typee[N];

void add_edge(int _from, int _to, int _capacity, int _cost)
{
    ///if (_capacity+_cost>0)
    ///cout<<_from<<"->"<<_to<<" = "<<_capacity<<" "<<_cost<<endl;
    v[_from].pb(_to);
    v[_to].pb(_from);
    cost[_from][_to]=_cost;
    cost[_to][_from]=-_cost;
    capacity[_from][_to]=_capacity;
}

void shortest_path()
{
    for (int i=1; i<=n; i++)
        d[i]=INF;
    d[s]=0;
    deque<int> q;
    for (int i=1; i<=n; i++)
        typee[i]=2;
    q.push_back(s);
    while (!q.empty())
    {
        int l=q.front();
        q.pop_front();
        typee[l]=0;
        for (int j=0; j<v[l].size(); j++)
        {
            int to=v[l][j];
            if (capacity[l][to]>0&&d[to]>d[l]+cost[l][to])
            {
                d[to]=d[l]+cost[l][to];
                p[to]=l;
                if (typee[to]==2)
                {
                    typee[to]=1;
                    q.push_back(to);
                }
                if (typee[to]==0)
                {
                    typee[to]=1;
                    q.push_front(to);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string st;
    cin>>st;
    for (int i=0; i<st.size(); i++)
    {
        kk[st[i]-'a'+1]++;
    }
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        int p;
        cin>>s>>p;
        add_edge(1,i+27,p,i);
        for (int j=1; j<=26; j++)
            kl[j]=0;
        for (int j=0; j<s.size(); j++)
            kl[s[j]-'a'+1]++;
        for (int j=1; j<=26; j++)
            add_edge(i+27,j+1,kl[j],0);
    }
    for (int j=1; j<=26; j++)
        add_edge(j+1,n+28,kk[j],0);
    n=n+28;
    s=1;
    t=n;
    int flow=0,cost=0;
    while (flow<(int)st.size())
    {
        shortest_path();
        if (d[t]==INF) {cout<<-1<<endl; return 0;}
        int f=(int)st.size()-flow;
        int cur=t;
        while (cur!=s)
        {
            f=min(f,capacity[p[cur]][cur]);
            cur=p[cur];
        }
        if (f==0) {cout<<-1<<endl; return 0;}
        flow+=f;
        cost+=f*d[t];
        cur=t;
        while (cur!=s)
        {
            capacity[p[cur]][cur]-=f;
            capacity[cur][p[cur]]+=f;
            cur=p[cur];
        }
    }
    cout<<cost<<endl;
}