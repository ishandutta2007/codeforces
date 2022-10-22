#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;


void solve() {

}

int main() {
    int n;
    cin >> n;

    vector<int> p;
    vector<int> is(1e6 + 13, -1);

    for(int i = 2; i < is.size(); i++) {

        if(is[i] == -1 && i * 1ll * i < is.size()) {

            for(int j = i * i; j < is.size(); j++)
                if(is[j] == -1)
                    is[j] = i;
        }

        is[i] = i;

        if(is[i])
            p.push_back(i);
    }

    vector<int> a(n + 1, -1);
    int cur = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] != -1)
            continue;
        int d = is[i];
//        cout << i << ' ' << d << endl;
        for(int j = i; j < a.size(); j += d)
            a[j] = cur;
        cur++;
    }

    for(int i = 2; i <= n; i++)
        cout << a[i] << ' ';

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();
}