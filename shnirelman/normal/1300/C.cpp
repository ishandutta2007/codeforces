#include <bits/stdc++.h>

using namespace std;

void solve() {

}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> p(n + 1, (1ll << 31) - 1), s(n + 1, (1ll << 31) - 1);
    //cout << (((1 << 30) - 1) & 11) << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = p[i] & ~a[i];
        //cout << !a[i] << endl;
        //cout << i << ' ' << p[i + 1] << endl;
    }

    for(int i = n - 1; i >= 0; i--)
        s[i] = s[i + 1] & ~a[i];

    int j = 0, ans = s[1] & a[0];
    for(int i = 0; i < n; i++) {
       // cout << i << ' ' << (p[i] & s[i + 1] & a[i]) << endl;
        if((p[i] & s[i + 1] & a[i]) > ans) {
            ans = (p[i] & s[i + 1] & a[i]);
            j = i;
        }
    }



    cout << a[j] << ' ';
    for(int i = 0; i < n; i++)
        if(i != j)
            cout << a[i] << ' ';
}