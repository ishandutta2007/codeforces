#include <bits/stdc++.h>
using namespace std;

const int M = 2000001;

char s[M];

int main() {
    int n;
    scanf("%d", &n);
    if(n > 26) return puts("-1");
    scanf("%s", s);
    int cnt = 0;
    int vis[101];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i ++) {
        if(vis[s[i]-'a']) cnt ++;
        vis[s[i] - 'a'] = 1;
    }
    cout << cnt << endl;
}