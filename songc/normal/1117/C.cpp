#include <bits/stdc++.h>
#define INF ((LL)1e18 + 123456)
using namespace std;
typedef long long LL;

int N;
int sx, sy;
int ex, ey;
LL dx[101010], dy[101010], ans=-1;
char S[101010];

int main(){
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    scanf("%d", &N);
    scanf("%s", S+1);
    for (int i=1; i<=N; i++){
        dx[i] = dx[i-1], dy[i] = dy[i-1];
        if (S[i] == 'U') dy[i]++;
        if (S[i] == 'D') dy[i]--;
        if (S[i] == 'L') dx[i]--;
        if (S[i] == 'R') dx[i]++;
    }
    LL L=0, H=INF;
    while (L<=H){
        LL mid = (L+H)/2;
        LL x = sx + mid/N*dx[N] + dx[mid%N];
        LL y = sy + mid/N*dy[N] + dy[mid%N];
        if (abs(x-ex) + abs(y-ey) <= mid) H = mid-1, ans = mid;
        else L = mid+1;
    }
    if (ans == -1) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}