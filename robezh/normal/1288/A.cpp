#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MX = 100000;

int n, d;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> d;
        bool good = false;
        for(int x = 0; x <= MX; x++) {
            if(x + (int)(ceil((double)d / (x + 1))) <= n) good = true;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
}