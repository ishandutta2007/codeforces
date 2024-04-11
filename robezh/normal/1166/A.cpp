#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string str;
int cnt[256];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        cnt[str[0]] ++;
    }
    int res = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        int one = (cnt[c] / 2);
        int two = cnt[c] - one;
        res += one * (one - 1) / 2 + two * (two - 1) / 2;
    }
    cout << res << endl;
}