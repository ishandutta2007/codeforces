#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <pair <int, int> > data(n);
    int sumL = 0, sumR = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
        sumL += data[i].first;
        sumR += data[i].second;
    }
    int mink = abs(sumL - sumR);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = sumL - data[i].first + data[i].second;
        int b = sumR - data[i].second + data[i].first;
        if (mink < abs(a - b)) {
            mink = abs(a - b);
            ans = i + 1;
        }
    }
    cout << ans;
}