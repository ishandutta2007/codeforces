#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string str;
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> str;
    for(int i = 0; i < n; i++) {
        if((str[i] - '0') % 2 == 0) {
            res += (i + 1);
        }
    }
    cout << res << endl;
}