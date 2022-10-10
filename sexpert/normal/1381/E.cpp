/*
 * Monogon orz
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Point operator+(const Point &o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point &o) const { return Point(x - o.x, y - o.y); }
    Point operator*(const double k) const { return Point(k * x, k * y); }
    Point operator/(const double k) const { return Point(x / k, y / k); }
};

struct Query {
    int f, idx;
    bool operator<(const Query &o) const {
        return f < o.f;
    }
};

ostream& operator<< (ostream& out, Point p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
};

const int MAXN = 2e5 + 10;
const double eps = 1e-9;

bool vert(Point a, Point b) {
    return fabs(a.x - b.x) < eps;
}

double slp(Point a, Point b) {
    if(vert(a, b))
        return b.y - a.y;
    return (b.y - a.y)/(b.x - a.x);
}

int n, q;
double lAns[MAXN], rAns[MAXN];

vector<Point> poly, left_side, right_side, middle, p_left, p_right;
vector<Query> qs;

Point at_y(double y, Point a, Point b) {
    double la = (a.y - y)/(a.y - b.y);
    return a + (b - a) * la;
}

double area(vector<Point> p) {
    double res = 0;
    int n = p.size();
    for(int i = 0; i < n; i++) {
        res += p[i].x * p[(i + 1) % n].y;
        res -= p[i].y * p[(i + 1) % n].x;
    }
    return fabsl(res) / 2.0;
}

typedef pair<double, int> eve;

void sweep(vector<Point> &poly, double* ans) {
    vector<eve> events;
    int n = poly.size();
    for(int i = 0; i < n; i++)
        events.push_back({poly[i].x, i});
    for(int i = 1; i <= q; i++)
        events.push_back({qs[i].f, -i});
    sort(events.begin(), events.end());

    double sum_slp = 0.0, thicc = 0.0, cum = 0.0, prv = 1e9;
    for(int i = 0; i < n; i++)
        prv = min(prv, poly[i].x);

    for(auto e : events) {
        if(e.second < 0) {
            //cout << "query at " << e.first << " " << sum_slp << " " << thicc << " " << cum << " " << prv << '\n';
            if(e.first < prv)
                ans[-e.second] = 0.0;
            else {
                double dis = e.first - prv;
                ans[-e.second] = cum + dis * thicc + dis * dis * sum_slp / 2.0;
            }
            continue;
        }
        double dis = e.first - prv;
        prv = e.first;
        cum += dis * thicc;
        cum += dis * dis * sum_slp / 2.0;
        thicc += dis * sum_slp;
        int i = e.second;
        if(vert(poly[i], poly[(i + 1) % n]))
            thicc += slp(poly[i], poly[(i + 1) % n]);
        else
            sum_slp += slp(poly[i], poly[(i + 1) % n]);
        if(vert(poly[i], poly[(i + n - 1) % n]))
            continue;
        sum_slp -= slp(poly[i], poly[(i + n - 1) % n]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    poly.resize(n);
    qs.resize(q + 1);
    for(auto &p : poly)
        cin >> p.x >> p.y;
    for(int i = 1; i <= q; i++) {
        int f;
        cin >> f;
        qs[i] = {f, i};
    }

    // Reindex polygon
    int minY = INT_MAX, maxY = INT_MIN, topIdx;
    for(auto p : poly) {
        minY = min((double)minY, p.y);
        maxY = max((double)maxY, p.y);
    }
    for(int i = 0; i < n; i++) {
        if(poly[i].y == minY) {
            rotate(poly.begin(), poly.begin() + i, poly.end());
            break;
        }
    }
    if(poly[1].x > poly[0].x || (poly[1].x == poly[0].x && poly[n - 1].x < poly[0].x)) {
        reverse(poly.begin(), poly.end());
        rotate(poly.begin(), poly.begin() + n - 1, poly.end());
    }

    //for(auto p : poly)
    //    cout << p << '\n';

    // Build side chains
    for(int i = 0; i < n; i++) {
        if(poly[i].y == maxY) {
            topIdx = i;
            break;
        }
    }

    for(int i = 0; i <= topIdx; i++)
        left_side.push_back(poly[i]);
    right_side.push_back(poly[0]);
    for(int i = n - 1; i >= topIdx; i--)
        right_side.push_back(poly[i]);

    /*cout << "Left chain" << endl;
    for(auto p : left_side)
        cout << p << " ";
    cout << endl;

    cout << "Right chain" << endl;
    for(auto p : right_side)
        cout << p << " ";
    cout << endl;*/

    // Build middle chain
    int lPtr = 0, rPtr = 0;
    while(lPtr + 1 < left_side.size() || rPtr + 1 < right_side.size()) {
        if(left_side[lPtr + 1].y == right_side[rPtr + 1].y) {
            middle.push_back((left_side[lPtr + 1] + right_side[rPtr + 1]) / 2.0);
            lPtr++;
            rPtr++;
            continue;
        }
        if(left_side[lPtr + 1].y < right_side[rPtr + 1].y) {
            Point inter = at_y(left_side[lPtr + 1].y, right_side[rPtr], right_side[rPtr + 1]);
            middle.push_back((left_side[lPtr + 1] + inter) / 2.0);
            lPtr++;
            continue;
        }
        Point inter = at_y(right_side[rPtr + 1].y, left_side[lPtr], left_side[lPtr + 1]);
        middle.push_back((right_side[rPtr + 1] + inter) / 2.0);
        rPtr++;
        continue;
    }
    middle.pop_back();
    /*cout << "Middle chain" << endl;
    for(auto p : middle)
        cout << p << " ";
    cout << endl;*/

    // Build left and right polygons
    for(auto p : middle)
        p_right.push_back(p);
    for(int i = (int)right_side.size() - 1; i >= 0; i--)
        p_right.push_back(right_side[i]);
    for(auto p : left_side)
        p_left.push_back(p);
    for(int i = (int)middle.size() - 1; i >= 0; i--)
        p_left.push_back(middle[i]);

    /*cout << "Left Polygon" << endl;
    for(auto p : p_left)
        cout << p << " ";
    cout << endl;

    cout << "Right Polygon" << endl;
    for(auto p : p_right)
        cout << p << " ";
    cout << endl;*/

    // Meme area sweep
    sweep(p_left, lAns);
    sweep(p_right, rAns);

    //for(int i = 1; i <= q; i++) {
    //    cout << i << " " << qs[i].f << " " << lAns[i] << " " << rAns[i] << '\n';
    //}

    double res = area(poly);
    cout << fixed << setprecision(9);
    for(int i = 1; i <= q; i++)
        cout << res - lAns[i] + rAns[i] << '\n';
}