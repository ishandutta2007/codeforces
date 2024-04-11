#include <bits/stdc++.h>

int N;
int ansi[20005], ansj[20005], K;
std::vector<int> e[1005];
bool f[1005];

void solve(int z) {
    for (int i = 0; i < N-1; i++) e[i].push_back(i+1);
    for (int i = 0; i < N-3; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        if (a > b) std::swap(a, b);
        e[a].push_back(b);
    }
    for (int i = 0; i < N; i++) std::sort(e[i].begin(), e[i].end());
    for (int i = 0; i < (int)e[0].size(); i++)
        f[e[0][i]] = true;

    int cur = 0;
    for (int i = 1; i < N-1; i++) {
        if (!f[i]) {
            cur = i-1;
            for (int j = (int)e[cur].size()-1; j >= 1; j--) {
                if (z == 0) { ansi[K] = cur; ansj[K] = e[cur][j]; K++; }
                else { ansi[K] = 0; ansj[K] = e[cur][j-1]; K++; }
                f[e[cur][j]] = true;
            }
        }
    }
}

void clear() {
    for (int i = 0; i < N; i++) {
        e[i].clear();
        f[i] = false;
    }
}

int main()
{
    scanf("%d", &N);
    solve(0);
    clear();
    int kk = K;
    solve(1);
    std::reverse(ansi+kk, ansi+K);
    std::reverse(ansj+kk, ansj+K);
    printf("%d\n", K);
    for (int i = 0; i < K; i++) printf("%d %d\n", ansi[i]+1, ansj[i]+1);
}