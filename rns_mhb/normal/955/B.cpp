#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n;
char s[N];
map<int, int> vis;
map<int, int> :: iterator it;

int main() {
    gets(s);
    for (int i = 0; s[i]; i ++) vis[s[i]-'a'] ++;
if (vis.size() >= 5) return puts("No"), 0;
    if (vis.size() == 4) return puts("Yes"), 0;
    if (vis.size() == 3) {
        if (strlen(s) >= 4) return puts("Yes"), 0;
        else return puts("No"), 0;
    }
    if (vis.size() == 2) {
        it = vis.begin();
        if (it -> second == 1) return puts("No"), 0;
        it ++;
        if (it -> second == 1) return puts("No"), 0;
        return puts("Yes"), 0;
    }
    return puts("No"), 0;
}