#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int N;
int l[305], c[305];
std::unordered_map<int, int> m;
std::priority_queue<int> q;
std::vector<int> v;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &l[i]);
    for (int i = 0; i < N; i++) scanf("%d", &c[i]);
    for (int i = 0; i < N; i++) {
        if (m.find(l[i]) == m.end()) {
            m[l[i]] = c[i];
            q.push(l[i]);
            v.push_back(l[i]);
        }
        else {
            m[l[i]] = std::min(m[l[i]], c[i]);
        }
    }

    while (!q.empty()) {
        int cur = q.top(); q.pop();

        int K = v.size();
        for (int i = 0; i < K; i++) {
            int g = gcd(cur, v[i]);
            if (m.find(g) == m.end()) {
                m[g] = m[cur] + m[v[i]];
                q.push(g);
                v.push_back(g);
            }
            else if (g < cur) {
                m[g] = std::min(m[g], m[cur] + m[v[i]]);
            }
        }
    }

    if (m.find(1) == m.end()) printf("-1\n");
    else printf("%d\n", m[1]);
}