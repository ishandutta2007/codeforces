#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, two, three, k;
char s[MaxN];

int main()
{
    scanf("%d %s", &N, s);
    k = 1;
    for (int i = 1; i < N; i++) {
        if (s[i] != s[i-1]) k++;
        else two++;
        if (i >= 2 && s[i] == s[i-1] && s[i] == s[i-2]) three++;
    }
    if (three || two >= 2) k += 2;
    else if (two) k++;
    printf("%d\n", k);
}