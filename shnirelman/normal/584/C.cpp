#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 20;
const int A = 27;

char other(char a, char b) {
    return (a != 'a' && b != 'a' ? 'a' :
            a != 'b' && b != 'b' ? 'b' : 'c');
}

char other(char a) {
    return other(a, a);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, t;
    cin >> n >> t;

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        if(s1[i] == s2[i])
            a.push_back(i);
        else
            b.push_back(i);
    }

    string res(n, '0');

    if(b.size() % 2 == 1) {
        res[b.back()] = other(s1[b.back()], s2[b.back()]);
        b.pop_back();
        t--;
    }

//    cout << t * 2 << ' ' << b.size() << endl;
//assert(t * 2 < b.size());
    if(t * 2 < int(b.size())) {

        cout << -1 << endl;
        return 0;
    }

    if(t < int(b.size())) {
        int x = b.size() - t;
//        cout << x << endl;
        for(int i = 0; i < x * 2; i += 2) {
            res[b[i]] = s1[b[i]];
            res[b[i + 1]] = s2[b[i + 1]];
        }

        for(int i = x * 2; i < b.size(); i++) {
            res[b[i]] = other(s1[b[i]], s2[b[i]]);
        }

        for(int i = 0; i < a.size(); i++)
            res[a[i]] = s1[a[i]];

        cout << res << endl;
    } else {
        for(int i = 0; i < b.size(); i++) {
            res[b[i]] = other(s1[b[i]], s2[b[i]]);
            t--;
        }

        for(int i = 0; i < a.size(); i++) {
            if(t > 0) {
                res[a[i]] = other(s1[a[i]]);
                t--;
            } else
                res[a[i]] = s1[a[i]];
        }

        cout << res << endl;
    }
}