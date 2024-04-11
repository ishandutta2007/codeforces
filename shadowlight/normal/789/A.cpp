#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        cnt += (w + k - 1) / k;
    }
    cout << (cnt + 1) / 2;

}