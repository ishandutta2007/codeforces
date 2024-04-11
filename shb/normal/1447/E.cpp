#include <bits/stdc++.h>

using namespace std;

int N, a[200010];
const int W = 31;
const int MAXNODE = (W + 1) * 200010;
int ch[MAXNODE][2], cnt[MAXNODE];
int M = 1;

void ins(int v) {
    //printf("ins %d\n",v);
    int now = 1;
    cnt[1]++;
    for (int i=W;i>=0;i--) {
        int dir = ((v >> i) & 1);
        int &nxt = ch[now][dir];
        if (!nxt) nxt = ++M;
        cnt[nxt]++;
        now = nxt;
        //printf("now = %d\n",now);
    }
}

int dfs(int x) {
    if (x == 0) return 0;
    if (!ch[x][0] && !ch[x][1]) return 1;
    return max(dfs(ch[x][0]) + (!!ch[x][1]), dfs(ch[x][1]) + (!!ch[x][0]));
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=N;i++) {
        ins(a[i]);
    }
    printf("%d\n",N - dfs(1));
}