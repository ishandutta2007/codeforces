//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    li p;
    int k;
    cin >> p >> k;

    vector<int> a;
    int i = 0;
    while(p > 0) {
        int r = p % k;

        if(i % 2 == 0) {
            a.push_back(r);
            p /= k;
        } else {
            a.push_back((k - r) % k);
            p = (p + a.back()) / k;
        }

        i++;
    }

    cout << a.size() << endl;
    for(auto x : a)
        cout << x << ' ';
}