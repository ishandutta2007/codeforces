#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;
typedef long long ll;
// Z-algorithm
//
// Examples:
// str = "aabaacd"
// z[] = {x, 1, 0, 2, 1, 0, 0}

//str = "abababab"
//z[] = {x, 0, 6, 0, 4, 0, 2, 0}

string str;
int n, k;
int z[N];

void getZarr(string str)
{
    memset(z, 0, sizeof(z));
    int n = str.length();
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
}

int in[N], res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> str;

    getZarr(str);
    if(k == 1) {
        for(int i = 0; i < n; i++) cout << 1;
        return 0;
    }
    for(int i = 1; i < n; i++) {
        ll l = 1LL * i * k - 1, r = 1LL * i * (k + 1) - 1;
        l = min(l, 1LL * n), r = min(r, 1LL * n-1);
        r = min(r, 1LL * i + z[i] - 1);
//        cout << i << ": " << l << ", " << r << endl;
        if(l <= r) in[l]++, in[r+1]--;
    }
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += in[i];
        res[i] = cur > 0;
    }
    for(int i = 0; i < n; i++) cout << res[i];

    return 0;
}