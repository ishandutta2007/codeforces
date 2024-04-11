#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, K, ans;
bool chk[30];

int main(){
    char ch;
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++){
        scanf(" %c", &ch);
        chk[ch-'a'+1] = true;
    }
    for (int i=1; i<=26 && K; i++) if (chk[i]) K--, ans += i, i++;
    if (K) puts("-1");
    else printf("%d\n", ans);
    return 0;
}