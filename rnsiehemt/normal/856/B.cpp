#include <bits/stdc++.h>

const int maxnodes = 1000*1000+5;

int T, n, ch__[maxnodes][26], Labels = 1;
std::vector<int*> v;
std::vector<int> e[maxnodes];
char s[maxnodes];
std::vector<std::string> ss;
bool seen[maxnodes], done[maxnodes];

int &ch(int n, int c) {
    v.emplace_back(&ch__[n][c]);
    return ch__[n][c];
}

std::pair<int,int> go(int i, int p) {
    seen[i] = true;
    int wme = 1, wome = 0;
    for (int j : e[i]) {
        if (j == p) {
            continue;
        }
        int w, wo;
        std::tie(w, wo) = go(j, i);
        wme += wo;
        wome += w;
    }
    wme = std::max(wme, wome);
    return std::make_pair(wme, wome);
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        for (int *i : v) {
            *i = 0;
        }
        v.clear();
        for (int i = 0; i < Labels; i++) {
            e[i].clear();
            seen[i] = false;
            done[i] = false;
        }
        Labels = 1;
        ss.clear();

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %s", s);
            ss.push_back(s);
            int x = 0, l = strlen(s);
            for (int j = 0; j < l; j++) {
                int k = s[j] - 'a';
                int &c = ch(x, k);
                if (c == 0) {
                    c = Labels++;
                }
                x = c;
                //printf("j = %d, l = %d, at %d\n", j, l, x);
            }
        }
        for (auto &s : ss) {
            int x = ch__[0][s[0] - 'a'], y = 0, l = int(s.length());
            for (int j = 1; j < l; j++) {
                int k = s[j] - 'a';
                if (ch__[x][k] == 0 || ch__[y][k] == 0) {
                    break;
                }
                x = ch__[x][k];
                y = ch__[y][k];
                if (!done[x]) {
                    done[x] = true;
                    e[x].push_back(y);
                    e[y].push_back(x);
                    //printf("edge from %d to %d\n", x, y);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < Labels; i++) {
            if (!seen[i]) {
                int w, wo;
                std::tie(w, wo) = go(i, -1);
                ans += std::max(w, wo);
            }
        }
        printf("%d\n", ans);
    }
}