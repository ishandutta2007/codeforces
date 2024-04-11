#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, k;
char str[202020];
int cnt[30], ans;

int main(){
    scanf("%d %d", &N, &k);
    scanf("%s", str+1);
    int x = 0;
    for (int i=1; i<=N; i++){
        if (str[i] != str[i-1]) x=1;
        else x++;
        if (x == k) cnt[str[i]-'a']++, x=0;
    }
    for (int i=0; i<26; i++) ans = max(ans, cnt[i]);
    printf("%d", ans);
    return 0;
}