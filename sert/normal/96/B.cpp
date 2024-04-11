#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

string s, k;
int p, a4, a7;

bool cmp(string a, string b) {
    return (a.length() != b.length() ? a.length() < b.length() : a < b);
}

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> s;
    k = "47";

    while (true) {
        ///cerr << k << "\n";
        a4 = a7 = 0;
        for (int i = 0; i < k.length(); i++)
            if (k[i] == '4') a4++;
            else a7++;
        if (a4 == a7 && !cmp(k, s)) {
            cout << k << "\n";
            return 0;
        }
        p = k.length() - 1;
        while (k[p] == '7') {
            p--;
            if (p == -1)
                break;
        }
        for (int i = p + 1; i < k.length(); i++)
            k[i] = '4';
        if (p == -1)
            k = "4" + k;
        else
            k[p] = '7';
    }

    return 0;
}