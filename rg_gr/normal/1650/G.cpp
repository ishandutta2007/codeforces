#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
#define int unsigned long long
const int maxn = 2e5 + 5;//
const int maxm = 4e5 + 5;//
const int inf = 0x33f3f3f3f3f3f3f;
//const LL inf = 0x3f3f3f3f3f3f3f3f;

struct Dijstra//d2[t] < inf
{
    int n, m;
    int d[2][maxn];//LLd[0]d[1]
    int cnt[2][maxn];//cnt[0]cnt[1]
    int head[maxn]={0},vv[maxn]={0};
    //int par[maxn];//
    struct Edge
    {
        int to, nxt;
        int dis;//LL
    }e[maxm];

    struct Node
    {
        int f;//01
        int u;//
        int dis;//LL
        bool operator<(const Node &rhs) const
        {
            return dis > rhs.dis;
        }
    };
	inline void first(){
	memset(head, 0xff, sizeof(head));
	}
    inline void init(int nn)
    {   n = nn;
        //for(int p=1;p<=maxn;p++) {if(head[p]==0xff) break;head[p]=0xff;}
	    memset(head, 0xff, (sizeof(head)));
        m = 0;
    }

    inline void addEdge(int from, int to, int dis)//LL dis
    {
	    //memset(head, 0xff, sizeof(head));
        e[m].to = to;
        e[m].dis = dis;
        e[m].nxt = head[from];
        head[from] = m++;
    }

    inline void finda(int s)
    {
        priority_queue<Node> q;
        for(int i = 0; i < n; ++i) d[0][i]  = d[1][i] = inf;//0~n-1
        d[0][s] = 0;
        for(int i = 0; i < n; ++i) cnt[0][i] = cnt[1][i] = 0;
        cnt[0][s] = 1;
        q.push((Node){0, s, 0});

        while(!q.empty())
        {
            Node x = q.top(); q.pop();
            int u = x.u;
            int dis = x.dis;
            int f = x.f;
            if(d[f][u] < dis) continue;
            for(int i = head[u]; ~i; i = e[i].nxt)
            {
                int v = e[i].to;
                int dd = dis + e[i].dis;//LL
                if(d[0][v] > dd)//
                {
                    if(d[0][v] < inf)//
                    {
                        d[1][v] = d[0][v];
                        cnt[1][v] = cnt[0][v];
                        q.push((Node){1, v, d[1][v]});
                    }

                    //
                    d[0][v] = dd;
                    cnt[0][v] = cnt[f][u];
                    q.push((Node){0, v, d[0][v]});
                }
                else if(d[0][v] == dd)//
                {
                    (cnt[0][v] += cnt[f][u])%=1000000007;
                }
                else if(d[1][v] > dd)//
                {
                    d[1][v] = dd;
                    cnt[1][v] = cnt[f][u];
                    q.push((Node){1, v, d[1][v]});
                }
                else if(d[1][v] == dd)//
                {
                    (cnt[1][v] += cnt[f][u])%=1000000007;
                }
            }
        }

    }
}a;


signed main()
{
    int T;
    cin >> T;
    while(T--){
        int n, m;
        //a.first();
        scanf("%lld%lld", &n, &m);
        a.init(n);
        int s, t;
        scanf("%lld%lld", &s, &t);
        int u, v, w;
        for(int i = 0; i < m; ++ i)
        {
            scanf("%lld%lld", &u, &v);
            a.addEdge(u-1, v-1, 1);
            a.addEdge(v-1, u-1, 1);
        }
        --s;--t;
        a.finda(s);
        int res = a.cnt[0][t];
        if(a.d[1][t] - 1 == a.d[0][t]) (res += a.cnt[1][t])%=1000000007;
        printf("%llu\n", res);
    }
    return 0;
}