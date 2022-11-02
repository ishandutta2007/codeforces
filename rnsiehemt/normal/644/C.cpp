#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::map<std::string, std::vector<std::string>> m;
std::map<std::vector<std::string>, std::vector<std::string>> n;
int N, K;
char s[99];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %s", s);
        std::string u, v;
        int l = strlen(s), j;
        for (j = 7; j < l && s[j] != '/'; j++) u += s[j];
        for (; j < l; j++) v += s[j];
        m[u].pb(v);
    }
    for (auto &i : m) {
        std::sort(all(i.second));
        i.second.erase(std::unique(all(i.second)), i.second.end());
        n[i.second].pb(i.first);
        //printf("%s: ", i.first.c_str());
        //for (auto &u : i.second) printf("%s, ", u.c_str());
        //printf("\n");
    }
    for (auto &i : n) if (sz(i.second) > 1) K++;
    printf("%d\n", K);
    for (auto &i : n) if (sz(i.second) > 1) {
        for (auto &u : i.second) printf("http://%s ", u.c_str());
        printf("\n");
    }
}