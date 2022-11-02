#include <bits/stdc++.h>

using namespace std;

template <typename T>
class vector2 {
	public:
		T x;
		T y;
		
		vector2(T x, T y) {
			this->x = x;
			this->y = y;
		}
		
		vector2 operator+(vector2 v) {
			return vector2(x+v.x, y+v.y);
		}
		
		void operator+=(vector2 v) {
			x += v.x;
			y += v.y;
		}
		
		vector2 operator-(vector2 v) {
			return vector2(x-v.x, y-v.y);
		}
		
		void operator-=(vector2 v) {
			x -= v.x;
			y -= v.y;
		}
		
		vector2 operator*(T a) {
			return vector2(a*x, a*y);
		}
		
		void operator*=(T a) {
			x *= a;
			y *= a;
		}
		
		bool operator==(vector2 v) {
			return x == v.x && y == v.y;
		}
		
		bool operator!=(vector2 v) {
			return !(*this==v);
		}
		
		double len() {
			return sqrt(x*x+y*y);
		}
		
		bool longer(double d) {
			return (x*x+y*y>d*d);
		}
		
		vector2 clone() {
			return vector2<T>(x, y);
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	vector2<int> dir[4] = {
		vector2<int>(-1, 0),
		vector2<int>(1, 0),
		vector2<int>(0, -1),
		vector2<int>(0, 1),
	};
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		char s[n][m+1];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		queue<vector2<int>> to;
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(s[i][j] == 'L') {
					for(k=0; k<4; k++) {
						vector2<int> con = vector2<int>(i, j)+dir[k];
						if(0<=con.x && con.x<n && 0<=con.y && con.y<m) {
							to.push(con.clone());
						}
					}
				}
			}
		}
		while(!to.empty()) {
			vector2<int> node = to.front();
			to.pop();
			if(s[node.x][node.y] == '.') {
				int count = 0;
				for(i=0; i<4; i++) {
					vector2<int> con = node+dir[i];
					if(0<=con.x && con.x<n && 0<=con.y && con.y<m) {
						if(s[con.x][con.y] == '.') {
							count++;
						}
					}
				}
				if(count <= 1) {
					s[node.x][node.y] = '+';
					for(i=0; i<4; i++) {
						vector2<int> con = node+dir[i];
						if(0<=con.x && con.x<n && 0<=con.y && con.y<m) {
							to.push(con.clone());
						}
					}
				}
			}
		}
		for(i=0; i<n; i++) {
			printf("%s\n", s[i]);
		}
	}
}