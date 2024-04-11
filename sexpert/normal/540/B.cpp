#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, p, x, y, sum = 0, q = 0;
    cin >> n >> k >> p >> x >> y;
    vector<int> v(k);
    for(auto &t : v) {
        cin >> t;
        sum += t;
        if(t >= y)
            q++;
    }
    vector<int> ans;
    if(q + n - k < (n + 1)/2) {
        cout << "-1\n";
        return 0;
    }
    while(q < (n + 1)/2) {
        ans.push_back(y);
        sum += y;
        k++;
        q++;
    }
    while(k < n) {
        ans.push_back(1);
        k++;
        sum++;
    }
    if(sum > x) {
        cout << "-1\n";
    }
    else {
        for(auto t : ans)
            cout << t << " ";
        cout << endl;
    }
}