#include <bits/stdc++.h>

#define ii std::pair<int, int>
#define mp std::make_pair
#define a first
#define b second

int N;
int d[66000];
int s[66000];
bool f[66000];
std::vector<ii> e;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d", &d[i], &s[i]);

    std::priority_queue<ii, std::vector<ii>, std::greater<ii> > q;
    for (int i = 0; i < N; i++) q.push(mp(d[i], i));
    while (!q.empty()) {
        ii cur = q.top(); q.pop();

        if (f[cur.b] || d[cur.b] == 0) continue;
        else f[cur.b] = true;
        
        e.push_back(mp(cur.b, s[cur.b]));
        d[s[cur.b]]--;
        s[s[cur.b]] ^= cur.b;
        q.push(mp(d[s[cur.b]], s[cur.b]));
    }

    printf("%d\n", (int)e.size());
    for (int i = 0; i < (int)e.size(); i++) printf("%d %d\n", e[i].a, e[i].b);
}