#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
int ans;

void askA(int x) {
    cout << "A " << x << endl;
    cin >> ans;
}

void askB(int x) {
    cout << "B " << x << endl;
    cin >> ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "C 1" << endl;
        exit(0);
    }
    vector<int> P = {-1}, Q;
    vector<bool> sieve(n + 1, true);
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) {
            if (x * x <= n) {
                Q.pb(x);
            } else {
                P.pb(x);
            }
            for (int y = x; y <= n; y += x) sieve[y] = false;
        }
    }
    int doljno = n;
    vector<bool> used(n + 1, false);
    int avg = (int) floor(sqrt(P.size())) + 1;
    int answer = 1;
    for (int i = 1; i < P.size(); i++) {
        if (i % avg == 0) {
            askA(1);
            if (doljno != ans) {
                for (int j = max(1LL, i - avg); j < i; j++) {
                    askA(P[j]);
                    if (ans == 1) {
                        answer *= P[j];
                        break;
                    }
                }
                break;
            }
        }
        askB(P[i]);
        for (int x = P[i]; x <= n; x += P[i]) {
            if (!used[x]) doljno--;
            used[x] = true;
        }
    }
    if (answer == 1) {
        askA(1);
        int i = (int) P.size();
        if (doljno != ans) {
            for (int j = max(1LL, i - avg); j < i; j++) {
                askA(P[j]);
                if (ans == 1) {
                    answer *= P[j];
                    break;
                }
            }
        }
    }
    for (auto meloc : Q) {
        int m = meloc;
        askB(m);
        askA(m);
        while (ans) {
            m *= meloc;
            if (m <= n) {
                askA(m);
            } else {
                ans = 0;
            }
        }
        m /= meloc;
        answer *= m;
    }
    cout << "C " << answer << endl;
}