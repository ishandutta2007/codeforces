#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::string str;
int add, sub, n;

int main() {
    add = 1;
    char c;
    scanf(" %*c %c", &c);
    while (c != '=') {
        if (c == '+') { add++; str += '+'; }
        else { sub++; str += '-'; }
        scanf(" %*c %c", &c);
    }
    scanf("%d", &n);
    int min = add, max = add*n;
    int minsub = -sub*n, maxsub = -sub;
    if (min + minsub <= n && n <= max + maxsub) {
        printf("Possible\n");
        int toadd = n - minsub, tosub = minsub;
        if (toadd > max) {
            toadd = max;
            tosub = n - toadd;
        }
        assert(toadd + tosub == n);
        std::vector<int> a, s;
        for (int i = 0; i < add; i++) a.pb(toadd / add);
        for (int i = 0; i < toadd % add; i++) a[i]++;
        tosub *= -1;
        for (int i = 0; i < sub; i++) s.pb(tosub / sub);
        if (sub) for (int i = 0; i < tosub % sub; i++) s[i]++;
        int addi = 1, subi = 0;
        printf("%d ", a[0]);
        for (int i = 0; i < sz(str); i++) {
            if (str[i] == '+') printf("+ %d ", a[addi++]);
            else printf("- %d ", s[subi++]);
        }
        printf("= %d\n", n);
    } else {
        printf("Impossible\n");
    }
}