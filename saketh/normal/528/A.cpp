#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void update(set<pair<int, int>> &gaps, set<int> &cuts, int where) {
    auto it = cuts.lower_bound(where);

    int blw = *prev(it);
    int abv = *it;

    gaps.erase({abv - blw, blw});

    gaps.insert({where - blw, blw});
    gaps.insert({abv - where, where});

    cuts.insert(where);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int W, H, N;
    cin >> W >> H >> N;

    set<pair<int, int>> vert_gaps;
    set<int> vert_cuts;
    set<pair<int, int>> horiz_gaps;
    set<int> horiz_cuts;

    vert_gaps.insert({H, 0});
    vert_cuts.insert(0);
    vert_cuts.insert(H);

    horiz_gaps.insert({W, 0});
    horiz_cuts.insert(0);
    horiz_cuts.insert(W);

    char type;
    int where;

    for (int i = 0; i < N; i++) {
        cin >> type >> where;

        if (type == 'H') update(vert_gaps, vert_cuts, where);
        else update(horiz_gaps, horiz_cuts, where);

        ll width = prev(horiz_gaps.end())->first;
        ll height = prev(vert_gaps.end())->first;

        cout << width * height << "\n";
    }
}