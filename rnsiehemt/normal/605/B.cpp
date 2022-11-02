#include <bits/stdc++.h>
#define sz(x) (int((x).size()))

const int MaxN = 100005;

int N, M, p[MaxN];
std::vector<std::tuple<int, int, int>> v;
std::vector<std::tuple<int, int>> w;
std::tuple<int, int> e[MaxN];

int find(int a) { return (a == p[a] ? a : p[a] = find(p[a])); }
void fail() { printf("-1\n"); exit(0); }

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        v.push_back(std::make_tuple(a, 1-b, i));
    }
    
    for (int i = 0; i < N; i++) p[i] = i;
    std::sort(v.begin(), v.end());
    int cur = 1;
    for (auto t : v) {
        int mst = 1-std::get<1>(t), j = std::get<2>(t);
        if (mst) {
            p[find(cur+1)] = p[find(cur)];
            e[j] = std::make_tuple(cur, cur+1);
            for (int i = 1; i < cur; i++) {
                if (sz(w) > M) break;
                w.push_back(std::make_tuple(i, cur+1));
            }
            cur++;
        } else {
            if (w.empty()) fail();
            else {
                e[j] = w.back();
                w.pop_back();
            }
        }
    }

    for (int i = 0; i < M; i++) printf("%d %d\n", std::get<0>(e[i]), std::get<1>(e[i]));
}