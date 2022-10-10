#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int rx = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
    int ry = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
    long long s = max(rx, ry);
    cout << s*s << endl;
}