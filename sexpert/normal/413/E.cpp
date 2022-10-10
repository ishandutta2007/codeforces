#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 1;
const int INF = 1e6;
int ccomp, n, m, gdist[MAXN];
set<ii> gsqs;
map<ii, int> pos, vist;
int comp[2*MAXN];
char rect[2][MAXN];
vector<ii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(ii s) {
    vist[s] = 1;
    comp[n*s.first + s.second] = ccomp;
    for(ii p : dir) {
        ii v = {s.first + p.first, s.second + p.second};
        if(v.first < 0 || v.first > 1 || v.second < 0 || v.second >= n || vist[v] || rect[v.first][v.second] == 'X')
            continue;
        dfs(v);
    }
}

int dist(int x, int y) {
    x--;
    y--;
    if(comp[x] != comp[y])
        return -1;
    ii p1 = {x % n, x / n}, p2 = {y % n, y / n};
    if(p1.first > p2.first)
        swap(p1, p2);
    //cout << "(" << p1.first << ", " << p1.second << ")"<< endl;
    //cout << "(" << p2.first << ", " << p2.second << ")" << endl;
    auto it1 = gsqs.find(p1), it2 = gsqs.find(p2);
    bool b1 = (it1 != gsqs.end()), b2 = (it2 != gsqs.end());
    if(b1 && b2)
        return abs(gdist[pos[p2]] - gdist[pos[p1]]);
    if(!b1) {
        auto it = gsqs.lower_bound(p1);
        ii p = *it;
        //cout << p.first << " " << p.second << endl;
        if(it != gsqs.end() && p.first <= p2.first)
            return abs(p1.first - p.first) + abs(p1.second - p.second) + dist(p.first + n*p.second + 1, p2.first + n*p2.second + 1);
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }
    if(!b2) {
        auto it = gsqs.lower_bound(p2);
        if(it != gsqs.begin()) {
            it--;
            ii p = *it;
            if(p.first >= p1.first)
                return abs(p2.first - p.first) + abs(p2.second - p.second) + dist(p.first + n*p.second + 1, p1.first + n*p1.second + 1);   
        }
    }
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            rect[i][j] = s[j];
    }
    for(int i = 0; i < 2*n; i++) {
        ii p = {i/n, i % n};
        if(!vist[p] && rect[p.first][p.second] == '.') {
            dfs(p);
            ccomp++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(rect[0][i] == '.' && rect[1][i] == 'X') {
            pos[{i, 0}] = gsqs.size();
            gsqs.insert({i, 0});
        }
        if(rect[1][i] == '.' && rect[0][i] == 'X') {
            pos[{i, 1}] = gsqs.size();
            gsqs.insert({i, 1});
        }
    }
    ii pre = {-1, -1};
    int i = 0;
    for(ii p : gsqs) {
        if(pre.first >= 0)
            gdist[i] = gdist[i - 1] + (p.first - pre.first) + (p.second != pre.second ? 1 : 0);
        i++;
        pre = p;
    }
    //for(int i = 0; i < gsqs.size(); i++)
    //    cout << gdist[i] << endl;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cout << dist(x, y) << endl;
    }
}