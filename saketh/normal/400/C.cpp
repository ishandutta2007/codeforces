#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void rotate(int &N, int &M, vector<pair<int, int>> &points) {
   for (pair<int, int> &p : points) {
        int row = p.second;
        int col = N - 1 - p.first;
        p = { row, col };
   } 
    swap(N, M);
}

void flip(int &N, int &M, vector<pair<int, int>> &points) {
    for (pair<int, int> &p : points) {
        p.second = M - 1 - p.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M, X, Y, Z, P;

    cin >> N >> M >> X >> Y >> Z >> P;

    vector<pair<int, int>> points;

    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;

        points.emplace_back(x-1, y-1);
    }

    X = X % 4, Y = Y % 2; Z = Z % 4;

    for (int i = 0; i < X; i++) {
        rotate(N, M, points);
    }

    if(Y) flip(N, M, points);

    for (int i = 0; i < 3 * Z; i++) {
        rotate(N, M, points);
    }

    for (pair<int, int> p: points)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
}