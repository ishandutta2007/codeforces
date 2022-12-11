//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

bool le(string s1, string s2) {
    if (s1 == s2) return false;
    if (s2.find(s1) == 0) return false;
    if (s1.find(s2) == 0) return true;
    return s1 < s2;
}

int Len(int x) {
    int res = 0;
    while (x > 0) {
        res++;
        x /= 10;
    }
    return res;
}

int k[12];
char ss[N], ch;
string s, st, tmp;
int n, m, p, r, t;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    gets(ss);
    s = ss;

    if (s == "10" || s == "01") {
        cout << "0";
        return 0;
    }

    n = s.length();

    for (int i = 0; i < n; i++)
        k[s[i] - '0']++;

    for (int i = max(1, n - 10); i <= n; i++) {
        if (i + Len(i) == n) {
            t = i;
            break;
        }
    }
    n = t;
    while (t > 0) {
        k[t % 10]--;
        t /= 10;
    }

    gets(ss);
    st = ss;
    for (int i = 0; i < (int)st.length(); i++)
        k[st[i] - '0']--;
    bool les = false;
    for (int i = 1; i < (int)st.length(); i++) {
        if (st[i - 1] > st[i])
            les = true;
        if (st[i - 1] < st[i])
            break;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < k[i]; j++)
            tmp += char('0' + i);
    }

    if (tmp.length() == 0) {
        cout << st;
        return 0;
    }

    int cur = 0;
    while (cur < tmp.length() && tmp[cur] == '0')
        cur++;
    if (cur < tmp.length())
        swap(tmp[0], tmp[cur]);

    bool used = false;
    k[10] = 3;

    if ((tmp[0] != '0' && le(tmp, st)) || st[0] == '0') {
        cur = tmp[0] - '0';
        k[cur]--;
        printf("%c", char('0' + cur));
    } else {
        printf("%s", st.c_str());
        used = true;
    }

    cur = 0;
    while (k[cur] == 0)
        cur++;

    while (cur < 10 || !used) {
        if (char('0' + cur - !les) < st[0] || used) {
            k[cur]--;
            printf("%c", char('0' + cur));
            while (k[cur] == 0)
                cur++;
        } else {
            printf("%s", st.c_str());
            used = true;
        }
    }



    return 0;
}