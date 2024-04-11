#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,L,K;
char q[1000010];
int l,r;
char ans[1010][1010];

int main() {
    scanf("%d%d%d",&N,&L,&K);
    scanf("%s",q + 1);
    sort(q + 1, q + N * L + 1);
    l = 1;
    r = N * L;
    memset(ans, 0, sizeof(ans));
    for (int i=1;i<=K;i++) {
        ans[i][1] = q[l++];
    }
    int lastsame = K;
    while(ans[lastsame-1][1] == ans[K][1]) lastsame--;
    for (int pos=2;pos<=L;pos++) {
        int tmp = K;
        while(ans[tmp-1][pos-1] == ans[K][pos-1]) tmp--;
        lastsame = max(lastsame, tmp);
        for (int i=lastsame;i<=K;i++) {
            ans[i][pos] = q[l++];
        }
        for (int i=lastsame-1;i>=1;i--) {
            ans[i][pos] = q[r--];
        }
    }    
    for (int i=K+1;i<=N;i++) {
        for (int j=1;j<=L;j++) {
            ans[i][j] = q[l++];
        }
    }
    for (int i=1;i<=N;i++) {
        printf("%s\n",ans[i] + 1);
    }
}