#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;

int main() {
   int n, k, q;
   cin >> n >> k >> q;
   set <pair <int, int> > window;
   vector <int> ids(n, 0);
   for (int i = 0; i < n; i++) {
        cin >> ids[i];
   }
   vector <int> in_window(n, 0);
   for (int i = 0; i < q; i++) {
        int it, x;
        cin >> it >> x;
        x--;
        auto v = *window.begin();
        if (it == 1) {
            if (window.size() < k) {
                 window.insert({ids[x], x});
                 in_window[x] = 1;
            } else if (ids[x] > v.first) {
               // cout << v.second << endl;
                window.erase(v);
                in_window[v.second] = 0;
                window.insert({ids[x], x});
                in_window[x] = 1;
            }
        } else {
            if (in_window[x]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
   }
}