#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 20 + 1;
const int A = 26;


/*

*/

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(4, 0);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A')
            a[0]++;
        else if(s[i] == 'C')
            a[1]++;
        else if(s[i] == 'G')
            a[2]++;
        else
            a[3]++;
    }

    sort(a.begin(), a.end());
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i] == a[3])
            cnt++;

    cout << pow2(cnt, n);
}