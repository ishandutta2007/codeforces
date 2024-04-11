#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int a[N], kol;

void add(char ch) {
    a[ch - 'A']++;
    if (a[ch - 'A'] == 1)
        kol++;
}

void del(char ch) {
    a[ch - 'A']--;
    if (a[ch - 'A'] == 0)
        kol--;
}

string s;
int kk;

int main() {
    //init();
    cin >> s;
    if (s.length() < 26) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < 26; i++)
        if (s[i] == '?') kk++;
        else add(s[i]);

    for (int i = 26; i <= s.length(); i++) {
        //cerr << kol << " " << kk << "\n";
        if (kol + kk == 26) {
            int cur = 0;
            while (a[cur]) cur++;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '?') {
                    if (j >= i || j < i - 26)
                        s[j] = 'S';
                    else {
                        s[j] = char('A' + cur);
                        a[cur] = -1;
                        while (a[cur]) cur++;
                    }
                }
            }
            cout << s << "\n";
            return 0;
        }
        if (i < s.length())
            if (s[i] == '?') kk++; else add(s[i]);
        if (s[i - 26] == '?') kk--; else del(s[i - 26]);
    }


    cout << "-1\n";

    return 0;
}