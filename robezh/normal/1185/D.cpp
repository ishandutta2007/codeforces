#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, INVAL = (int)2e9 + 50;
typedef pair<int, int> P;

int n;
P p[N];
int dif[N];
ll pval[N], sval[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    if(n <= 3) return cout << 1 << endl, 0;
    sort(p, p + n);
    for(int i = 1; i < n; i++) dif[i] = p[i].first - p[i-1].first;
    n--;
    for(int i = n; i >= 1; i--) {
        if(i != n && (sval[i+1] == INVAL || sval[i+1] != dif[i])) sval[i] = INVAL;
        else sval[i] = dif[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i != 1 && (pval[i-1] == INVAL || pval[i-1] != dif[i])) pval[i] = INVAL;
        else pval[i] = dif[i];
    }
    for(int i = 1; i + 1 <= n; i++) {
        bool good = false;
        int cur = dif[i] + dif[i+1];
        if(i == 1) {
            good = (sval[i+2] == cur);
        }
        else {
            if(i + 1 == n) good = (pval[i-1] == cur);
            else good = (sval[i+2] == cur && pval[i-1] == cur);
        }
        if(good) return cout << p[i].second + 1 << endl, 0;
    }
    if(sval[2] != INVAL) return cout << p[0].second + 1 << endl, 0;
    if(pval[n-1] != INVAL) return cout << p[n].second + 1 << endl, 0;
    cout << -1 << endl;




}