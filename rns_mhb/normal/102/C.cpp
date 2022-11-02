#include<bits/stdc++.h>
using namespace std;

char s[100010];
pair<int, int> f[26];
bool vis[26];

int main() {
    int k, n, i, sum;
    scanf("%s%d", s, &k);
    n = strlen(s);
    for(i = 0; i < n; i ++) f[s[i] - 'a'].first ++;
    for(i = 0; i < 26; i ++) f[i].second = i;
    sort(f, f + 26);
    for(i = sum = 0; i < 26; i ++) {
        sum += f[i].first;
        if(sum > k) break;
        vis[f[i].second] = 1;
    }
    if(i == 26) {puts("0"); return 0;}
    printf("%d\n", 26 - i);
    for(i = 0; i < n; i ++) if(!vis[s[i] - 'a']) putchar(s[i]);
}