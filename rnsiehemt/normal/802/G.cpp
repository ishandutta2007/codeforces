#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
typedef long long ll;

char s[] = "heidi", t[12345];
int n = 5, m;

int main() {
    scanf("%s", t);
    m = strlen(t);
    int j = 0;
    fo(i,0,m) {
        if (t[i] == s[j]) j++;
        if (j == n) {
            puts("YES"); return 0;
        }
    }
    puts("NO");

    return 0;
}