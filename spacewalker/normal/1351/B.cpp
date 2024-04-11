#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
        vector<int> arr{a, b, c, d};
        sort(begin(arr), end(arr));
        if (arr[2] == arr[3] && arr[0] + arr[1] == arr[2] && 
            ((a == c) || (a == d) || (b == c) || (b == d))) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}