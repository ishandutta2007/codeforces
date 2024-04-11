#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n;

int ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans % 2;
}

vector<int> ask_column() {
    vector<int> res(n+1);
    for(int i = 1; i <= n; i++) res[i] = ask(1, 1, i, n);
    return res;
}

vector<int> ask_rows() {
    vector<int> res(n+1);
    for(int i = 1; i <= n; i++) res[i] = ask(1, 1, n, i);
    return res;
}

bool find_one(vector<int> &vec) {
    for(int i = 1; i <= n; i++) if(vec[i] == 1) return true;
    return false;
}

P find_ends(vector<int> &vec) {
    int a = -1, b = -1;
    for(int i = 0; i < n; i++) {
        if(vec[i] == 0 && vec[i+1] == 1) a = i + 1;
        if(vec[i] == 1 && vec[i+1] == 0) b = i + 1;
    }
//    cout << "ends are" << a << ", " << b << endl;
    return {a, b};
}

void answer(int x1, int y1, int x2, int y2) {
    printf("! %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    exit(0);
}



int main() {
    cin >> n;
    auto cols = ask_column();
    auto rows = ask_rows();
    bool one_cols = find_one(cols), one_rows = find_one(rows);
    if(one_cols && one_rows) {
        int x1, x2, y1, y2;
        P px = find_ends(cols);
        x1 = px.first, x2 = px.second;
        P py = find_ends(rows);
        y1 = py.first, y2 = py.second;

        if(ask(x1, y1, x1, y1)) answer(x1, y1, x2, y2);
        else answer(x1, y2, x2, y1);
    }
    else if(one_cols){
        P px = find_ends(cols);
        int x = min(px.first, px.second);
        int l = 0, r = n, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(ask(1, 1, x, mid)) r = mid;
            else l = mid;
        }
        answer(px.first, r, px.second, r);
    }
    else if(one_rows) {
        P py = find_ends(rows);
        int y = min(py.first, py.second);
        int l = 0, r = n, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(ask(1, 1, mid, y)) r = mid;
            else l = mid;
        }
        answer(r, py.first, r, py.second);
    }
    else {
        assert(false);
    }

}