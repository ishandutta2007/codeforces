#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

ll res = 0;
int n;
ll psum[N], ssum[N];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    n = str.length();
    str = " " + str;
    for(int i = 2; i <= n; i++) {
        psum[i] = psum[i-1] + (str[i] == 'v' && str[i-1] == 'v');
    }
    for(int i = n - 1; i >= 1; i--) {
        ssum[i] = ssum[i+1] + (str[i] == 'v' && str[i+1] == 'v');
    }
    for(int i = 2; i <= n - 1; i++) {
        if(str[i] == 'o') res += psum[i-1] * ssum[i+1];
    }
    cout << res << endl;

}