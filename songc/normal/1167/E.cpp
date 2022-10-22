#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, X;
set<int> S;
LL ans;
int Min[1010101];
int Max[1010101];
int st=INF, ed=0;

int main(){
    int a;
    scanf("%d %d", &N, &X);
    for (int i=0; i<=X; i++) Min[i] = INF;
    for (int i=1; i<=N; i++){
        scanf("%d", &a);
        if (S.upper_bound(a) != S.end()){
            int k = *S.upper_bound(a);
            Min[a] = min(Min[a], k);
            Max[a] = *(--S.end());
            ed = max(ed, a);
        }
        S.insert(a);
    }
    for (int i=0; i<=X; i++){
        st = min(st, Min[i]);
        ed = max(ed, Max[i]);
        if (st <= i) break;
        ans += X-max(i+1, ed)+1;
    }
    printf("%lld\n", ans);
    return 0;
}