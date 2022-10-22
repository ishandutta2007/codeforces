#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        li a;
        cin >> a;

        if(a > 14 && a % 14 > 0 && a % 14 < 7)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}