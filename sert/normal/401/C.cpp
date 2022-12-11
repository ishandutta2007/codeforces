#include <cstdio>
#include <string>
std::string s;
int n, m, n1, m1;
bool q;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 3; i++) {
        s = "";
        n1 = m1 = 0;
        q = false;
        for (int j = 0; j < n + m; j++) {
            if (!q) {
                if ((i + j) % 3 == 0) {
                    n1++;
                    s += '0';
                } else {
                    m1++;
                    s += '1';
                }
                if (n - n1 == m - m1) q = true;
            } else {
                s += (s[j - 1] == '0' ? '1' : '0');
                n1 = n;
                m1 = m;
            }
        }
        if (n1 == n && m1 == m) {
            printf("%s", s.c_str());
            return 0;
        }
    }
    printf("-1\n");
}