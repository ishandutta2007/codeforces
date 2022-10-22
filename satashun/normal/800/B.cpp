#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

//intersectSP modified on 2018/7/5

namespace geom {
    
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define EPS (1e-9)
#define PI (3.1415926535897932384626)
    
    typedef double R;
    typedef complex<R> P;
    
    inline int sgn(R a, R b = 0) { return a < b - EPS ? -1 : a > b + EPS ? 1 : 0; }
    inline bool near(P a, P b) { return !sgn(abs(a - b)); }
    inline R norm(const P &p) { return p.X * p.X + p.Y * p.Y; }
    inline R dot(const P &a, const P &b) { return real(a * conj(b)); }
    inline R cross(const P &a, const P &b) { return imag(conj(a) * b); }
    inline R sr(R a) { return sqrt(max(a, (R)0));}
    inline P unit(const P &p) { return p / abs(p); }
    inline P proj(const P &s, const P &t) { return t * dot(s, t) / norm(t);}
    
    struct L : public vector<P> { // line
        L() {}
        L(const P &a, const P &b) {
            this->push_back(a); this->push_back(b);
        }
        P dir() const { return at(1) - at(0); }
    };
    
    struct G : public vector<P> {
        G(int sz = 0) : vector(sz) {}
        L edge(int i) const { return L(at(i), at(i+1 == size() ? 0 : i+1)); }
    };
    
    //(a->b->c)
    int ccw(P a, P b, P c) {
        b -= a; c -= a;
        R cr = cross(b, c);
        if (sgn(cr) > 0) return 1;                 // counter clockwise
        if (sgn(cr) < 0) return -1;                // clockwise
        if (sgn(dot(b, c)) < 0) return 2;          // c--a--b on line
        if (sgn(norm(b), norm(c)) < 0) return -2;  // a--b--c on line
        return 0;
    }
    
    // L..line, S..segment, P..point
    
    bool intersectLL(const L &l, const L &m) {
        return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
        abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
    }
    
    bool intersectLS(const L &l, const L &s) {
        return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
        cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
    }
    
    bool intersectLP(const L &l, const P &p) {
        return abs(cross(l[1]-p, l[0]-p)) < EPS;
    }
    
    bool intersectSS(const L &s, const L &t) {
        return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
        ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
    }
    
    bool intersectSP(const L &s, const P &p) {
        return !ccw(s[0],s[1],p);
    }
    
    inline P proj(const P &s, const L &t) { return t[0] + proj(s - t[0], t[1] - t[0]);}
    
    P projection(const L &l, const P &p) {
        R t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
        return l[0] + t*(l[0]-l[1]);
    }
    
    P reflection(const L &l, const P &p) {
        return p + (projection(l, p) - p) * (R)2;
    }
    
    R distanceLP(const L &l, const P &p) {
        return abs(p - projection(l, p));
    }
    
    R distanceLL(const L &l, const L &m) {
        return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
    }
    
    R distanceLS(const L &l, const L &s) {
        if (intersectLS(l, s)) return 0;
        return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
    }
    
    R distanceSP(const L &s, const P &p) {
        const P r = projection(s, p);
        if (intersectSP(s, r)) return abs(r - p);
        return min(abs(s[0] - p), abs(s[1] - p));
    }
    
