#include <bits/stdc++.h>

using namespace std;

int n;
int query(const vector<int> &ax, const vector<int> &bx) {
    vector<int> iset(n);
    for (int v : ax) ++iset[v];
    for (int v : bx) --iset[v];
    vector<int> sa, sb;
    for (int i = 0; i < n; ++i) {
        if (iset[i] == 1) sa.push_back(i);
        else if (iset[i] == -1) sb.push_back(i);
    }
    if (sa.empty()) return sb.empty() ? 0 : -1;
    else if (sb.empty()) return 1;

    printf("? %d %d\n", (int)sa.size(), (int)sb.size());
    for (int v : sa) printf("%d ", v + 1);
    printf("\n");
    for (int v : sb) printf("%d ", v + 1);
    printf("\n");
    fflush(stdout);

    static char response[10];
    scanf("%s", response);
    if (response[0] == 'W') exit(0);
    else if (response[0] == 'E') return 0;
    else if (response[0] == 'F') return -1; // -1 means >
    else return 1; // 1 means <
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve() {
    int k; scanf("%d %d", &n, &k);
    uniform_int_distribution<int> distrib(1, n - 1);
    for (int trial = 0; trial < 25; ++trial) {
        int i = distrib(rng);
        if (query(vector<int>{0}, vector<int>{i})  == 1) return 0;
    }
    // 0 probably contains a stone here
    int stonel = 0, stoner = 0, unsurel = 1, unsurer = n - 1;
    while (unsurel < unsurer) {
        if (unsurer - unsurel < stonel - stoner) {
            stonel = stoner - (unsurer - unsurel);
        }
        int ellen = min((unsurer - unsurel + 1) / 2, stoner - stonel + 1);
        int qbl = stonel, qbr = qbl + ellen - 1;
        int qtl = unsurel, qtr = qtl + ellen - 1;
        vector<int> qa(ellen), qb(ellen);
        iota(begin(qa), end(qa), qbl);
        iota(begin(qb), end(qb), qtl);
        int qres = query(qa, qb);
        if (qres == 0) {
            unsurel = qtr + 1; 
            stoner = qtr;
        } else if (qres == -1) {
            unsurel = qtl, unsurer = qtl + ellen - 1;
        } else {
            assert(false);
        }
    }
    return unsurel;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("! %d\n", solve() + 1);
        fflush(stdout);
    }
}