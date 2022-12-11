#include <bits/stdc++.h>
using namespace std;
char nam[34];
int city, score, n, m;
vector <string> name;
vector <pair<int, int> > es[12345];
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d\n", nam, &city, &score);
        name.push_back(nam);
        es[city - 1].push_back(make_pair(-score, i));
    }
    for (int i = 0; i < m; i++) {
        sort(es[i].begin(), es[i].end());
        es[i].push_back(make_pair(34, 31));
        if (es[i][1].first == es[i][2].first)
            printf("?\n");
        else
            printf("%s %s\n", name[es[i][0].second].c_str(), name[es[i][1].second].c_str());
    }
}