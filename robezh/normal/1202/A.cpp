#include <bits/stdc++.h>
using namespace std;

int n;
string A, B;

int solve() {
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int firB = -1;
    for(int i = 0; i < B.length(); i++) {
        if(B[i] == '1') {
            firB = i;
            break;
        }
    }
    if(firB == -1) return 0;
    for(int i = firB; i < A.length(); i++) {
        if(A[i] == '1') {
            return i - firB;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << "\n";

    }
}