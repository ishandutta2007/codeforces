#include<bits/stdc++.h>
using namespace std;

int t, n;
char s[1000];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%s", &n, s);
        int cnt = 0;
        for(int i = n - 1; i >= 0 && s[i] == ')'; i --) cnt ++;
        puts(cnt * 2 > n ? "YES" : "NO");
    }
}