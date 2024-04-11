#include <bits/stdc++.h>
using namespace std;

int N, k;
char str[101010];
int cnt[30], ans;

int main(){
    scanf("%d %d", &N, &k);
    scanf("%s", str);
    for (int i=0; i<N; i++) cnt[str[i] - 'A']++;
    ans = cnt[0];
    for (int i=1; i<k; i++) ans = min(ans, cnt[i]);
    printf("%d", ans * k);
    return 0;
}