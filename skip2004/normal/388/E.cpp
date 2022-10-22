#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
using db = long double;
constexpr db eps = 1e-5;
struct vec {
	db x, y;
	inline db abs() const {
		return ((fabs(x) < eps ? y : x) < 0 ? 1 : -1) * sqrtl(x * x + y * y);
	}
} speed[maxn], start[maxn];
int n, ans = 1;
inline db cross(const vec& x, const vec& y) {
	return x.y * y.x - x.x * y.y;
}
inline vec operator - (const vec & a, const vec & b) {
	return (vec) { a.x - b.x, a.y - b.y };
}
inline bool operator < (const vec & x, const vec & y) {
	db A = cross(x, y);
	return fabs(A) < eps ? x.abs() < y.abs() : A < 0;
}
inline bool eql(db x, db y) {
	return fabs(x - y) < eps;
}
inline void calc(std::vector<db>& vector) {
	sort(vector.begin(), vector.end());
	for(int i = 0, j = 0;i < (int) vector.size();i = j) {
		for(j = i;j < (int) vector.size() && vector[j] - vector[i] < eps;)
			++ j;
		ans = std::max(ans, j - i + 1);
	}
}
inline void calc(std::vector<vec>& vector) {
	sort(vector.begin(), vector.end());
	for(int i = 0, j = 0;i < (int) vector.size();i = j) {
		static std::vector<db> vec; vec.clear();
		for(j = i;j < (int) vector.size() && fabs(cross(vector[j], vector[i])) < eps;++j) {
			vec.emplace_back(vector[j].abs());
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end(), eql), vec.end());
		ans = std::max(ans, (int) vec.size() + 1);
	}
}
inline void work0() {
	for(int i = 0;i < n;++i) {
		std::vector<db> vec0;
		std::vector<vec> vec1;
		for(int j = 0;j < n;++j) if(i != j) {
			if(fabs(cross(start[i] - start[j], speed[i] - speed[j])) < eps && (speed[i] - speed[j]).abs() > 1e-6) {
				vec0.emplace_back((start[i] - start[j]).abs() / (speed[i] - speed[j]).abs());
				vec1.emplace_back(speed[i] - speed[j]);
			}
		}
		calc(vec0);
		calc(vec1);
	}
}
int main() {
	cin >> n;
	for(int i = 0, t0, t1;i < n;++i) {
		cin >> t0 >> start[i].x >> start[i].y;
		cin >> t1 >> speed[i].x >> speed[i].y;
		speed[i].x = (speed[i].x - start[i].x) / (t1 - t0);
		speed[i].y = (speed[i].y - start[i].y) / (t1 - t0);
		start[i].x -= speed[i].x * t0;
		start[i].y -= speed[i].y * t0;
	}
	work0();
	cout << ans << '\n';
}