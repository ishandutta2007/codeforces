#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 4e5 + 10;

struct Pt{
	long long x, y;
};

bool operator < (const Pt & a, const Pt & b){
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

bool operator == (const Pt & a, const Pt & b){
	return a.x == b.x && a.y == b.y;
}

inline long long operator * (const Pt & a, const Pt & b){
	return a.x * b.y - a.y * b.x;
}

inline long long operator % (const Pt & a, const Pt & b){
	return a.x * b.x + a.y * b.y;
}

inline Pt operator - (const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y};
}

inline Pt operator + (const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y};
}

long long sqr(long long x){
	return x * x;
}

inline double len(const Pt & a){
	return sqrt(sqr(a.x) + sqr(a.y));
}

long long absll(long long x){
	return x < 0 ? -x : x;
}

void read(){

}

namespace DB {
    struct Pt{
        double x, y;
        Pt(const ::Pt &a) : x(a.x), y(a.y) {}
        Pt(double _x, double _y) : x(_x), y(_y) {}
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

    inline Pt operator / (const Pt & a, double u){
        return (Pt){a.x / u, a.y / u};
    }

    double sqr(double x){
        return x * x;
    }

    inline double len(const Pt & a){
        return sqrt(sqr(a.x) + sqr(a.y));
    }
}

int n, H;
Pt a[MAXN], eye;

void solve() {
    scanf("%d%d", &n, &H);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    eye = a[n];
    eye.y += H;
    Pt cur = a[n];
    double ans = 0;
    for (int i = n; i >= 2; i--) {
        // a[i - 1] ~ a[i]
        // cout << "====== " << i << ' ' << cur.x << ' ' << cur.y << endl;
        if ((a[i] - eye) * (cur - eye) == 0) {
            // cout << "???" << (a[i - 1] - eye) * (cur - eye) << endl;
            if ((a[i - 1] - eye) * (cur - eye) >= 0) {
                ans += len(a[i] - a[i - 1]);
                cur = a[i - 1];
            }
        } else {
            // cout << "!!!" << (a[i - 1] - eye) * (cur - eye) << endl;
            if ((a[i - 1] - eye) * (cur - eye) > 0) {
                Pt s = a[i] - a[i - 1];
                Pt t = eye - cur;
                double at = s * t;
                DB::Pt s_db{s};
                DB::Pt v = a[i] + (eye - a[i]) * t / at * s_db;
                // cerr << a[i].x << ' ' << a[i].y << endl;
                // cerr << v.x << ' ' << v.y << endl;
                // cerr << a[i - 1].x << ' ' << a[i - 1].y << endl;
                ans += len(a[i - 1] - v);
                cur = a[i - 1];
            }
        }
        // cout << "ans: " << ans << endl;
    }
    printf("%.15f\n", ans);
}

void printans(){

}
	

int main(){
	int T = 1;
    // scanf("%d", &T);
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}