#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef pair< int, int > pii;

const int MAXN = 100500;
const int MAXM = 20;
const int DIVC = 300;

int n, m, q, icnt;
pii toV[MAXN][MAXM];
bool want[MAXN][MAXM];
int used[MAXN][MAXM];
vector< vector< pii > > interest;
vector< int > intcnt;
char sm[MAXN][MAXM];

pii
getVal(int x, int y, char c)
{
    if (c == '<') {
        return make_pair(x, y - 1);
    }
    if (c == '>') {
        return make_pair(x, y + 1);
    }
    return make_pair(x - 1, y);
}

bool
isBorder(const pii &vl)
{
    return (vl.first == 0 || vl.second == 0 || vl.second == m + 1);
}

pii
getPar(int x, int y)
{
    if (isBorder(make_pair(x, y))) {
        return make_pair(x, y);
    }
    if (used[x][y] == 1) {
        return toV[x][y];
    }
    if (used[x][y] == 2) {
        return make_pair(-1, -1);
    } 
    used[x][y] = 2;
    pii nxtVal = getVal(x, y, sm[x][y]);
    toV[x][y] = getPar(nxtVal.first, nxtVal.second);
    used[x][y] = 1;
    return toV[x][y];
}

void
recalc(const vector< pii > &allInterest)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            want[i][j] = false;
            used[i][j] = 0;
        }
    }
    for (auto pa : allInterest) {
        want[pa.first][pa.second] = true;
        used[pa.first][pa.second] = 1;
        toV[pa.first][pa.second] = pa;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            getPar(i, j);
        }
    }
}

void
changeSymb(int x, int y, char nc)
{
    sm[x][y] = nc;
}

void
buildIsect(const vector< pii > allP)
{
    int len = min(300, 3 * int(sqrt(int(allP.size()) + 1.)));
    if (!len) {
        return;
    }
    int sz = int(allP.size());
    int cnt = (sz + len - 1) / len;
    len = (sz + cnt - 1) / cnt;
    interest.resize(cnt);
    intcnt.resize(cnt);
    for (int i = 0; i < cnt; ++i) {
        int lft = i * len, rght = min(sz, (i + 1) * len);
        intcnt[i] = rght - lft;
        interest[i] = vector< pii >(allP.begin() + lft, allP.begin() + rght);
    }
}

int ITER = 100;

void
calcAns(int x, int y)
{
    ++ITER;
    pii curVal = make_pair(x, y);
    while (curVal.first != -1 && !isBorder(curVal)) {
        curVal = toV[curVal.first][curVal.second];
        int x = curVal.first, y = curVal.second;
        if (!isBorder(curVal) && y != -1) {
            if (used[x][y] == ITER) {
                curVal = make_pair(-1, -1);
            } else {
                used[x][y] = ITER;
                curVal = getVal(x, y, sm[x][y]);
            }
        }
    }
    printf("%d %d\n", curVal.first, curVal.second);
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    vector< pii > chq(q);
    vector< char > tmp(q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> sm[i][j];
        }
    }
    vector< pii > ai;
    for (int i = 0; i < q; ++i) {
        char a;
        int x, y;
        cin >> a >> x >> y;
        chq[i] = make_pair(x, y);
        if (a == 'A') {
            tmp[i] = '-';
        } else {
            cin >> tmp[i];
            ai.push_back(chq[i]);
        }
    }
    if (!ai.empty()) {
        buildIsect(ai);
    }
    interest.push_back(vector< pii >());
    if (interest.empty()) {
        recalc(vector< pii >());
        for (int i = 0; i < q; ++i) {
            calcAns(chq[i].first, chq[i].second);
        }
    } else {
        int pos = 0;
        int allCnt = int(interest.size());
        int curSz = int(interest[pos].size());
        recalc(interest[0]);
        for (int i = 0; i < q; ++i) {
            if (tmp[i] != '-') {
                changeSymb(chq[i].first, chq[i].second, tmp[i]);
                --curSz;
                if (curSz == 0 && pos != allCnt - 1) {
                    ++pos;
                    recalc(interest[pos]);
                    curSz = int(interest[pos].size());
                }
            } else {
                calcAns(chq[i].first, chq[i].second);
            }
        }
    }
    return 0;
}