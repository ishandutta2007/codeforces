#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
vector<int> e[200010];
int ind[200010];
int d[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            ind[i] = 0;
            d[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int K;
            scanf("%d",&K);
            ind[i] = K;
            while(K--) {
                int u;
                scanf("%d",&u);
                e[u].push_back(i);
            }
        }
        int done = 0;
        set<int> ok;
        for (int i = 1; i <= n; i++) {
            if (!ind[i]) {
                d[i] = 1;
                ok.insert(i);
            }
        }
        int ans = 0;
        while(!ok.empty()) {
            ans++;
            int now = *ok.begin();
            set<int> nok;
            while(true) {
                done++;
                for (auto &t : e[now]) {
                    if (--ind[t] == 0) {
                        if (t < now) {
                            nok.insert(t);
                        } else {
                            ok.insert(t);
                        }
                    }
                }
                auto it = ok.upper_bound(now);
                if (it == ok.end()) {
                    ok.erase(now);
                    break;
                }
                int nxt = (*it);
                ok.erase(now);
                now = nxt;
            }
            ok = nok;
        }
        if (done != n) {
            puts("-1");
        } else {
            printf("%d\n",ans);
        }
    }
}