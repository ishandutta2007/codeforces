#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;
int f[10];
int r[10];

void solve() {
    for (char c : s) {
        int d = c - '0';
        if (d == 4) {
            r[3]++; r[2]+=2;
        } else if (d == 8) {
            r[7]++; r[2]+=3;
        } else if (d == 6) {
            r[3]++; r[5]++;
        } else if (d == 9) {
            r[7]++; r[3]+=2; r[2]++;
        } else {
            r[d]++;
        }
        // cout << d << " " << r[7] << endl;
    }
    for (int d = 9; d > 1; d--)
        while (r[d]--) cout << d;
    cout<<endl;
}

int main() {
    setIO();
    cin>>n>>s;
    solve();
    
    return 0;
}