#include <iostream>

using namespace std;

long long get(long long n) {
    long long r = 1;
    while (n > 1 && n % 2 == 0) {
        r *= 2;
        n /= 2;
    }
    return r;
}

int main(){
    int t; cin >> t;
    while (t--) {
        int w, h, n;
        cin >> w >> h >> n;
        long long c = get(w) * get(h);
        cout << ((c >= n) ? "YES" : "NO") << "\n";
    }

    return 0;
}