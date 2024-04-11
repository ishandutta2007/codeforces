#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
	}
	T operator [](int k){
		return ST[N - 1 + k];
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T all(){
		return ST[0];
	}
};
struct point{
  long double x, y;
  point(){
  }
  point(long double x, long double y): x(x), y(y){
  }
  point operator +(point P){
    return point(x + P.x, y + P.y);
  }
  point operator *(long double k){
    return point(x * k, y * k);
  }
  point operator /(long double k){
    return point(x / k, y / k);
  }
};
point rotate(point P, long double t){
  return point(P.x * cos(t) - P.y * sin(t), P.x * sin(t) + P.y * cos(t));
}
long double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y);
}
pair<point, long double> f(pair<point, long double> a, pair<point, long double> b){
  return make_pair(a.first + rotate(b.first, a.second), a.second + b.second);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);
  int n, m;
  cin >> n >> m;
  segment_tree<pair<point, long double>> ST(n, f, make_pair(point(0, 0), 0));
  for (int i = 0; i < n; i++){
    ST.update(i, make_pair(point(1, 0), 0));
  }
  for (int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    y--;
    if (x == 1){
      pair<point, long double> P = ST[y];
      P.first = P.first / abs(P.first) * (abs(P.first) + z);
      ST.update(y, P);
    }
    if (x == 2){
      pair<point, long double> P = ST[y];
      long double t = -z * PI / 180;
      P.first = rotate(P.first, t);
      P.second += t;
      ST.update(y, P);
    }
    pair<point, long double> res = ST.all();
    cout << res.first.x << ' ' << res.first.y << "\n";
  }
}