#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (!(a <= b || a == b + 1 && c == 0 && d == 0) || !(b <= a + c || b == a + c + 1 && d == 0) || !(c <= b + d || c == b + d + 1 && a == 0) || !(d <= c || d == c + 1 && a == 0 && b == 0)) {
        cout << "NO\n";
        return 0;
    }

    int n = a + b + c + d;
    for (int i=0; i<4; i++) {
        int x = i, cnt[4] = {a, b, c, d};
        vector<int> ret;
        while (cnt[x] > 0) {
            ret.push_back(x);
            cnt[x]--;
            if (x == 0)
                x++;
            else if (x == 1) {
                if (cnt[0] > 0) x--;
                else x++;
            } else if (x == 2) {
                if (cnt[3] > 0) x++;
                else x--;
            } else
                x--;
        }
        if (ret.size() == n) {
            cout << "YES\n";
            for (int i : ret)
                cout << i << " ";
            cout << "\n";
            return 0;
        }
    }

//    vector<int> ret;
//    while (a > 0) {
//        ret.push_back(0);
//        a--;
//        if (b == 0)
//            break;
//        ret.push_back(1);
//        b--;
//    }
//    bool endOnTwo = false;
//    while (c > 0) {
//        ret.push_back(2);
//        c--;
//        endOnTwo = true;
//        if (b == 0)
//            break;
//        ret.push_back(1);
//        b--;
//        endOnTwo = false;
//    }
//    if (endOnTwo)
//        while (d > 0) {
//            ret.push_back(3);
//            d--;
//            if (c == 0)
//                break;
//            ret.push_back(2);
//            c--;
//        }
//    if (ret.size() == n) {
//        cout << "YES\n";
//        for (int i : ret)
//            cout << i << " ";
//        cout << "\n";
//        return 0;
//    }
//
//    ret.clear();
//    a = oa, b = ob, c = oc, d = od;
//    while (b > 0) {
//        ret.push_back(1);
//        b--;
//        if (a == 0)
//            break;
//        ret.push_back(0);
//        a--;
//    }
//    endOnTwo = false;
//    while (c > 0) {
//        ret.push_back(2);
//        c--;
//        endOnTwo = true;
//        if (b == 0)
//            break;
//        ret.push_back(1);
//        b--;
//        endOnTwo = false;
//    }
//    if (endOnTwo)
//        while (d > 0) {
//            ret.push_back(3);
//            d--;
//            if (c == 0)
//                break;
//            ret.push_back(2);
//            c--;
//        }
//    if (ret.size() == n) {
//        cout << "YES\n";
//        for (int i : ret)
//            cout << i << " ";
//        cout << "\n";
//        return 0;
//    }

    cout << "NO\n";

    return 0;
}