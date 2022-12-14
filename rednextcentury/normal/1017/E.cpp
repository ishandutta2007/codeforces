//
// Convex hull of 2D points
//
// Description:
//   Find a convex hull of point sets.
//
// Algorithm:
//   Andrew's monotone chain.
//
// References:
//   A. M. Andrew (1979):
//     Another efficient algorithm for convex hulls in two dimensions.
//     Information Processing Letters, vol.9, pp.216-219.
//

#include <bits/stdc++.h>

using namespace std;

#define ALL(c) c.begin(), c.end()
#define FOR(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define fst first
#define snd second

typedef long long Value;
typedef complex<Value> Point;
#define X real()
#define Y imag()
Value dot(Point a, Point b)   { return real(conj(a)*b); }
Value cross(Point a, Point b) { return imag(conj(a)*b); }
Value dist2(Point a, Point b) { return dot(a-b, a-b); }

int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b,c) > 0)      return +1; // counter clockwise
  if (cross(b,c) < 0)      return -1; // clockwise
  if (dot(b,c) < 0)        return +2; // c--a--b on line
  if (dot(b,b) < dot(c,c)) return -2; // a--b--c on lne
  return 0;
}

// Convex Hull
//
// Algorithm:
//   Andrew's monotone chain
namespace std {
  bool operator < (Point a, Point b) { // bottom-left
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
  }
}
vector<Point> convexHull(vector<Point> p) {
  int n = p.size(), k = 0;
  vector<Point> h(2*n);
  sort(ALL(p));
  for (int i = 0; i < n; h[k++] = p[i++])
    while (k >= 2 && ccw(h[k-2], h[k-1], p[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; h[k++] = p[i--])
    while (k >= t && ccw(h[k-2], h[k-1], p[i]) <= 0) --k;
  return vector<Point>(h.begin(), h.begin() + k - (k > 1));
}
vector<long long> Build(vector<Point> ch, bool ok=false)
{
    vector<long long> ret;
    int n=ch.size();
    for (int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        int k=(j+1)%n;
        long long d1 = (ch[i].X-ch[j].X)*(ch[i].X-ch[j].X)+(ch[i].Y-ch[j].Y)*(ch[i].Y-ch[j].Y);
        long long d2 = (ch[j].X-ch[k].X)*(ch[j].X-ch[k].X)+(ch[j].Y-ch[k].Y)*(ch[j].Y-ch[k].Y);
        Point a;
        a.real(ch[j].real() - ch[i].real());
        a.imag(ch[j].Y-ch[i].Y);
        Point b;
        b.real(ch[k].X-ch[j].X);
        b.imag(ch[k].Y-ch[j].Y);
        long long d = dot(a,b);
        ret.push_back(d1);
        ret.push_back(d);
        ret.push_back(d2);
    }
    if (ok)
    {
        int m = ret.size();
        for (int i=0;i<m;i++)
            ret.push_back(ret[i]);
    }
    return ret;
}


#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct knuth_morris_pratt {
  int m;
  vector<long long> p;
  vector<int> fail;
  knuth_morris_pratt(vector<long long> x) {
       p=x, m=p.size();
    fail.resize(m+1, -1);
    for (int i = 1, j = -1; i <= m; ++i) {
      while (j >= 0 && p[j] != p[i-1]) j = fail[j];
      fail[i] = ++j;
    }
  }
  vector<int> match(vector<long long> s) {
    int n = s.size();
    vector<int> occur;
    for (int i = 0, k = 0; i < n; ++i) {
      while (k >= 0 && s[i] != p[k]) k = fail[k];
      if (++k == m) {
        /* match at s[i-m+1 ... i] */
        occur.push_back(i-m+1);
      }
    }
    return occur;
  }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<Point> p(n);
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[i].real(x);
        p[i].imag(y);
    }
    vector<Point> ch1 = convexHull(p);
    p.resize(m);
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        p[i].real(x);
        p[i].imag(y);
    }
    vector<Point> ch2 = convexHull(p);

    if (ch1.size()!=ch2.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }

    vector<long long> v1 = Build(ch1,true);
    vector<long long> v2 = Build(ch2);

    knuth_morris_pratt KMP(v2);
    if (KMP.match(v1).size())
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}