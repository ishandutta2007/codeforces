// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5e5 + 5, INF = 1e9;

int n, f[N];

char s[N];



int g(int x) {
    return f[x];
}

int wk() {  
    int cr = 0, cb = 0;
    for (int i = 1; i <= n; i++) 
        if (s[i] == 'R') cr++;
        else cb++;
    if (cr > cb) return 1;
    if (cb > cr) return 0;
    int sg = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j < n && s[j + 1] != s[j]) j++;
        int z = j - i + 1;
        sg ^= g(z);
        i = j;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << f[i] << endl;
    // }
    return sg;
}

set<int> st;

int main() {
    for (int i = 1; i <= 1000; i++) {
        st.clear();
        for (int j = 0; j + 2 <= i; j++) {
            int k = i - j - 2;
            int v = f[j] ^ f[k];
            st.insert(v);
        }
        while (st.count(f[i])) f[i]++;
    }
    for (int i = 1001; i < N; i++) f[i] = f[i - 34];

    int T; read(T);
    while (T--) {
      read(n);
      scanf("%s", s + 1);  
      puts(wk() ? "Alice" : "Bob"); 
    }   
    return 0;
}