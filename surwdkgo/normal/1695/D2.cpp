#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 400010
#define F first
#define S second
#define P pair<int,int>

int par[MAXN];
vector<P> edg;
int st[MAXN];
int ans[MAXN][2];
int child[MAXN];
int cost[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n;
        scanf("%d", &n);
        edg.clear();
        for (int i = 0; i <= n ; i++)
        {
            st[i] = 0;
            par[i] = -1;
        }
        for (int i = 0; i < n-1; i++)
        {
            int s,e;
            scanf("%d%d",&s,&e);
            s--;
            e--;
            edg.push_back(P(s,e));
            edg.push_back(P(e,s));
            st[s+1]++;
            st[e+1]++;
        }
        sort(edg.begin(), edg.end());
        for (int i = 0; i <n; i++) st[i+1]+= st[i];


        std::deque<int> q;
        q.push_back(0);
        par[0] = 0;

        std::vector<int> ord;

        while (q.size())
        {
            int d = q[0];
            q.pop_front();
            ord.push_back(d);

            for (int i = st[d]; i < st[d+1]; i++)
            {
                int e = edg[i].S;
                if (par[e] == -1)
                {
                    par[e] = d;
                    q.push_back(e);
                }
            }
        }

        int fin;
        for (int i = n-1; i >= 0; i--)
        {
            int d = ord[i];
            int nc = 0;
            for (int j = st[d]; j < st[d+1]; j++)
            {
                if (edg[j].S != par[d])
                {
                    child[nc++] = edg[j].S;
                }
            }

            if (nc == 0)
            {
                ans[d][0] = 1;
                ans[d][1] = 0;
                if (i == 0)
                {
                    fin = 0;
                }
            }
            else if (nc == 1)
            {
                ans[d][0] = ans[child[0]][0];
                ans[d][1] = ans[child[0]][1];
                if (i == 0)
                {
                    fin = ans[d][0];
                }
            }
            else
            {
                ans[d][0] = 0;
                ans[d][1] = 0;

                int numZ = 0;
                for (int j = 0; j < nc; j++)
                {
                    int delta = ans[child[j]][1];
                    if (delta == 0)
                    {
                        if (numZ) delta = 1;
                        numZ++;
                    }
                    ans[d][1] += delta;
                    //if (d == 5) printf("** %d %d\n", child[j]+1, delta);
                }
                ans[d][0] = ans[d][1] + (numZ > 0 ? 1 : 0);

                if (i == 0)
                {
                    int mi = 1e9;
                    fin = 0;
                    for (int j = 0; j < nc; j++)
                    {
                        int delta = ans[child[j]][1];
                        if (delta == 0 && numZ > 1)
                        {
                            delta = 1;
                        }
                        fin += delta;
                        mi = min(mi, ans[child[j]][0] - delta);
                    }
                    if (numZ == 1 && nc >= 3) mi = 0;
                    fin = fin + mi;
                    if (numZ > 1) fin--;

                    fin = min(fin, ans[d][0]);
                    //fin = ans[d][1];
                }
            }
        }

        //for (int i = 0; i<n; i++)printf("%d: %d %d\n", i+1, ans[i][0], ans[i][1]);
        printf("%d\n", fin);
    }

    return 0;
}