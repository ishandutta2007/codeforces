#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> cnt(1, 0);
    vector <vector <bool> > shelfs(1, vector <bool> (m, 0));
    vector <vector <int> > data(1, vector <int> (n, 0));
    for (int i = 0; i < q; i++) {
        int all_cnt = cnt[i];
        vector <int> next = data[i];
        int id;
        cin >> id;
        if (id == 1) {
            int sh, pl;
            cin >> sh >> pl;
            sh--;
            pl--;
            vector <bool> new_shelf = shelfs[next[sh]];
            if (!new_shelf[pl]) {
                new_shelf[pl] = 1;
                all_cnt++;
            }
            shelfs.push_back(new_shelf);
            next[sh] = shelfs.size() - 1;
            data.push_back(next);
        } else if (id == 2) {
            int sh, pl;
            cin >> sh >> pl;
            sh--;
            pl--;
            vector <bool> new_shelf = shelfs[next[sh]];
             if (new_shelf[pl]) {
                new_shelf[pl] = 0;
                all_cnt--;
            }
            shelfs.push_back(new_shelf);
            next[sh] = shelfs.size() - 1;
            data.push_back(next);
        } else if (id == 3) {
            int sh;
            cin >> sh;
            sh--;
            vector <bool> new_shelf = shelfs[next[sh]];
            for (int pl = 0; pl < m; pl++) {
                if (!new_shelf[pl]) {
                    new_shelf[pl] = 1;
                    all_cnt++;
                } else {
                    new_shelf[pl] = 0;
                    all_cnt--;
                }
            }
            shelfs.push_back(new_shelf);
            next[sh] = shelfs.size() - 1;
            data.push_back(next);
        } else {
            int version;
            cin >> version;
            data.push_back(data[version]);
            all_cnt = cnt[version];
        }
        cout << all_cnt << endl;
        cnt.push_back(all_cnt);
    }
}