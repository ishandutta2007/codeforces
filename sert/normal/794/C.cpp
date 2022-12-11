#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1000034;
string s, k;
char ss[N];
string res;

int main()
{
    //freopen("a.in", "r", stdin);
    gets(ss); s = ss;
    gets(ss); k = ss;
    res = s;
    sort(s.begin(), s.end());
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());
    int n = res.length();
    for (int i = n - n / 2; i < n; i++) s.pop_back();
    for (int i = n / 2; i < n; i++) k.pop_back();

    int cs = 0, ck = 0, cb = 0, ce = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[cs] < k[ck]) res[cb++] = s[cs++];
            else {
                res[ce--] = s.back();
                s.pop_back();
            }
        } else {
            if (k[ck] > s[cs]) res[cb++] = k[ck++];
            else {
                res[ce--] = k.back();
                k.pop_back();
            }
        }
    }

    cout << res;

    return 0;
}