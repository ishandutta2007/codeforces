#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    bool lock = false;
    string col = "blue";
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s[0] == 'u')
            lock = false;
        else if(s[0] == 'l')
            lock = true;
        else if(!lock)
            col = s;
    }

    cout << col << endl;
}