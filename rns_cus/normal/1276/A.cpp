#include <bits/stdc++.h>
using namespace std;

#define N 200100

char s[N];
bool vis[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < n; i ++) vis[i] = 0;
        vector <int> vec;
        for (int i = 0; i < n - 2; i ++) {
            if (vis[i] || vis[i+1] || vis[i+2]) continue;
            if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') vec.push_back(i + 1), vis[i+1] = 1;
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
                if (i + 3 < n && s[i+3] == 'n') vec.push_back(i + 2), vis[i+2] = 1;
                else vec.push_back(i + 1), vis[i+1] = 1;
            }
        }
        int sz = vec.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; i ++) printf("%d%c", vec[i] + 1, " \n"[i==sz-1]);
    }

    return 0;
}