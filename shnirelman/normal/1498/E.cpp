#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 43;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, pii>> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] < a[j])
                b.emplace_back(a[j] - a[i], make_pair(j, i));
            else
                b.emplace_back(a[i] - a[j], make_pair(i, j));
        }
    }

    sort(b.rbegin(), b.rend());



//    bool fl = true;
//    while(fl) {
//        fl = false;
//        int x = -1;
//        for(int i = 0; i < n; i++) {
//            if(a[i] == 0) {
//                x = i;
//                fl = true;
//                break;
//            }
//        }
//
//        if(x != -1)
//            for(int i = 0; i < n; i++)
//                a[i]--;
//    }

    for(auto p : b) {
        cout << "? " << p.s.f + 1 << ' ' << p.s.s + 1 << endl;
        string s;
        cin >> s;

        if(s[0] == 'Y') {
            cout << "! " << p.s.f + 1 << ' ' << p.s.s + 1 << endl;
            return 0;
        }
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < i; j++) {
//            cout << "? " << a[i].s + 1 << ' ' << a[j].s + 1 << endl;
//            string s;
//            cin >> s;
//
//            if(s[0] == 'Y') {
//                cout << "! " << a[i].s + 1 << ' ' << a[j].s + 1 << endl;
//                return 0;
//            }
//        }
//    }

    cout << "! 0 0" << endl;
}