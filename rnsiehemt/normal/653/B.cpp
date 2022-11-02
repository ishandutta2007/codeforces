#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, Q, ans;
char a[40][2], b[40];
char s[10];

void go(int i) {
    if (i == N) {
        std::vector<char> v;
        for (int j = N-1; j >= 0; j--) v.pb(s[j]);
        for (int j = 0; j < N-1; j++) {
            int k = sz(v);
            bool found = false;
            for (int l = 0; l < Q; l++) {
                if (v[k-1] == a[l][0] && v[k-2] == a[l][1]) {
                    found = true;
                    v.pop_back();
                    v.pop_back();
                    v.push_back(b[l]);
                    break;
                }
            }
            if (!found) return;
        }
        if (v[0] == 'a') ans++;
    } else {
        for (char c = 'a'; c <= 'f'; c++) {
            s[i] = c;
            go(i+1);
        }
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < Q; i++) scanf(" %s %c", a[i], b+i);
    go(0);
    printf("%d\n", ans);
}