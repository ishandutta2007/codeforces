#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N;
map<pii, int> cache;
int query(int L, int R) {
    if (cache.find(pii(L, R)) != cache.end()) return cache[pii(L, R)];
    printf("? %d %d\n",L,R);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return cache[pii(L, R)] = ret;
}

void answer(int x) {
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}

void solve(int L,int R) {
    if (L == R) {
        answer(L);
        return;
    }
    if (L == R - 1) {
        int ret = L + R - query(L, R);
        answer(ret);
        return;
    }
    if (L == R - 2) {
        set<int>gao;
        gao.insert(query(L, L + 2));
        gao.insert(query(L, L + 1));
        gao.insert(query(L + 1, L + 2));
        int ret = L + L + 1 + L + 2;
        for (auto &t: gao) ret -= t;
        answer(ret);
        return;
    }
    int mid = (L + R) / 2;
    int v2 = query(L, mid);
    int v4 = query(mid + 1, R);
    int whole = query(L, R);
    if (whole == v2) solve(L, mid);
    else if (whole == v4) solve(mid + 1, R);
    else {
        if (whole <= mid) solve(mid + 1, R);
        else solve(L, mid);
    }
}

int main() {
    scanf("%d",&N);    
    solve(1, N);
}