#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(2e5 + 14, 1e9);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }

    int mn = 0;
    for(int i = 0; i < b.size(); i++)
        if(b[i] < b[mn])
            mn = i;

    cout << mn << endl;
}