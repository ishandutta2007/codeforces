#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }



    vector<int> a(n + 1, -1);
    vector<int> suf(n + 1, 0);
    int cnt = sum / n;
//    int cnt0 = 0;
//    int rg0 = n;
    for(int i = n - 1; i >= 0; i--) {
        if(cnt == 0) {
            for(int j = 0; j <= i; j++)
                a[j] = 0;
            break;
        }

        if(i + 1 == cnt) {
            for(int j = 0; j <= i; j++)
                a[j] = 1;
            break;
        }

//        while(cnt0 >= cnt && rg0 > i) {
//            cnt0 -= (a[rg0] == '0');
//            rg0--;
//        }

        suf[i] = suf[i + 1];


            int l = i, r = n;
            while(r - l > 1) {
                int m = (l + r) / 2;

                if(cnt + suf[i] - suf[m + 1] > m - i)
                    l = m;
                else
                    r = m;
            }


        int c1 = (r - i);
//        cout << i << ' ' << cnt << ' ' << cnt0 << ' ' << rg0 << " c1 = " << c1 << endl;
//        cout << i << ' ' << cnt << ' ' << r << " c1 = " << c1 << endl;


        if(c1 < c[i]) {
            a[i] = 1;
            cnt--;
            suf[i]++;
        } else {
            a[i] = 0;
//            cnt0++;
        }
    }


//    int cnt = sum / n;
//    int rg0 = n;
//    for(int i = n - 1; i >= 0; i--) {
//        int c1 = (rg0 - i - (a[rg0] == 0));
//        if(c1 < c[i]) {
//            a[i] = 1;
//            cnt--;
//            while(rg0 > i && a[i] == 1)
//                i--;
//
//        }
//    }



//    vector<int> add(n, 0);
//    int cur = 0;
//    vector<int> d(n, 0);
//    for(int i = 0; i < n; i++) {
//        if(d[i] < c[i] || a[i] == 1) {
//            a[i] = 1;
//            d[i] += i;
//
//        }
//    }

//    if(c[n - 1] == n) {
//        a[n - 1] = 1;
//        if(c[n - 2] == n - 1) {
//            a[n - 2] = 1;
//        } else {
//
//        }
//    }



//    int rg0 = 0;
//    for(int i = n - 1; i >= 0; i--) {
//        if(c[i] == 0) {
//            break;
//        }
//
//        if(c[i] < )
//    }
//    int cur = 0;
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < c[i]; j++)
//            a[cur++] = 1;
//        a[cur++] = 0;
//    }

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}