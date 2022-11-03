#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

struct Pt{
	double x, y;
};

inline int equal(double p, double q){
	return fabs(p - q) < eps;
}

bool operator < (const Pt & a, const Pt & b){
	if (equal(a.x,b.x))
		return a.y < b.y;
	else
		return a.x < b.x;
}

bool operator == (const Pt & a, const Pt & b){
	return equal(a.x, b.x) && equal(a.y, b.y);
}

inline double operator * (const Pt & a, const Pt & b){
	return a.x * b.y - a.y * b.x;
}

inline double operator % (const Pt & a, const Pt & b){
	return a.x * b.x + a.y * b.y;
}

inline Pt operator - (const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y};
}

inline Pt operator + (const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y};
}

inline Pt operator * (double u, const Pt & a){
	return (Pt){a.x * u, a.y * u};
}

double sqr(double x){
	return x * x;
}

inline double len(const Pt & a){
	return sqrt(sqr(a.x) + sqr(a.y));
}

vector<Pt> convex_hull(vector<Pt> u){
    sort(u.begin(),u.end()); 
    u.erase(unique(u.begin(),u.end()),u.end()); 
    if(u.size()<3) return u;
    vector<Pt> c;
    for(size_t i=0,o=1,m=1;~i;i+=o){
        while(c.size()>m){
            Pt a=c.back()-c[c.size()-2];
            Pt b=c.back()-u[i];
            if(a*b<0) break; 
            c.pop_back();
        }
        c.push_back(u[i]);
        if(i+1==u.size()) m=c.size(),o=-1;
    }
    c.pop_back();
    return c;
}

bool onSegment(const Pt& p, const Pt& q, const Pt& r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
        return true; 
    return false; 
} 

int orientation(const Pt& p, const Pt& q, const Pt& r) { 
    double val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    if (fabs(val) < eps) return 0; 
    return (val > 0)? 1: 2; 
} 

bool doIntersect(const Pt& p1, const Pt& q1, const Pt& p2, const Pt& q2) {
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
    if (o1 != o2 && o3 != o4) 
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
} 

double W, H;
int n;
vector<Pt> a[MAXM];
double b[MAXM];

bool isInside(vector<Pt>& polygon, Pt p) { 
    int n = polygon.size();
    if (n < 3) return false; 
    Pt extreme = {max(W, H) * 2 + 5.17353162, max(W, H) * 2 + 1.327354234};
    int count = 0, i = 0; 
    // cout << n << ' ' << p.x << ' ' << p.y << ' ' << extreme.x << ' ' << extreme.y << endl;
    do { 
        int next = (i+1)%n;
        // cout << "???" << i << ' ' << polygon[i].x << ' ' << polygon[i].y << endl;
        if (doIntersect(polygon[i], polygon[next], p, extreme)) { 
            if (orientation(polygon[i], p, polygon[next]) == 0) {
               if (onSegment(polygon[i], p, polygon[next])) return true;
            }
            else {
                count++; 
            }
        } 
        i = next; 
    } while (i != 0);  
    // cout << count << endl;
    return count&1;
} 

double calc(const Pt &x, const Pt & a, const Pt & b) {
    if ((x - a) % (b - a) <= 0) return 1e200;
    if ((x - b) % (a - b) <= 0) return 1e200;
    if (len(a - b) <= eps) return 1e200;
    return fabs((x - a) * (x - b)) / len(a - b);
}

bool check(vector<Pt>&a, double x, double y, double r) {
    Pt p = (Pt){x, y};
    for (auto &q : a) {
        if (len(p - q) <= r + eps) return true;
    }
    for (int i = 0; i < a.size(); i++) {
        if (calc(p, a[i], a[(i + 1) % (a.size())]) <= r + eps) return true;
    }
    if (isInside(a, p)) return true;
    return false;
}

void solve(){
    scanf("%lf%lf%d", &W, &H, &n);
    for (int i = 0; i < n; i++) {
        int x;
        double p, q;
        scanf("%d", &x);
        a[i].clear();
        for (int j = 0; j < x; j++) {
            scanf("%lf%lf", &p, &q);
            a[i].push_back((Pt){p, q});
        }
        double ans = a[i][x - 1] * a[i][0];
        for (int j = 1; j < x; j++) 
            ans += a[i][j - 1] * a[i][j];
        ans = fabs(ans) / 2.0;
        b[i] = ans;
    }
    int Q;
    scanf("%d", &Q);
    vector<int> res;
    while (Q--) {
        double x, y, r;
        scanf("%lf%lf%lf", &x, &y, &r);
        double ans = 0;
        res.clear();
        for (int i = 0; i < n; i++) {
            if (check(a[i], x, y, r)) {
                ans += b[i];
                res.push_back(i);
            }
        }
        printf("%.15f %d", ans, (int)(res.size()));
        for (auto &x : res) {
            printf(" %d", x);
        }
        puts("");
    }
}	

int main(){
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}