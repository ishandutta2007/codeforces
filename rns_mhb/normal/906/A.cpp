#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define K 26

int n, ans, done;
char ch;
char s[N];
set<int> maybe, nmaybe;
set<int> :: iterator it;
bool vis[K+5];

int main() {
    scanf("%d ", &n);
    for (int i = 0; i < K; i ++) maybe.insert(i);
    while (n --) {
        scanf("%c %s ", &ch, s);
        if (ch == '!') {
            if (done) ans ++;
            memset(vis, 0, sizeof vis);
            for (int i = 0; s[i]; i ++) vis[s[i]-'a'] = 1;
            nmaybe.clear();
            for (it = maybe.begin(); it != maybe.end(); it ++) if (vis[*it]) nmaybe.insert(*it);
            maybe = nmaybe;
        }
        else if (ch == '.') {
            for (int i = 0; s[i]; i ++) maybe.erase(s[i] - 'a');
        }
        else if (ch == '?') {
            if (n) {
                if (done) ans ++;
                maybe.erase(s[0] - 'a');
            }
        }
        else assert(0);
        if (maybe.size() == 1) done = 1;
    }
    printf("%d\n", ans);
}