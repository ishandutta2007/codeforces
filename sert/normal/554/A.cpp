#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

string s, k;
set <string> ss;
int n;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s;
    n = s.length();
    for (int i = -1; i < n; i++)
    for (char ch = 'a'; ch <= 'z'; ch++) {
        k.clear();
        if (i == -1)
            k += ch;
        for (int j = 0; j < n; j++) {
            k += s[j];
            if (j == i)
                k += ch;
        }
        ss.insert(k);
    }

    cout << ss.size();

    return 0;
}