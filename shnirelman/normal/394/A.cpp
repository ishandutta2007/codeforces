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

int main() {
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;
    int i = 0;
    for(i = 0; i < s.size(); i++) {
        if(s[i] == '+')
            break;
        a++;
    }

    i++;
    for(; i < s.size(); i++) {
        if(s[i] == '=')
            break;
        b++;
    }

    c = s.size() - a - b - 2;

    if(a + b == c) {
        cout << s << endl;
        return 0;
    }

    bool res = true;
    if(c < a + b) {
        if(a + b - 1 == c + 1) {
            c++;
            if(a > 1)
                a--;
            else if(b > 1)
                b--;
            else
                res = false;
        } else
            res = false;
    } else {
        if(a + b + 1 == c - 1) {
            c--;
            a++;
        } else
            res = false;
    }

    if(!res) {
        cout << "Impossible" << endl;
        return 0;
    }

    for(int i = 0; i < a; i++)
        cout << '|';
    cout << '+';
    for(int i = 0; i < b; i++)
        cout << '|';
     cout << '=';
    for(int i = 0; i < c; i++)
        cout << '|';
}