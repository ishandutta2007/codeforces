#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k;
string vow = "aeiou";
vector<vector<int> > res;

void print(int n, int m) {
    res.resize(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        if(i == 0) res[i][0] = 0;
        else res[i][0] = (res[i-1][0] + 1) % 5;
        for(int j = 1; j < m; j++) res[i][j] = (res[i][j-1] + 1) % 5;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << vow[res[i][j]];
    }
}


int main() {
    cin >> k;
    for(int n = 5; n * n <= k; n++) {
        if(k % n == 0 && k / n >= 5) {
            print(n, k / n);
            return 0;
        }
    }
    cout << "-1" << endl;
}