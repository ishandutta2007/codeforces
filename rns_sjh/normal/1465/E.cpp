#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n;
long long t;
char s[N];

int two[30], cnt[30];

int main() {
    two[0] = 1;
    for(int i = 1; i < 30; i ++) two[i] = two[i - 1] << 1;
    scanf("%d%lld", &n, &t);
    scanf("%s", s);
    for(int i = 0; i < n; i ++) t -= two[s[i] - 'a'];
    t += 2 * two[s[n - 2] - 'a'];
    for(int i = 0; i < n - 2; i ++) cnt[s[i] - 'a'] ++;
    if(t > 0 || t & 1) {
        puts("No");
        return 0;
    }
    t = -t;
    t >>= 1;
    for(int i = 25; i >= 0 && t; i --) {
        while(cnt[i] --) if(t >= two[i]) t -= two[i];
    }
    puts(t ? "No" : "Yes");
}