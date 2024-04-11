#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

struct Cube {
    vector <vector <vector <int> > > a;
};

Cube *new_cube() {
    vector <vector <vector <int> > > a(6, vector <vector <int> > (2, vector <int> (2, 0)));
    return new Cube({a});
}

typedef Cube* cube;

vector <int> lleft = {1, 3, 5, 4};
vector <int> down = {0, 1, 2, 5};

bool full(Cube *now, int x) {
    int color = now->a[x][0][0];
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            if (now->a[x][j][k] != color) {
                return false;
            }
        }
    }
    return true;
}

vector <int> shift(vector <int> a) {
    int n = a.size();
    int x = a[0];
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = x;
    return a;
}

void print(vector <int> a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    Cube *now = new_cube();
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cin >> now->a[i][j][k];
            }
        }
    }
    auto mas = now->a;
    if (full(now, 0) && full(now, 2)) {
        vector <int> a, b;
        vector <int> order = {3, 1, 4, 5};
        for (int i = 0; i < 4; i++) {
            int x = order[i];
            for (int j = 0; j < 2; j++) {
                a.push_back(mas[x][0][j]);
                b.push_back(mas[x][1][j]);
            }
        }
        vector <int> a1 = shift(shift(a));
        vector <int> b1 = shift(shift(b));
        //print(a);
        //print(b);
        if (a1 == b || b1 == a) {
            cout << "YES\n";
            return 0;
        }
    }
    if (full(now, 3) && full(now, 4)) {
        vector <int> a, b;
        vector <int> order = {0, 1, 2, 5};
        for (int i = 0; i < 4; i++) {
            int x = order[i];
            for (int j = 0; j < 2; j++) {
                a.push_back(mas[x][j][0]);
                b.push_back(mas[x][j][1]);
            }
        }
        swap(a[6], b[6]);
        swap(a[7], b[7]);
        //print(a);
        //print(b);
        vector <int> a1 = shift(shift(a));
        vector <int> b1 = shift(shift(b));
        if (a1 == b || b1 == a) {
            cout << "YES\n";
            return 0;
        }
    }
    if (full(now, 1) && full(now, 5)) {
        vector <int> a, b;
        /*vector <int> order = {0, 4, 2, 3};
        for (int i = 0; i < 4; i++) {
            int x = order[i];
            for (int j = 0; j < 2; j++) {
                a.push_back(mas[x][j][0]);
                b.push_back(mas[x][j][1]);
            }
        }
        swap(a[6], a[7]);
        swap(b[6], b[7]);*/
        a.push_back(mas[0][0][0]);
        a.push_back(mas[0][0][1]);
        a.push_back(mas[4][0][1]);
        a.push_back(mas[4][1][1]);
        a.push_back(mas[2][1][1]);
        a.push_back(mas[2][1][0]);
        a.push_back(mas[3][1][0]);
        a.push_back(mas[3][0][0]);
        ///CHTO
        b.push_back(mas[0][1][0]);
        b.push_back(mas[0][1][1]);
        b.push_back(mas[4][0][0]);
        b.push_back(mas[4][1][0]);
        b.push_back(mas[2][0][1]);
        b.push_back(mas[2][0][0]);
        b.push_back(mas[3][1][1]);
        b.push_back(mas[3][0][1]);
        //print(a);
        //print(b);
        vector <int> a1 = shift(shift(a));
        vector <int> b1 = shift(shift(b));
        if (a1 == b || b1 == a) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}