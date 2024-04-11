#include <bits/stdc++.h>
using namespace std;

const int N = 50005;

int c2[N];
int cnt[N];

int main() {
    for(int i = 1; i < N; i++) c2[i] = (int)(1LL * i * (i - 1) / 2);
    int T;
    cin >> T;
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        for(int i = N - 1; i >= 2; i--) {
//            cout << n << " " << c2[i] << endl;
            int tk = n / c2[i];
            cnt[i] += tk;
            n -= tk * c2[i];
        }
        cout << 1;
        for(int i = 1; i < N; i++) {
            cout << 3;
            for(int j = 0; j < cnt[i]; j++) cout << 7;
        }
        cout << "\n";
    }

}