#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int c[200];

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
        for (int a = 1; a <= 200; a++) {
            int countAs = 0;
            int leftIndex = -1, rightIndex = n;
            
            while (leftIndex < rightIndex) {
                int nextLeft, nextRight;
                for (nextLeft = leftIndex+1; nextLeft < n; nextLeft++) {
                    if (arr[nextLeft] == a) break;
                }

                for (nextRight = rightIndex-1; nextRight >= 0; nextRight--) {
                    if (arr[nextRight] == a) break;
                }

                if (nextRight <= nextLeft) break;
                leftIndex = nextLeft;
                rightIndex = nextRight;
                countAs++;
            }

            if (countAs == 0) continue;

            vector<int> c(210);
            int bestMiddle = 0;
            for (int j = leftIndex+1; j < rightIndex; j++) {
                c[arr[j]]++;
                if (c[arr[j]] > bestMiddle) bestMiddle = c[arr[j]];
            }

            for (int x = countAs; x >= 1; x--) {
                if (2*x + bestMiddle > bestAnswer) bestAnswer = 2*x + bestMiddle;

                c[arr[leftIndex]]++;
                if (c[arr[leftIndex]] > bestMiddle) bestMiddle = c[arr[leftIndex]];
                leftIndex--;
                while (leftIndex >= 0 && arr[leftIndex] != a) {
                    c[arr[leftIndex]]++;
                    if (c[arr[leftIndex]] > bestMiddle) bestMiddle = c[arr[leftIndex]];
                    leftIndex--;
                }

                c[arr[rightIndex]]++;
                if (c[arr[rightIndex]] > bestMiddle) bestMiddle = c[arr[rightIndex]];
                rightIndex++;
                while (rightIndex < n && arr[rightIndex] != a) {
                    c[arr[rightIndex]]++;
                    if (c[arr[rightIndex]] > bestMiddle) bestMiddle = c[arr[rightIndex]];
                    rightIndex++;
                }
            }
        }

        cout << bestAnswer << '\n';
    }

    return 0;
}