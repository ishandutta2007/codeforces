#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first != b.first) return (a.first < b.first);
    return (a.second < b.second);
}struct pt {
	int x, y;
};

bool ccmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> &a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &ccmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}
vector<pair<int, int> > Hull(vector<pair<int, int> > &pts){
    vector<pt> kek;
    int mx = 0, my = 0;
    for (int i=0;i<pts.size();i++) mx = max(mx, pts[i].first);
    for (int i=0;i<pts.size();i++) my = max(my, pts[i].second);
    kek.push_back({0, my});
    kek.push_back({mx, 0});
    kek.push_back({0, 0});
    for (int i=0;i<pts.size();i++) kek.push_back({pts[i].first, pts[i].second});
    convex_hull(kek);
    vector<pair<int, int> > ans;
    int ind = -1;
    for (int i=0;i<kek.size();i++) if (kek[i].x==0 && kek[i].y==0) ind = i;
    for (int i=0;i<kek.size();i++){
        int A = (i+ind)%kek.size();
        ans.push_back({kek[A].x, kek[A].y});
    }
    return ans;
}
void check(vector<pair<int, int> > &hull, pair<int, int> pt){
    int L = 0, R = hull.size() - 1;
    while (R-L>1){
        int M = (L+R)/2;
        int vp = hull[M].first * pt.second - hull[M].second * pt.first;
        if (vp >= 0) R = M;
        else L = M;
    }
    int X1 = hull[L].first, Y1 = hull[L].second, X2 = hull[R].first, Y2 = hull[R].second;
    int A = Y1-Y2, B = X2-X1, C = -(Y1*X2-Y2*X1);
    int F = C, S = pt.first * A + pt.second*B+C;
    if (F != 0)F /= abs(F);
    if (S!=0) S /= abs(S);
    F *= S;
    if (F > 0) return;
    cout << "Max";
    exit(0);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    vector<pair<int, int> > a, b;
    for (int i=0;i<n;i++){
        int X, Y;
        cin >> X >> Y;
        a.push_back({X, Y});
    }
    for (int i=0;i<m;i++){
        int X, Y;
        cin >> X >> Y;
        b.push_back({X, Y});
    }
    vector<pair<int, int> > pts = Hull(b);
    //for (int i=0; i < pts.size(); i++) cout << pts[i].first << " " << pts[i].second << endl;
    for (int i=0; i < n; i++){
        check(pts, a[i]);
    }
    cout << "Min";
    return 0;
}