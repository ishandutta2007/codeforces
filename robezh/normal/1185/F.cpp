#include <bits/stdc++.h>
using namespace std;

const int N = 9, PW = 512, M = (int)1e5 + 50;
const int INF = (int)2e9 + 50;

int n, m;
int fr[PW];
int pm[M];
int p[PW], p2[PW];
int p2i[PW], p2j[PW], p1i[PW];

int get_mask() {
    int n, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        res |= (1 << a);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) fr[get_mask()]++;
    fill(p, p + PW, INF);
    fill(p2, p2 + PW, INF);
    for(int i = 0; i < m; i++) {
        int pr; cin >> pr;
        pm[i] = pr;
        int msk = get_mask();
        if(pr < p[msk]) {
            p[msk] = pr;
            p1i[msk] = i;
        }
    }
    for(int i = 0; i < PW; i++) {
        if(p[i] == INF) continue;
        for(int j = 0; j < PW; j++) {
            if(p[j] == INF) continue;
            if(p[i] + p[j] < p2[i | j]) {
                p2[i | j] = p[i] + p[j];
                p2i[i | j] = p1i[i];
                p2j[i | j] = p1i[j];
            }
        }
    }
    int mx_fr = 0, mn_pr = INF, mi = 0, mj = 1;
    for(int i = 0; i < PW; i++) {
        if(p2[i] == INF) continue;
        int cnt = 0;
        for(int j = 0; j < PW; j++) {
            if((i | j) == i) cnt += fr[j];
        }
        if(cnt > mx_fr) {
            mx_fr = cnt;
            mn_pr = p2[i];
            mi = p2i[i];
            mj = p2j[i];
        }
        else if(cnt == mx_fr && p2[i] < mn_pr) {
            mn_pr = p2[i];
            mi = p2i[i];
            mj = p2j[i];
        }
    }
    if(mi == mj) {
        mj = -1;
        for(int j = 0; j < m; j++) {
            if(j != mi && (mj == -1 || pm[j] < pm[mj])) mj = j;
        }
    }
    cout << mi + 1 << " " << mj + 1 << endl;
}