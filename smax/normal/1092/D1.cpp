#include <bits/stdc++.h>
using namespace std;

int a[200000], b[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] %= 2;
        b[i] = a[i];
    }

//    // Case 1: Make em all odd
//    int suff = INT_MAX;
//    for (int i=1; i<n; i++) {
//        if (a[i] == a[i-1] && a[i] == 1) {
//            a[i] = a[i-1] = 2;
//            suff = min(suff, i-1);
//        }
//        else if (a[i] == 0 && i > 1 && a[i-1] == 1 && a[i-2] == 2) {
//            a[suff] = 1;
//            a[i-1] = 2;
//            suff = INT_MAX;
//        }
//    }
//
//
//    bool can1 = true;
//    int len = 0;
//    for (int i=0; i<n && can1; i++) {
//        if (a[i] % 2 == 0)
//            len++;
//        else {
//            if (len % 2 == 1)
//                can1 = false;
//            len = 0;
//        }
//    }
//    can1 &= (len % 2 == 0);
//
//    // Case 2: Make em all even
//    suff = INT_MAX;
//    for (int i=1; i<n; i++) {
//        if (b[i] == b[i-1] && b[i] == 0) {
//            b[i] = b[i-1] = 3;
//            suff = min(suff, i-1);
//        }
//        else if (b[i] == 1 && i > 1 && b[i-1] == 0 && b[i-2] == 3) {
//            b[suff] = 0;
//            b[i-1] = 3;
//            suff = INT_MAX;
//        }
//    }
//
//    bool can2 = true;
//    len = 0;
//    for (int i=0; i<n && can2; i++) {
//        if (b[i] % 2 == 1)
//            len++;
//        else {
//            if (len % 2 == 1)
//                can2 = false;
//            len = 0;
//        }
//    }
//    can2 &= (len % 2 == 0);

    stack<int> s;
    for (int i=0; i<n; i++) {
        if (!s.empty() && a[i] == s.top())
            s.pop();
        else
            s.push(a[i]);
    }

    cout << (s.size() <= 1 ? "YES\n" : "NO\n");

    return 0;
}