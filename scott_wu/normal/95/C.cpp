#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1100;
const ll INF = 100000000000000LL;

struct blah
{
    int endd;
    ll dist;
};

vector <blah> edge[MAXN];
vector <blah> edge2[MAXN];
ll bdist[MAXN][MAXN];
ll fdist[MAXN];
ll cost[MAXN];
ll mdist[MAXN];
int n, m;
int snode, enode;

inline bool operator < (blah left, blah right)
{
    return left.dist > right.dist;
}

void dijk (int start)
{
    priority_queue <blah> pq;
    bool seen[MAXN];
    for (int i = 0; i < MAXN; i++)
        seen[i] = false;
    seen[start] = true;
    while (!pq.empty())
        pq.pop();
    for (int i = 0; i < edge[start].size(); i++)
        pq.push (edge[start][i]);
    while (!pq.empty())
    {
        //cout << start;
        while (!pq.empty() && seen[pq.top().endd])
            pq.pop();
        if (pq.empty())
            break;
        int next = pq.top().endd;
        seen[next] = true;
        bdist[start][next] = pq.top().dist;
        //cout << pq.top().endd << " " << pq.top().dist << "\n";
        for (int i = 0; i < edge[next].size(); i++)
        {
            if (!seen[edge[next][i].endd])
            {
                blah t;
                t.endd = edge[next][i].endd;
                t.dist = edge[next][i].dist + pq.top().dist;
                pq.push (t);
            }
        }
    }
}

void dijk2 ()
{
    priority_queue <blah> pq;
    bool seen[MAXN];
    for (int i = 0; i < MAXN; i++)
        seen[i] = false;
    seen[snode] = true;
    for (int i = 0; i < edge2[snode].size(); i++)
        pq.push (edge2[snode][i]);
    while (!pq.empty())
    {
        while (!pq.empty() && seen[pq.top().endd])
            pq.pop();
        if (pq.empty())
            break;
        int next = pq.top().endd;
        seen[next] = true;
        fdist[next] = pq.top().dist;
        for (int i = 0; i < edge2[next].size(); i++)
        {
            if (!seen[edge2[next][i].endd])
            {
                blah t;
                t.endd = edge2[next][i].endd;
                t.dist = edge2[next][i].dist + pq.top().dist;
                pq.push (t);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            bdist[i][j] = INF;
    for (int i = 0; i < MAXN; i++)
        fdist[i] = INF;
    cin >> n >> m;
    cin >> snode >> enode;
    snode--; enode--;
    if (snode == enode)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        blah t;
        int temp, temp2;
        cin >> temp >> temp2 >> t.dist;
        temp--; temp2--;
        t.endd = temp2;
        edge[temp].push_back (t);
        t.endd = temp;
        edge[temp2].push_back (t);
        //cout << t.endd << " " << t.dist << "\n";
    }
    for (int i = 0; i < n; i++)
        cin >> mdist[i] >> cost[i];
    for (int i = 0; i < n; i++)
        dijk (i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i != j && (bdist[i][j] <= mdist[i]))
            {
                blah t;
                t.endd = j;
                t.dist = cost[i];
                edge2[i].push_back (t);
            }
        }
    dijk2 ();
    if (fdist[enode] == INF)
        cout << "-1\n";
    else
        cout << fdist[enode] << "\n";
    //system ("Pause");
    return 0;
}