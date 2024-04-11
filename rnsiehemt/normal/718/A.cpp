#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, t;
char s[maxn];

int main() {
    scanf("%d%d %s", &n, &t, s);
    int i = 0;
    while (s[i] != '.') i++;
    i++;
    while (s[i] && s[i] < '5') i++;
    if (s[i]) {
        bool special = false;
        while (t && s[i] >= '5') {
            t--;
            if (s[i-1] == '.') {
                s[i-1] = '\0';
                i -= 2;
                special = true;
                break;
            } else {
                s[i] = '\0';
                s[i-1]++;
                i--;
            }
        }
        if (special) {
            int aoeu = strlen(s);
            while (i >= 0 && s[i] == '9') i--;
            if (i < 0) {
                printf("1");
                for (int j = 0; j < aoeu; j++) printf("0");
                printf("\n");
                return 0;
            } else {
                s[i]++;
                for (int j = i+1; j < aoeu; j++) s[j] = '0';
            }
        }
    }
    printf("%s\n", s);
}