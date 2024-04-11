#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> P;
typedef vector<int> vi;
typedef long double ld;

struct Point {
    int x, y;
    Point operator-(Point p) { return {x - p.x, y - p.y}; }
};

bool InUpper(Point p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}

ll CrossProd(Point A, Point B) {
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}

int n, k;
vector<Point> pts;
vector<vector<double>> lines;
vector<vector<double>> choose;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if(x == 0 && y == 0) continue;;
        pts.push_back({x, y});
    }

    n--;
    sort(pts.begin(), pts.end(), [&](Point &a, Point &b) {
        int au = InUpper(a);
        int bu = InUpper(b);
        if (au != bu) {
            return au > bu;
        }
        return CrossProd(a, b) > 0;
    });

    int r = 0;
    for(int i = 0; i < n; i = r) {
        while(r < n && InUpper(pts[i]) == InUpper(pts[r]) && CrossProd(pts[i], pts[r]) == 0) r++;
        vector<double> line;
        choose.push_back(vector<double>());
        if(i == 0) line.push_back(0);
        for(int j = i; j < r; j++) line.push_back(hypot(pts[j].x, pts[j].y));
        sort(all(line));
        lines.push_back(line);
    }

    vector<P> pos;
    int ov = -1;
    for(int i = 0; i < sz(lines); i++) {
        if(sz(lines[i]) * 2 >= k + 1) {
            ov = i;
        }
        for(int j = sz(lines[i]) - 1, c = 0; j >= 0 && 2 * c + 1 <= k; j--, c++) {
            pos.push_back({lines[i][j] * (k - 2 * c - 1), {i, j}});
//            cout << lines[i][j] * (k - 2 * c - 1) << endl;
        }
    }
    sort(pos.begin(), pos.end(), greater<P>());
    auto add = [&](pii p) {
        int x = p.first, y = p.second;
        choose[x].push_back(lines[x][y]);
    };
    for(int i = 0; i < min(k, sz(pos)); i++) add(pos[i].second);
    if(k > sz(pos)) {
        assert(ov != -1);
        for(int j = 0; j < k - sz(pos); j++) choose[ov].push_back(lines[ov][j]);
    }
    for(int i = 0; i < sz(choose); i++) sort(all(choose[i]));
    ld res = 0;
    for(vector<double> &line : choose) {
//        cout << "line: ";
        ld sum = 0;
        for(int j = 0; j < sz(line); j++) {
//            cout << line[j] << " ";
            res += j * line[j] - sum;
            res += (k - sz(line)) * line[j];
            sum += line[j];
        }
//        cout << endl;
    }
    cout << fixed << setprecision(10) << res << '\n';


}