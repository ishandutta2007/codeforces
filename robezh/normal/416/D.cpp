#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, INF = (int)1e9 + 7;

int n;
int a[N];

int mod(int x, int y) {
    return (x % y + y) % y;
}

int dvd(int x, int y) {
    return (x - mod(x, y)) / y;
}

bool lar(int a, int b, int c) {
    return a >= dvd(c + b - 1, b);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int r = 0, res = 0;
    for(int i = 0; i < n; i = r) {
        res++;
        int fir = -1, d = INF;
        while(r < n) {
            if(a[r] != -1) {
                if(fir == -1) fir = r;
                else {
                    if((a[r] - a[fir]) % (r - fir) != 0) break;
                    int di = (a[r] - a[fir]) / (r - fir);
                    if(d != INF && d != di) break;
                    d = di;
                }
                if(d != INF && lar(d, r - i, a[r])) {
                    break;
                }
            } else {
                if(d != INF && !lar(d, r - fir, -a[fir] + 1)) break;

            }
            r++;
        }
    }
    cout << res << endl;
}