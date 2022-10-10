#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int m = *min_element(v.begin(), v.end());
    int c = 0;
    for(int i = 0; i < n; i++)
        if(v[i] == m) c++;
    if(c > n/2)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}