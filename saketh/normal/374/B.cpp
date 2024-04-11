#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string str;

bool match(char a, char b) {
    return (a - '0') + (b - '0') == 9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> str;

    ll res = 1;

    for (int i = 0; i < str.size();) {
        int j = i;

        while (j + 1 < str.size() && match(str[j], str[j+1]))
            j++;

        if (j > i) {
            if ((j - i) % 2 == 0) res *= (j - i + 2) / 2;
        }
        
        i = j + 1;
    }

    cout << res << "\n";
}