#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
set<int> A[N];
bool v[N], u[N];
set<int> e;
int w[N], w1[N];
int n;

void chk(int x) {
    if ((int) A[x].size() != 2) return;
    bool F = 0;
    for (set<int>::iterator i = A[x].begin(); i != A[x].end(); i ++) 
        if ((int) A[*i].size() == 1) F = 1;
    if (F) e.insert(x);
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        x --; y --;
        A[x].insert(y); A[y].insert(x);
    }
    for (int i = 0; i < n; i ++) chk(i);
    while (!e.empty()) {
        int x = *e.begin();
        int y = *A[x].begin();
        A[x].erase(y);
        int z = *A[x].begin();
        A[x].erase(z);
        v[x] = 1;
        e.erase(x);
        A[y].erase(x);
        A[y].insert(z);
        A[z].erase(x);
        A[z].insert(y);
        chk(y); chk(z);
    }
    for (int i = 0; i < n; i ++) if ((int) A[i].size() > 1) u[i] = 1;
    for (int i = 0; i < n; i ++) if (u[i]) {
        int c = 0; int c1 = 0;
        for (set<int>::iterator j = A[i].begin(); j != A[i].end(); j ++) {
            if (u[*j]) c ++;
            else c1 ++;
        }
        w[i] = c; w1[i] = c1;
    }
    bool F = 1;
    for (int i = 0; i < n; i ++) if (u[i]) {
        int c = 0;
        for (set<int>::iterator j = A[i].begin(); j != A[i].end(); j ++) if (u[*j] && w[*j] >= 2) c ++;
        if (c >= 3) F = 0;
    }
    if (!F) { puts ("No"); return 0;}
    for (int i = 0; i < n; i ++) if (u[i] && w[i] >= 3) {
        int c = 0;
        for (set<int>::iterator j = A[i].begin(); j != A[i].end(); j ++) if (u[*j] && (w[*j] >= 2 || (w[*j] == 1 && w1[*j] >= 3))) c ++;
        if (c >= 3) F = 0;
    }
    if (!F) { puts ("No"); return 0;}
    puts ("Yes");
    return 0;
}