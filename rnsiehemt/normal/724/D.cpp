#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n, m;
char s[maxn];
std::string t;

int main() {
    scanf("%d %s", &m, s);
    n = strlen(s);
    for (char c = 'a'; c <= 'z'; c++) {
        bool works = true;
        {
            int last = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] <= c) last = i;
                if (i-last >= m) {
                    works = false;
                    break;
                }
            }
        }
        if (works) {
            int last = -1, choose = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == c) choose = i;
                if (s[i] < c) last = i;
                if (i-last >= m) {
                    t += c;
                    last = choose;
                }
            }
            break;
        } else {
            for (int i = 0; i < n; i++) if (s[i] == c) t += c;
        }
    }
    printf("%s\n", t.c_str());
}