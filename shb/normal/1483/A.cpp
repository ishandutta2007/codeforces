#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int ans[1000120];
int N, M;
vector<int>avl[100010];
vector<int>avl_man[100010];
int id[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++) {
            avl_man[i].clear();
        }
        for (int i=1;i<=M;i++) {
            int K;
            scanf("%d",&K);
            avl[i].resize(K);
            for (int j=0;j<K;j++) {
                int man;
                scanf("%d",&man);
                avl[i][j] = man;
                avl_man[man].push_back(i);
            }
        }
        int mx = -1, mid = -1;
        for (int i=1;i<=N;i++) {
            if (int(avl_man[i].size()) > mx) {
                mx = int(avl_man[i].size());
                mid = i;
            }
        }
        sort(avl_man[mid].begin(), avl_man[mid].end(), [&](int id1, int id2) {
            return avl[id1].size() < avl[id2].size();
        });
        for (int i=1;i<=M;i++) ans[i] = -1;
        for (int i=0;i<avl_man[mid].size() && i < (M + 1) / 2; i++) {
            ans[avl_man[mid][i]] = mid;
        }
        //printf("mid= %d\n",mid);
        bool ok = true;
        for (int i=1;i<=M;i++) {
            if (ans[i] != -1) continue;
            for (auto &t: avl[i]) {
                if (t == mid) continue;
                ans[i] = t;
                break;
            }
            if (ans[i] == -1) ok = false;
        }
        if (ok) {
            puts("YES");
            for (int i=1;i<=M;i++) {
                printf("%d%c",ans[i]," \n"[i==M]);
            }
        } else {
            puts("NO");
        }
    }
}