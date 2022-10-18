#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int can;
    int n;
    vector<pair<int, int>> edg;
    vector<int> st;
    vector<bool> visit;
    deque<int> que;
    vector<int> dep;

    scanf("%d", &can);

    for (int cas = 0; cas < can; cas++)
    {
        scanf("%d", &n);
        edg.resize(2*n-2);
        st.resize(n+1);
        visit.resize(n);
        dep.resize(n);
        for (int i = 0; i < n-1; i++)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            edg[i*2].first = a;
            edg[i*2].second = b;
            edg[i*2+1].first = b;
            edg[i*2+1].second = a;
        }

        std::sort(edg.begin(), edg.end());
        int m = 2*n-2;
        for (int i = 0; i < m; i++)
        {
            if (i == 0 || edg[i].first != edg[i-1].first)
            {
                st[edg[i].first] = i;
            }
        }
        st[n] = m;

        for (int i = 0; i < n; i++)
        {
            visit[i] = 0;
            dep[i] = 0;
        }

        que.clear();
        que.push_back(0);
        if (st[1] - st[0] < 2)
        {
            printf("%d\n", n-2);
            continue;
        }

        int ans = 0;
        while (!que.empty())
        {
            int v = *que.begin();
            visit[v] = 1;
            if (v != 0 && st[v+1] - st[v] <= 2)
            {
                int cur = n - 2*dep[v] - (st[v+1] - st[v]);
                if (cur > ans)
                {
                    ans = cur;
                }
            }
            for (int i = st[v]; i < st[v+1]; i++)
            {
                int w = edg[i].second;
                if (!visit[w])
                {
                    visit[w] = 1;
                    dep[w] = dep[v] + 1;
                    que.push_back(w);
                }
            }
            que.pop_front();
        }

        printf("%d\n", ans);
    }

    return 0;
}