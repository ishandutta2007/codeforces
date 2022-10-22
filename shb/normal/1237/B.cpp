#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
pii p[100010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        int tmp;
        scanf("%d",&tmp);
        p[tmp].first = i;
    }
    for (int i=1;i<=N;i++) {
        int tmp;
        scanf("%d",&tmp);
        p[tmp].second = i;
    }
    sort(p+1,p+N+1);
    int mx = -1,  ans = 0;
    for (int i=1;i<=N;i++) {
        if (mx > p[i].second) {
            //printf("%d %d\n",p[i].first,p[i].second);
            ans++;
        }
        mx = max(mx, p[i].second);
    }
    printf("%d\n",ans);
}