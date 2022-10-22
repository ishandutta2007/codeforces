#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ind(char c) {
    return c - 'a';
}

void solve() {
    int alpha[26] = {0};
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int* a = new int[m];
    for (int i = 0; i < m; i++) { cin >> a[i];}
    sort(a, a + m);

    for (int i = 0; i < n; i++)
        alpha[s[i] - 'a']++;
    for (int i = 0; i < a[0]; i++)
        alpha[s[i] - 'a'] += m;

    for (int i = 0; i < m - 1; i++) {
        for (int j = a[i]; j < a[i + 1]; j++) {
            alpha[s[j] - 'a'] += m - i - 1;
        }
    }


    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << " ";
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
    return 0;
}