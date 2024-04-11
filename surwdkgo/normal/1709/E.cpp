#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>

using namespace std;

#define MAXN 200010
#define F first
#define S second

int64_t s64() { int64_t res; scanf("%" PRId64, &res); return res; }
void p64(int64_t res) { printf("%" PRId64, res); }

vector<vector<int>> edg;
int n;
int inp[MAXN];
int vis[MAXN];
int cnt;

struct tron
{
    set<int>* st = nullptr;
    int delta = 0;

    bool find(int v)
    {
        return st->find(v^delta) != st->end();
    }
    void insert(int v)
    {
        st->insert(v^delta);
    }
};

tron dfs(int i)
{
    vis[i] = 1;

    bool ok = true;
    tron st;
    for (int v : edg[i])
    {
        if (!vis[v])
        {
            tron sub = dfs(v);
            if (st.st == nullptr)
            {
                swap(sub, st);
            }
            else if (ok)
            {
                if (sub.st->size() > st.st->size())
                {
                    swap(sub, st);
                }

                for (int value : *sub.st)
                {
                    if (st.find((value^sub.delta) ^ inp[i]))
                    {
                        ok = false;
                        break;
                    }
                }
                for (int value : *sub.st)
                {
                    st.insert(value^sub.delta);
                }
            }
        }
    }
    if (st.st == nullptr)
    {
        st.st = new set<int>();
        st.st->insert(inp[i]);
        return st;
    }

    if (st.find(inp[i]))
    {
        ok = false;
    }
    st.delta ^= inp[i];
    st.insert(inp[i]);

    if (!ok)
    {
        cnt++;
        tron tmp;
        tmp.st = new set<int>();
        return tmp;
    }

    return st;
}

int main()
{
    scanf("%d",&n);
    edg.resize(n);
    for (int i = 0; i < n ; i++)
    {
        scanf("%d", &inp[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        s--;
        t--;
        edg[s].push_back(t);
        edg[t].push_back(s);
    }

    dfs(0);

    printf("%d\n", cnt);

    return 0;
}