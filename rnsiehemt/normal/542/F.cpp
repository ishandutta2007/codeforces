#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int N, T;
std::vector<int> v[105];
bool seen[105][1005];
int ksh[105][1005];

int f(int t, int p) {
    if (t >= T) return 0;
    else if (seen[t][p]) return ksh[t][p];
    else seen[t][p] = true;
    int sum = 0;
    ksh[t][p] = f(t+1, std::min(p*2, 1000));
    for (int i = 0; i < sz(v[t]) && (p-(i+1))*2 >= 0; i++) {
        sum += v[t][i];
        ksh[t][p] = std::max(ksh[t][p], sum + f(t+1, std::min(1000, (p-(i+1))*2)));
    }
    return ksh[t][p];
}
 
int main()
{
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) {
        int t, w; scanf("%d%d", &t, &w);
        t = T-t;
        v[t].push_back(w);
    }
    for (int t = 0; t < T; t++) {
        std::sort(v[t].begin(), v[t].end());
        std::reverse(v[t].begin(), v[t].end());
    }
    printf("%d\n", f(0, 1));
}