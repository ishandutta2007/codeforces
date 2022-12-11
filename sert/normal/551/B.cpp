#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

string s1, s2, s3;
char ss[N];
int a[30], b[30], c[30], d[30];
int bst, cur, kol, k1, k2;
int la, lb, lc;
bool fail;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%s", ss); s1 = ss;
    for (int i = 0; i < s1.length(); i++) a[s1[i] - 'a']++;
    scanf("%s", ss); s2 = ss;
    for (int i = 0; i < s2.length(); i++) b[s2[i] - 'a']++;
    scanf("%s", ss); s3 = ss;
    for (int i = 0; i < s3.length(); i++) c[s3[i] - 'a']++;

    la = s1.length();lb = s2.length();lc=s3.length();

    for (int i = 0; i <= la / lb; i++) {
        fail = false;
        kol = 100100;
        for (int j = 0; !fail && j < 26; j++) {
            if (a[j] < i * b[j]) {
                kol = -3400000;
                fail = true;
                continue;
            }
            kol = min(kol, (c[j] ? (a[j] - i * b[j]) / c[j] : 100500));
        }
        if (kol + i > bst) {
            bst = kol + i;
            k1 = i;
            k2 = kol;
        }
    }

    for (int i = 0; i < k1; i++)
        printf("%s", s2.c_str());
    for (int i = 0; i < k2; i++)
        printf("%s", s3.c_str());
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < a[i] - b[i] * k1 - c[i] * k2; j++)
            printf("%c", char('a' + i));

    return 0;
}