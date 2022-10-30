#include <bits/stdc++.h>

char c[] = "CODEFORCES";

int main()
{
    int N = strlen(c);
    std::string s;
    std::cin >> s;
    int M = (int)s.size();
    if (M >= N) {
        for (int i = 0; i <= N; i++) {
            bool yes = true;
            for (int k = 0; k < i; k++) if (s[k] != c[k]) yes = false;
            for (int k = i; k < N; k++) if (s[k+M-N] != c[k]) yes = false;
            if (yes) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
}