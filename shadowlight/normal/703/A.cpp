#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
   int n;
   cin >> n;
   int sum1 = 0, sum2 = 0;
   for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r) sum1++; else if (l < r) sum2++;
   }
   if (sum1 > sum2) {
        cout << "Mishka";
   } else if (sum1 == sum2) {
        cout << "Friendship is magic!^^";
   } else cout << "Chris";
}