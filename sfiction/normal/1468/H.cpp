#include <bits/stdc++.h>

using namespace std;

int N, K, M;
bool keep[200010];
int s[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&K,&M);
        K /= 2;
        for (int i=1;i<=N;i++) keep[i] = false;
        for (int i=1;i<=M;i++) {
            int tmp;
            scanf("%d",&tmp);
            keep[tmp] = true;
        }
        if ((N - M) % (2 * K) != 0) {
            puts("NO");
            continue;
        } 
        s[0] = 0;
        vector<int>fuck;
        for (int i=1;i<=N;i++) {
            s[i] = s[i - 1];
            if (keep[i]) {
                s[i]++;
            }
            else {
                fuck.push_back(i);
            }
        }
        assert(fuck.size() == N - M);
        bool ok = (s[fuck[N - M - K]] - s[fuck[K - 1]] >= 1);
        puts(ok ? "YES" : "NO");
    }
}