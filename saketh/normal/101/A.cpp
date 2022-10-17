#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string str;
int K;

int ct[26];
int ord[26];

bool elim[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> str >> K;

    for (char c : str) ct[c-'a']++;

    for (int i = 0; i < 26; i++)
        ord[i] = i;

    sort(ord, ord + 26, [](int i, int j) { return ct[i] < ct[j]; });

    int D = 26;
    for (int _i = 0; _i < 26; _i++) {
        int i = ord[_i];
        if (ct[i] > K) break;

        D--;
        K -= ct[i];
        elim[i] = true;
    }

    cout << D << "\n";

    for (char c : str) {
        if (elim[c-'a']) continue;
        cout << c;
    }

    cout << "\n";
}