//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 16 * 16;

mt19937 rnd(0);


int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;

//    vector<int> a;
//    for(int i = 1; i * i <= n; i++) {
//        if(n % i == 0) {
//            a.push_back(i);
//            if(i * i != n)
//                a.push_back(n / i);
//        }
//    }
//
//    for(int i = 0; i < a.size(); i++) {
//        for(int j = i + 1; j < a.size(); j++) {
//            for(int k = j + 1; k < a.size(); k++) {
//                li x = a[i], y = a[j], z = a[k];
//
//                li p = n * (x * y + x * z + y * z);
//                li q = 2 * x * y * z;
//
//                if(p % q == 0) {
//                    cout << p / q * x << ' ' << p / q * y << ' ' << p / q * z << endl;
//                    return 0;
//                }
//            }
//        }
//    }
//
//    cout << -1 << endl;
}