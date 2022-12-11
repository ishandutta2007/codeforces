#include <bits/stdc++.h>

using namespace std;

void solve() {
    static char s[1000010];
    int n, m; scanf("%d %d", &n, &m);
    scanf("%s", s);
    vector<int> goodRows(n*m), goodCols(n*m);

    int lastSerious = -1e7;
    vector<int> goodInRowLead(n*m);
    for (int i = 0; i < n * m; ++i) {
        if (s[i] == '1') lastSerious = i;
        goodInRowLead[i] = (lastSerious > i - m);
    }
    for (int i = 0; i < n * m; ++i) goodRows[i] = goodInRowLead[i] + (i < m ? 0 : goodRows[i-m]);

    vector<int> goodInColLead(n*m);
    for (int i = 0; i < n*m; ++i) {
        if (s[i] == '1' || (i >= m && goodInColLead[i-m] == 1)) goodInColLead[i] = 1;
    }
    for (int i = 1; i < n * m; ++i) goodInColLead[i] += goodInColLead[i-1];

    for (int i = 0; i < n * m; ++i) goodCols[i] = goodInColLead[i] - (i >= m ? goodInColLead[i-m] : 0);
    for (int i = 0; i < n * m; ++i) printf("%d ", goodRows[i] + goodCols[i]);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}