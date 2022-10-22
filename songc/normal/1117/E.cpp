#include <bits/stdc++.h>
using namespace std;

int N;
int P[10101];
char str[10101];
char ans[10101];
char Q[10101];

int main(){
    scanf("%s", str+1);
    N = strlen(str+1);

    for (int i=1; i<=N; i++) Q[i] = (i%26) + 'a';
    printf("? %s\n", Q+1);
    fflush(stdout);
    scanf("%s", Q+1);
    for (int i=1; i<=N; i++) P[i] += (Q[i]-'a') % 26;

    for (int i=1; i<=N; i++) Q[i] = (i/26%26) + 'a';
    printf("? %s\n", Q+1);
    fflush(stdout);
    scanf("%s", Q+1);
    for (int i=1; i<=N; i++) P[i] += (Q[i]-'a') % 26 * 26;

    for (int i=1; i<=N; i++) Q[i] = (i/676) + 'a';
    printf("? %s\n", Q+1);
    fflush(stdout);
    scanf("%s", Q+1);
    for (int i=1; i<=N; i++) P[i] += (Q[i]-'a') % 26 * 676;

    for (int i=1; i<=N; i++) ans[P[i]] = str[i];
    printf("! %s\n", ans+1);
    fflush(stdout);
    return 0;
}