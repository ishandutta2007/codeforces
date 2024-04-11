#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;

int n, na, nb;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> na >> nb;
        int mx0 = 0, mx1 = 0;
        for(int i = 0; i < na; i++) {
            int x;
            cin >> x;
            mx0 = max(mx0, x);
        }
        for(int i = 0; i < nb; i++) {
            int x;
            cin >> x;
            mx1 = max(mx1, x);
        }
        cout << (mx0 > mx1 ? "YES" : "NO") << '\n';
    }
}