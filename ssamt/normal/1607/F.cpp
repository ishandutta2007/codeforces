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
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d %d", &n, &m);
		char s[n][m+1];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		int a[n][m];
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(s[i][j] == 'U') {
					a[i][j] = 0;
				} else if(s[i][j] == 'D') {
					a[i][j] = 1;
				} else if(s[i][j] == 'L') {
					a[i][j] = 2;
				} else {
					a[i][j] = 3;
				}
			}
		}
		vector2<int> d[4] = {
			vector2<int>(-1, 0),
			vector2<int>(1, 0),
			vector2<int>(0, -1),
			vector2<int>(0, 1),
		};
		int dist[n][m] = {};
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(dist[i][j] == 0) {
					vector2<int> pos(i, j);
					vector<vector2<int>> path{pos.clone()};
					int dir;
					while(dist[pos.x][pos.y] == 0) {
						dist[pos.x][pos.y] = -1;
						dir = a[pos.x][pos.y];
						pos += d[dir];
						if(0<=pos.x && pos.x<n && 0<=pos.y && pos.y<m) {
							path.push_back(pos.clone());
						} else {
							break;
						}
					}
					/*for(k=0; k<path.size(); k++) {
						printf("%d %d\n", path[k].x, path[k].y);
					}*/
					if(0<=pos.x && pos.x<n && 0<=pos.y && pos.y<m) {
						if(dist[pos.x][pos.y] == -1) {
							for(k=path.size()-2; path[k]!=path.back(); k--);
							for(l=k; l<path.size()-1; l++) {
								dist[path[l].x][path[l].y] = path.size()-1-k;
							}
							for(l=0; l<k; l++) {
								dist[path[l].x][path[l].y] = path.size()-1-l;
							}
						} else {
							for(l=0; l<path.size()-1; l++) {
								dist[path[l].x][path[l].y] = path.size()-1-l+dist[path.back().x][path.back().y];
							}
						}
					} else {
						for(l=0; l<path.size(); l++) {
							dist[path[l].x][path[l].y] = path.size()-l;
						}
					}
				}
			}
		}
		int r, c, maxd = 0;
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(dist[i][j] > maxd) {
					maxd = dist[i][j];
					r = i;
					c = j;
				}
			}
		}
		printf("%d %d %d\n", r+1, c+1, maxd);
	}
}