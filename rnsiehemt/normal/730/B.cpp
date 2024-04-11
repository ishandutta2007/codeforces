#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int T, n;

char query(int i, int j) {
    printf("? %d %d\n", i+1, j+1);
    fflush(stdout);
    char x; scanf(" %c", &x);
    return x;
}

void solve() {
    std::vector<int> min, max;
    scanf("%d", &n);
    for (int i = 0; i+1 < n; i += 2) {
        char x = query(i, i+1);
        if (x == '<') { min.pb(i); max.pb(i+1); }
        else { max.pb(i); min.pb(i+1); }
    }
    if (n%2) { min.pb(n-1); max.pb(n-1); }
    int mini, maxi;
    {
        int i = 0;
        for (int j = 1; j < sz(min); j++) {
            if (query(min[i], min[j]) == '>') i = j;
        }
        mini = min[i];
    }
    {
        int i = 0; 
        for (int j = 1; j < sz(max); j++) {
            if (query(max[i], max[j]) == '<') i = j;
        }
        maxi = max[i];
    }
    printf("! %d %d\n", mini+1, maxi+1);
    fflush(stdout);
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) solve();
}