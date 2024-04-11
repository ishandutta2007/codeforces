#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;
typedef long long ll;

int n;
string str;
int rmn[N];

int main() {
//    cin >> n;
    cin >> str;
    n = str.length();
    rmn[n] = n;
    ll res = 0;
    for(int i = n - 1; i >= 0; i--) {
        rmn[i] = rmn[i+1];
        for(int j = i + 2; j <= i + 10 && j < n; j += 2) {
            int md = (i + j) / 2;
            if(str[i] == str[md] && str[md] == str[j]) rmn[i] = min(rmn[i], j);
        }
        res += n - rmn[i];
    }
    cout << res << endl;
}