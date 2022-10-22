#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
*/



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);


    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        bool ans = (b >= a);
//        li x = 0;
        int ca = 0, cb = 0;
        for(int j = 0; j < 30; j++) {
            if((1 << j) & a)
                ca++;
            if((1 << j) & b)
                cb++;
            if(cb > ca)
                ans = false;

//            if(((1 << j) & a) != 0 || ((1 << j) & x) != 0) {
//                x += (1 << j);
//            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
}