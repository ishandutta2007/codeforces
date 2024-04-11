#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<int> cO(3), cX(3);
    int n, k;
    k = 0;
    cin >> n;
    vector<string> gr(n);
    for(auto &s : gr) {
        cin >> s;
        for(auto &c : s)
            if(c != '.')
                k++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(gr[i][j] == 'O')
                cO[(i + j) % 3]++;
            if(gr[i][j] == 'X')
                cX[(i + j) % 3]++;
        }
    }
    int toO, toX;
    if(cO[0] + cX[1] <= k/3) {
        toX = 0;
        toO = 1;
    }
    if(cO[1] + cX[2] <= k/3) {
        toX = 1;
        toO = 2;
    }
    if(cO[2] + cX[0] <= k/3) {
        toX = 2;
        toO = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) % 3 == toX && gr[i][j] != '.')
                gr[i][j] = 'X';
            if((i + j) % 3 == toO && gr[i][j] != '.')
                gr[i][j] = 'O';
            cout << gr[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}