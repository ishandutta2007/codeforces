#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> res;
    while(n >= 25) {
        n -= 7;
        res.push_back(7);
    }
    if(n == 1 || n == 2 || n == 3 || n == 5 || n == 6 || n == 9 || n == 10 || n == 13 || n == 17) {
        cout << "-1\n";
        return 0;
    }
    int x = -1, y = -1, mn = 100;
    for(int a = 0; a < 100; a++) {
        for(int b = 0; b < 100; b++) {
            if(4*a + 7*b != n)
                continue;
            if(a + b < mn || (a + b == mn && a > x)) {
                x = a;
                y = b;
                mn = a + b;
            }
        }
    }
    while(x--)
        res.push_back(4);
    while(y--)
        res.push_back(7);
    sort(res.begin(), res.end());
    for(auto x : res)
        cout << x;
    cout << '\n';
}