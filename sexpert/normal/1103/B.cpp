#include <bits/stdc++.h>
using namespace std;

int qn;

char query(int x, int y) {
    cout << "? " << x << " " << y << '\n';
    cout.flush();
    char c;
    cin >> c;
    if(c == 'e')
        exit(0);
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(true) {
        qn = 0;
        cin >> s;
        if(s != "start")
            return 0;
        char r = query(0, 1);
        qn++;
        if(r == 'x') {
            cout << "! 1\n";
            cout.flush();
            continue;
        }
        int p = 2, lbnd, hbnd;
        while(true) {
            char q = query(p, p/2);
            qn++;
            if(q == 'y') {
                hbnd = p;
                lbnd = p/2 + 1;
                break;
            } // 2^k mod a < 2^(k - 1) mod a gives a <= 2^k and we know a > 2^(k - 1)
            p <<= 1;
        }
        int t = lbnd - 1; // always < a so gives t
        // find smallest x with x mod a < t mod a 
        while(lbnd < hbnd) {
            int mi = (lbnd + hbnd)/2;
            char q = query(mi, t);
            qn++;
            if(q == 'y')
                hbnd = mi;
            else
                lbnd = mi + 1;
        }
        cout << "! " << lbnd << '\n';
        cout.flush();
    }
}