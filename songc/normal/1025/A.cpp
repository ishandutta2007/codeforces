#include <bits/stdc++.h>
using namespace std;

int N;
char str[1010101];
int cnt[30];

int main(){
    scanf("%d", &N);
    scanf("%s", str);
    if (N==1) {
        puts("YES");
        return 0;
    }
    for (int i=0; i<N; i++) cnt[str[i]-'a']++;
    bool tf = true;
    for (int i=0; i<26; i++) if (cnt[i] > 1) tf = false;
    if (tf) puts("NO");
    else puts("YES");
    return 0;
}