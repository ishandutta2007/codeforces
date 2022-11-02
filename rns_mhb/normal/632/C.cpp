#include <bits/stdc++.h>
using namespace std;

#define N 50005

int n;
int id[N];
char tmp[N];
string s[N];

bool cmp(int x, int y) { return s[x] + s[y] < s[y] + s[x]; }

int main() {
    scanf("%d ", &n);
    for (int i = 0; i < n; i ++) {
        gets(tmp);
        s[i] = tmp;
        id[i] = i;
    }
    sort(id, id + n, cmp);
    for (int i = 0; i < n; i ++) printf("%s", s[id[i]].c_str());
    puts("");
    return 0;
}