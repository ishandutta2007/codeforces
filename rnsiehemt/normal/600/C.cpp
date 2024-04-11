#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005, MaxC = 26;

char s[MaxN];
int N, c[MaxC], k;
std::vector<int> v;

int main()
{
    scanf(" %s", s);
    N = strlen(s);
    for (int i = 0; i < N; i++) c[s[i] - 'a']++;
    for (int i = 0; i < MaxC; i++) if (c[i]%2) v.push_back(i);
    for (int i = 0, j = sz(v)-1; i < j; i++, j--) {
        c[v[j]]--;
        c[v[i]]++;
    }
    for (int i = 0; i < MaxC; i++) for (int j = 0; j < c[i]/2; j++) printf("%c", char('a'+i));
    for (int i = 0; i < MaxC; i++) if (c[i]%2) printf("%c", char('a'+i));
    for (int i = MaxC-1; i >= 0; i--) for (int j = 0; j < c[i]/2; j++) printf("%c", char('a'+i));
    printf("\n");
}