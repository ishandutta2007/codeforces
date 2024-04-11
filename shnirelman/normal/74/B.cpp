#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    a--;
    b--;

    string s;
    cin >> s;
    cin >> s;

    bool d = (s == "tail");

    string t;
    cin >> t;

    for(int i = 0; i < t.size(); i++) {
        if(t[i] == '0') {
            if(a < b) {
                if(a > 0)
                    a--;
            } else {
                if(a < n - 1)
                    a++;
            }
        }

        if(b == 0)
            d = 1;
        else if(b == n - 1)
            d = 0;

        if(d)
            b++;
        else
            b--;

        if(t[i] == '1') {
            a = (d ? 0 : n - 1);
        }

//        cout << a << ' ' << b << endl;

        if(a == b) {
            cout << "Controller " << i + 1 << endl;
            return 0;
        }
    }

    cout << "Stowaway" << endl;
}