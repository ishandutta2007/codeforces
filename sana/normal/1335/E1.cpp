#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int dp[2100][30][30][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; j++) {
            int u; cin >> u;
            arr.push_back(u);
        }

        int bestAnswer = 1;
        
        for (int a = 1; a <= 26; a++) {
            for (int x = 1; x <= n/2; x++) {
                int countAs = 0;
                int leftIndex = n+1, rightIndex = -1;
                for (int j = 0; j < n; j++) {
                    if (arr[j] == a) countAs++;
                    if (countAs == x) {
                        leftIndex = j;
                        break;
                    }
                }

                countAs = 0;
                for (int j = n-1; j >= 0; j--) {
                    if (arr[j] == a) countAs++;
                    if (countAs == x) {
                        rightIndex = j;
                        break;
                    }
                }

                if (rightIndex <= leftIndex) break;

                int bestMiddle = 0;
                map<int, int> c;
                for (int j = leftIndex+1; j < rightIndex; j++) {
                    c[arr[j]]++;
                    if (c[arr[j]] > bestMiddle) bestMiddle = c[arr[j]];
                }

                if (2*x + bestMiddle > bestAnswer) bestAnswer = 2*x + bestMiddle;
            }
        }

        cout << bestAnswer << '\n';
    }
    return 0;
}