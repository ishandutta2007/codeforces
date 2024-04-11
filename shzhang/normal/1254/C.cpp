#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

#define ll long long

int n;

struct PtData {
    int group;
    ll area;
    int id;
};

PtData mk_ptdata(int group, ll area, int id)
{
    PtData ans; ans.group = group; ans.area = area; ans.id = id;
    return ans;
}

ll query(int t, int i, int j, int k)
{
    printf("%d %d %d %d\n", t, i, j, k);
    fflush(stdout);
    ll ans;
    scanf("%lld", &ans);
    return ans;
}

ll area[1005];

bool cmp(PtData a, PtData b)
{
    return a.group < b.group || (a.group == b.group && a.area < b.area) ||
    (a.group == b.group && a.area == b.area && a.id < b.id);
}

int main()
{
    scanf("%d", &n);
    int curright = 2;
    for (int i = 3; i <= n; i++) {
        if (query(2, 1, i, curright) < 0) {
            curright = i;
        }
    }
    ll high_area = 0; int high_vertex;
    for (int i = 2; i <= n; i++) {
        if (i == curright) continue;
        area[i] = query(1, 1, curright, i);
        if (area[i] > high_area) {
            high_area = area[i]; high_vertex = i;
        }
    }
    vector<PtData> seq;
    for (int i = 2; i <= n; i++) {
        if (i == high_vertex) continue;
        if (query(2, 1, high_vertex, i) > 0) {
            seq.push_back(mk_ptdata(1, area[i], i));
        } else {
            seq.push_back(mk_ptdata(2, -area[i], i));
        }
    }
    seq.push_back(mk_ptdata(1, 0, 1));
    seq.push_back(mk_ptdata(2, -9000000000000000000LL, high_vertex));
    sort(seq.begin(), seq.end(), cmp);
    printf("0 ");
    int one_index = 0;
    for (int i = seq.size() - 1; i >= 0; i--) {
        if (seq[i].id == 1) one_index = i;
        //printf("%d ", seq[i].id);
    }
    for (int i = one_index; i >= 0; i--) {
        printf("%d ", seq[i].id);
    }
    for (int i = seq.size() - 1; i > one_index; i--) {
        printf("%d ", seq[i].id);
    }
    return 0;
}