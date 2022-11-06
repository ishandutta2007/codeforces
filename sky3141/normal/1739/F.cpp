#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 1000 + 9, S = 12, SS = 2000 + 9, INF = 1000000000;

struct Node
{
    int cost;
    Node *next[26], *fail;
    int f[1 << S];
    Node *prev[1 << S];
    int pstate[1 << S];
    char pc[1 << S];
} *root, pool[SS * 2], *alloc = pool, *nil = pool;

Node* newNode()
{
    ++alloc;
    fill(begin(alloc->f), end(alloc->f), -INF);
    return alloc;
}

void add(const string &s, int cost)
{
    Node *cur = root;
    for (auto c : s)
    {
        Node* &nxt = cur->next[c - 'a'];
        if (!nxt)
            nxt = newNode();
        cur = nxt;
    }
    cur->cost += cost;
}

void solve()
{
    int n;
    cin >> n;

    root = newNode();
    root->fail = nil;
    fill(begin(nil->next), end(nil->next), root);
    
    for (int i = 0; i < n; ++i)
    {
        int cost;
        string s;
        cin >> cost >> s;
        int len = s.length();
        bool g[S][S]{};
        for (int i = 1; i < len; ++i)
        {
            int u = s[i - 1] - 'a', v = s[i] - 'a';
            g[u][v] = g[v][u] = true;
        }
        int d[S]{};
        int start = -1;
        for (int i = 0; i < S; ++i)
        {
            d[i] = count(g[i], g[i] + S, true);
            if (d[i] > 2)
            {
                start = -1;
                break;
            }
            if (d[i] == 1)
                start = i;
        }
        if (start == -1)
            continue;
        string curs;
        function<void(int, int)> dfs = [&](int cur, int fa)
        {
            curs.push_back('a' + cur);
            for (int i = 0; i < S; ++i)
            {
                if (i != fa && g[cur][i])
                    dfs(i, cur);
            }
        };
        dfs(start, -1);
        add(curs, cost);
        reverse(curs.begin(), curs.end());
        add(curs, cost);
    }
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();
        cur->cost += cur->fail->cost;
        for (int i = 0; i < S; ++i)
        {
            if (cur->next[i])
            {
                cur->next[i]->fail = cur->fail->next[i];
                que.push(cur->next[i]);
            }
            else
            {
                cur->next[i] = cur->fail->next[i];
            }
        }
    }

    fill(begin(root->f), end(root->f), 0);
    for (int i = 0; i < (1 << S); ++i)
    {
        for (Node *cur = alloc; cur != pool; --cur)
        {
            for (int j = 0; j < S; ++j)
            {
                if (i & (1 << j))
                    continue;
                int nstate = i | (1 << j);
                if (cur->f[i] + cur->next[j]->cost > cur->next[j]->f[nstate])
                {
                    cur->next[j]->f[nstate] = cur->f[i] + cur->next[j]->cost;
                    cur->next[j]->pc[nstate] = 'a' + j;
                    cur->next[j]->prev[nstate] = cur;
                    cur->next[j]->pstate[nstate] = i;
                }
            }
        }
    }
    
    int mx = -INF;
    Node *p;
    int state;

    for (int i = 0; i < (1 << S); ++i)
    {
        for (Node *cur = alloc; cur != pool; --cur)
        {
            if (cur->f[i] > mx)
            {
                mx = cur->f[i];
                p = cur;
                state = i;
            }
        }
    }
    string ans;
    while (p != root || state != 0)
    {
        ans.push_back(p->pc[state]);
        auto tmp = p->prev[state];
        state = p->pstate[state];
        p = tmp;
    }
    for (int i = 0; i < S; ++i)
    {
        if (find(ans.begin(), ans.end(), 'a' + i) == ans.end())
        {
            ans.push_back('a' + i);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}