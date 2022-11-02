#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define eb emplace_back
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 1005;

int N, ans;
bool comp[MaxN];
std::vector<int> v;

int main()
{
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        if (!comp[i]) {
            for (int j = i; j <= N; j += i) comp[j] = true;
            for (int j = i; j <= N; j *= i) v.push_back(j);
        }
    }
    printf("%d\n", sz(v));
    for (int i = 0; i < sz(v); i++) printf("%d%c", v[i], " \n"[i == sz(v)-1]);
}