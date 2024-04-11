#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;

int main() {
   int n, d, h, last;
   cin >> n >> d >> h;
   if (d > 2 * h) {
        cout << -1 << endl;
        return 0;
   }
   if (d == h && h == 1 && n > 2) {
        cout << -1;
        return 0;
   }
   vector <pair <int, int> > ans;
   int now = 2;
   if (d == h && n - 1 > d) {
        for (int i = 0; i < h; i++) {
            ans.push_back({now - 1, now});
            now++;
        }
        for (int i = now; i <= n; i++) {
            ans.push_back({now - 2, i});
        }
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
        return 0;
   }
   for (int i = 0; i < h; i++) {
        ans.push_back({now - 1, now});
        now++;
   }
   if (now <= n) {
        ans.push_back({1, now});
        now++;
        last = 1;
   }
   for (int j = 1; j <= d - h - 1; j++) {
        ans.push_back({now - 1, now});
        last = now - 1;
        now++;
   }
   for (int i = now; i <= n; i++) {
        ans.push_back({last, i});
   }
   for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
   }
}