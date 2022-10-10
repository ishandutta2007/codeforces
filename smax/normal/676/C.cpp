#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int aSum = 0, bSum = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'a') {
            aSum++;
            b.push_back(bSum);
            bSum = 0;
        } else {
            bSum++;
            a.push_back(aSum);
            aSum = 0;
        }
    }
    a.push_back(aSum);
    b.push_back(bSum);

    int aWindow = 0, bWindow = 0;
    for (int i=0; i<=k; i++) {
        if (i < a.size())
            aWindow += a[i] + (i > 0);
        if (i < b.size())
            bWindow += b[i] + (i > 0);
    }
    int aMax = aWindow, bMax = bWindow;
    for (int j=k+1; j<a.size(); j++) {
        aWindow += a[j] - a[j-k-1];
        aMax = max(aMax, aWindow);
    }
    for (int j=k+1; j<b.size(); j++) {
        bWindow += b[j] - b[j-k-1];
        bMax = max(bMax, bWindow);
    }

    cout << max(aMax, bMax) << "\n";

    return 0;
}