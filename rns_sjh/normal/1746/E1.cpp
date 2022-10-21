#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int n;
vector<int> x, y[4];
char s[10];

int ask(int a) {
    printf("? 1 %d\n", a);
    fflush(stdout);
    scanf("%s", s);
    return strcmp(s, "NO");
}

int ask(vector<int> a, vector<int> b) {
    printf("? %d", a.size() + b.size());
    for(int u : a) printf(" %d", u);
    for(int u : b) printf(" %d", u);
    puts("");
    fflush(stdout);
    scanf("%s", s);
    return strcmp(s, "NO");
}

int guess(int a) {
    printf("! %d\n", a);
    fflush(stdout);
    scanf("%s", s);
    return strcmp(s, ":(");
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) x.push_back(i);
    while(x.size() > 3) {
        int m = x.size();
        for(int k = 0; k < 4; k ++) {
            y[k].clear();
            for(int i = m * k / 4; i < m * (k + 1) / 4; i ++) y[k].push_back(x[i]);
        }
        int l = 0;
        if(ask(y[0], y[1])) l += 2;
        if(ask(y[0], y[2])) l += 1;
        x.clear();
        for(int k = 0; k < 4; k ++) if(k != l) for(int u : y[k]) x.push_back(u);
    }
    if(x.size() == 3) {
        x.push_back(x[0]);
        x.push_back(x[1]);
        vector<int> z;
        for(int i = 0; i < 3; i ++) {
            int u = ask(x[i]);
            int v = ask(x[i + 1]);
            if(!u && !v) continue;
            if(u && v) {
                z.push_back(x[i]), z.push_back(x[i + 1]);
                x = z;
                break;
            }
            if(u && !v) {
                z.push_back(x[i]), z.push_back(x[i + 2]);
                x = z;
                break;
            }
            if(!u && v) {
                z.push_back(x[i + 1]), z.push_back(x[i + 2]);
                x = z;
                break;
            }
        }
        if(z.empty()) {
            z.push_back(x[0]);
            x = z;
        }
    }
    if(x.size() == 1) {
        guess(x.front());
        return 0;
    }
    if(x.size() == 2) {
        if(!guess(x.front())) guess(x.back());
        return 0;
    }
}