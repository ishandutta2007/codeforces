#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)2e5 + 50, INF = (int)1e9;

int n;
int a[N], b[N];
int app[N];

int check_consec() {
    if(app[1] == -1) return INF;
    for(int i = app[1], j = 1; i < n; i++, j++) {
        if(b[i] != j) return INF;
    }
    int st = n - app[1] + 1;

    for(int i = st, mnst = -1; i <= n; mnst++, i++) {
        if(app[i] != -1 && app[i] > mnst) return INF;
    }
    
    return n - st + 1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int mn_st = 0;
    fill(app, app + n + 1, -1);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] != 0) {
            mn_st = max(mn_st, i + 1 - (b[i] - 1));
            app[b[i]] = i;
        }
    }
    
    cout << min(mn_st + n, check_consec()) << endl;

}