    R distanceSS(const L &s, const L &t) {
        if (intersectSS(s, t)) return 0;
        return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
                   min(distanceSP(t, s[0]), distanceSP(t, s[1])));
    }
    
    P crosspoint(const L &l, const L &m) {
        R A = cross(l[1] - l[0], m[1] - m[0]);
        R B = cross(l[1] - l[0], l[1] - m[0]);
        if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
        if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
        return m[0] + B / A * (m[1] - m[0]);
    }
    
    struct C{P c; R r;};
    
    pair<P, P> crosspoint(C a, C b) {
        R d = abs(a.c - b.c);
        R l = ((a.r*a.r - b.r*b.r) / d + d) / 2.0;
        R h = sqrt(a.r*a.r - l*l);
        P e = a.c + (b.c-a.c) * l / d;
        P p = (b.c-a.c) * h / d * P(0,-1);
        return make_pair(e+p, e-p);
    }
    
    pair<P, P> crosspoint(C c, L l) {
	P p = projection(l, c.c);
	R d = abs(p - c.c);
	P ve = unit(l.dir());
	R w = sr(c.r * c.r - d * d);
	return mp(p - w * ve, p + w * ve);
    }

    R area(P a, P b, P c) { return imag(conj(b - a) * (c - a)) * 0.5; }
    
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
    
    R poly_area(const G& vec) {
        R ret = 0.0;
        rep(i, vec.size())
        ret += cross(curr(vec, i), next(vec, i));
        return fabs(ret) / (R)2;
    }
    
    //center of mass
    P center(const G &vec) {
        R ar = 0;
        P c(0, 0);
        rep(i, vec.size()) {
            P a = curr(vec,i), b = next(vec,i);
            R t = a.X * b.Y - b.X * a.Y;
            ar += t;
            c += (a + b) * t;
        }
        c /= 3 * ar;
        return c;
    }
    
    //polygon,point
    enum { OUT, ON, IN };
    int contains(const G &vec, const P &p) {
        bool in = false;
        for (int i = 0; i < vec.size(); ++i) {
            P a = curr(vec,i) - p, b = next(vec,i) - p;
            if (imag(a) > imag(b)) swap(a, b);
            if (imag(a) <= 0 && 0 < imag(b))
                if (cross(a, b) < 0) in = !in;
            if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
        }
        return in ? IN : OUT;
    }
    
    /* 
     enum { TRUE = 1, FALSE = 0, BORDER = -1 };
     
     int contains(const G& vec, const P &p) {
     R sum = .0;
     rep(i, vec.size()) {
	    L l(curr(vec, i), next(vec, i));
	    if (intersectSP(l, p)) return BORDER;
	    sum += arg((curr(vec, i) - p) / (next(vec, i) - p));
     }
     return !!sgn(sum);
     }
     */
    
    bool containSG(const L &s, const G &vec) {
        vector<P> p;
        p.push_back(s[0]);
        p.push_back(s[1]);
        
        for (int i = 0; i < vec.size(); ++i) {
            L e(vec[i], vec[(i + 1) % vec.size()]);
            
            if (abs(cross(e[1] - e[0], s[1] - s[0])) > EPS) {
                if (intersectSS(e, s)) p.push_back(crosspoint(e, s));
            }
            
            if (intersectSP(s, vec[i])) p.push_back(vec[i]);
        }
        
        sort(ALL(p));
        
        for (int i = 0; i < (int)p.size() - 1; ++i) {
            P pt = (p[i] + p[i + 1]) / 2.;
            if (contains(vec, pt) == OUT) return false;
        }
        
        return true;
    }
    
    G convex_cut(const G& Pl, const L& l) {
        G Q;
        for (int i = 0; i < Pl.size(); ++i) {
            P A = curr(Pl, i), B = next(Pl, i);
            if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
            if (ccw(l[0], l[1], A) * ccw(l[0], l[1], B) < 0)
                Q.push_back(crosspoint(L(A, B), l));
        }
        return Q;
    }
    
    G convex_hull(G ps) {
        int n = ps.size(), k = 0;
        sort(ALL(ps));
        
        G ch(2 * n);
        
        for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
            while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
        for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
            while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
        ch.resize(k-1);
        return ch;
    }
}

using namespace geom;

namespace std {
    bool operator<(const P &a, const P &b) { return sgn(a.X - b.X) ? a.X < b.X : a.Y < b.Y; }
    istream& operator>>(istream &is, P &p) { R x, y; is >> x >> y; p = P(x, y); return is; }
}

int main() {
	int n; cin >> n;
	G pl(n);

	rep(i, n) {
		cin >> pl[i]; 
	}
	R ans = 1e9;

	rep(i, n) {
		int j = (i + 1) % n, k = (i + 2) % n;
		R d1 = distanceLP(L(pl[i], pl[k]), pl[j]);
		R d2 = distanceLP(L(pl[i], pl[j]), pl[k]);
		R d3 = distanceLP(L(pl[j], pl[k]), pl[i]);
		chmin(ans, min({d1,d2,d3}) / 2);
	}
	printf("%.8f\n", ans);
	return 0;
}