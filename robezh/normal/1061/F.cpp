#include <bits/stdc++.h>
using namespace std;

int n,k,h;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int lf1;

bool query(int x, int y, int z) {
    printf("? %d %d %d\n", x, y, z);
    fflush(stdout);
    string s;
    cin >> s;
    return s[0] == 'Y';
}

bool is_leaf(int v) {
    int cnt = 0;
    int u = (v != 1 ? 1 : 2);
    for(int i = 1; i <= n; i++) {
        if(i != u && i != v) {
            cnt += query(i, v, u);
        }
    }
    return cnt == 0;
}

bool is_another(int v, int lf) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(i != v && i != lf) {
            cnt += query(v, i, lf);
        }
    }
    return cnt == 2 * (h - 1) - 1;
}


int main() {
    cin >> n >> k;
    h = 1;
    int prod = 1;
    while(prod * k <= n){prod *= k; h++;}
//    cout << h << endl;

    vector<int> range;
    for(int i = 1; i <= n; i++) range.push_back(i);

    std::shuffle(range.begin(), range.end(), rng);
    for(int x : range) if(is_leaf(x)) {lf1 = x; break;}

//    printf("lf 1 is %d\n", lf1);
    int lf2 = 0;
    std::shuffle(range.begin(), range.end(), rng);
    for(int x : range) if(lf1 != x && is_another(x, lf1)) {lf2 = x; break;}

//    printf("lf 2 is %d\n", lf2);
    vector<int> path;
    for(int i = 1; i <= n; i++) {
        if(i != lf1 && i != lf2 && query(lf1, i, lf2)) path.push_back(i);
    }
    sort(path.begin(), path.end(), [](int a, int b){return query(lf1, a, b);});

    printf("! %d\n", path[h - 2]);
    fflush(stdout);
}