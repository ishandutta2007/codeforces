#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    li ans = 0;
    map<int, int> mp1;
    map<pii, int> mp2;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;


        if(a != b) {
            ans += mp1[a];
            ans += mp1[b];
            ans -= mp2[{a, b}];
            ans -= mp2[{b, a}];

            mp1[a]++;
            mp1[b]++;
            mp2[{a, b}]++;
        } else {
            ans += mp1[a];
            mp1[a]++;
            mp2[{a, a}]++;
        }
    }

    cout << ans << endl;
}