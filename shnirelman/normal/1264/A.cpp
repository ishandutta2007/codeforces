#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void no() {
    cout << "0 0 0" << endl;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
//cout << "s" << endl;
    int cnt1 = 0;
    while(cnt1 < n && a[cnt1] == a[0])
        cnt1++;

    if(cnt1 > n / 2) {
        no();
        return;
    }

//cout << "s" << endl;
    int cnt2 = 0;
    int j = cnt1;
    while(cnt2 <= cnt1) {
        j = cnt1 + cnt2;
        int x = 0;
        while(j + x < n && a[j] == a[j + x])
            x++;

        cnt2 += x;

        if(cnt2 + cnt1 == n) {
            no();
            return;
        }
    }


    if(cnt1 + cnt2 > n / 2) {
        no();
        return;
    }



//        cout << "s" << endl;

    int cnt3 = 0;
    while(true) {
        int x = 0;
        j = cnt1 + cnt2 + cnt3;
//        cout << cnt1 + cnt2 + cnt3 << endl;
        while(j + x < n && a[j] == a[j + x])
            x++;
//        cout << x << endl;

        if(n / 2 >= cnt1 + cnt2 + cnt3 + x)
            cnt3 += x;
        else
            break;
    }

    if(cnt3 <= cnt1) {
        no();
        return;
    }


    cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    for(int i = 0; i < n; i++)
//        cin >> a[i];





    int t;
    cin >> t;
    while(t--)
        solve();
}