#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, ans;
int cnt[30];
char str[110];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%s", str);
        cnt[str[0]-'a']++;
    }
    for (int i=0; i<26; i++){
        if (cnt[i] & 1) ans += (cnt[i]/2) * (cnt[i]/2-1) / 2 + (cnt[i]/2+1) * (cnt[i]/2) / 2;
        else ans += 2 * (cnt[i]/2) * (cnt[i]/2-1) / 2;
    }
    printf("%d\n", ans);
    return 0;
}