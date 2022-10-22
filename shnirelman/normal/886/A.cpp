#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n = 6;

    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 1; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[0] + a[i] + a[j] == sum - a[0] - a[i] - a[j]) {
                cout << "YES";
                return 0;
            }

    cout << "NO";
}