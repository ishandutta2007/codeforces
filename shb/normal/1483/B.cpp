#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, a[100010];
int pre[100010], suc[100010];
int fa[100010];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int com;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            pre[i] = i - 1;
            suc[i] = i + 1;
            fa[i] = i;
        }
        pre[1] = N;
        suc[N] = 1;
        com = N;
        for (int i=1;i<=N;i++) {
            if (__gcd(a[i], a[suc[i]]) != 1) {
                if (find(i) == find(suc[i])) continue;
                com--;
                fa[i] = find(suc[i]);
            }
        }
        //for (int i=1;i<=N;i++) printf("find[%d]=%d\n",i,find(i));
        vector<int>ans;
        int now = 1;
        while(com > 1) {
            int nxt = find(now);
            nxt = suc[nxt];
            //printf("erase %d\n",nxt);
            int L = pre[nxt], R = suc[nxt];
            //printf("L, R = %d, %d\n",L,R);
            ans.push_back(nxt);
            if (find(nxt) == nxt) {
                com--;
            } 
            if (__gcd(a[L], a[R]) != 1) {
                //if (find(L) != find(R)) {
                    fa[L] = find(R);
                    com--;
                //}
            } else if (com == 1 && ans.size() < N - 1) {
                com++;
            }
            suc[L] = R;
            pre[R] = L;
            now = R;
        }
        int fuck = find(now);
        while(suc[fuck] != fuck && __gcd(a[fuck], a[suc[fuck]]) == 1) {
            int tmp = suc[fuck];
            ans.push_back(tmp);
            suc[fuck] = suc[tmp];
            pre[suc[tmp]] = fuck;
        }
        if (ans.size() == N - 1 && a[now] == 1) ans.push_back(now);
        printf("%d",ans.size());
        for (auto &t: ans) printf(" %d",t);
        puts("");
    }
}