#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n;
int a[N];
vector<int> num;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) num.push_back(-a[i]);
        else if(a[i] > 0) num.push_back(a[i]);
    }
    sort(num.begin(), num.end());
    ll res = 0;
    for(int x : num) {
        res += upper_bound(num.begin(), num.end(), 2 * x) - lower_bound(num.begin(), num.end(), x);
    }
    for(int i = 0; i < num.size(); i++) {
        res --;
        if(i + 1 < num.size() && num[i+1] == num[i]) res --;
    }
    cout << res << endl;
}