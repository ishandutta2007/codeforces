#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

struct pt {
    int x, y;
    pt(int x, int y) : x(x), y(y) {}
    pt operator+(pt o) {
        return pt(x + o.x, y + o.y);
    }
};

int main() {
    vector<pt> obs;
    vector<pt> clues;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        obs.push_back(pt(x, y));
    }
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        clues.push_back(pt(x, y));
    }
    set<ii> possibles, prev;
    for(int i = 0; i < n; i++) {
        possibles.clear();
        pt cur = obs[i];
        for(pt cl : clues) {
            pt pos = cur + cl;
            ii p = {pos.x, pos.y};
            if(i == 0 || prev.count(p))
                possibles.insert(p);
        }
        prev = possibles;
    }
    ii p = *(prev.begin());
    cout << p.first << " " << p.second << endl;
}