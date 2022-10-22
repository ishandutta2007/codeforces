#include <bits/stdc++.h>
using namespace std;

int N;
int zeb[101010], ans;
int S, E;
char str[101010];

int main(){
    scanf("%s", str+1);
    N = strlen(str+1);
    for (int i=1; i<=N; i++){
        if (str[i] != str[i-1]) zeb[i] = zeb[i-1] + 1;
        else zeb[i] = 1;
        ans = max(ans, zeb[i]);
    }
    if (str[1] == str[N]) {
        printf("%d", ans);
        return 0;
    }
    for (int i=1; i<=N && str[i] != str[i-1]; i++) S = i;
    for (int i=1; i<=N && str[N-i+1] != str[N-i+2]; i++) E = i;
    ans = max(ans, S+E);
    printf("%d", min(ans, N));
    return 0;
}