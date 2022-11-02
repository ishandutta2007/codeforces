#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>

using namespace std;

#define M_PI 3.14159265358979323846

class vector2 {
	public:
		double x;
		double y;
		
		vector2(double x, double y) {
			this->x = x;
			this->y = y;
		}
		
		vector2 operator+(vector2 v) {
			return vector2(x+v.x, y+v.y);
		}
		
		vector2 operator-(vector2 v) {
			return vector2(x-v.x, y-v.y);
		}
		
		vector2 operator*(double a) {
			return vector2(a*x, a*y);
		}
		
		double len() {
			return sqrt(x*x+y*y);
		}
		
		bool longer(double d) {
			return (x*x+y*y>d*d);
		}
};

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d %d", &n, &k);
	vector<vector2> p;
	for(i=0; i<n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		p.push_back(vector2(x, y));
	}
	double start = 0;
	double end = 2e5;
	double epsilon = 1e-9;
	while((end-start) > epsilon) {
		double r = (start+end)/2;
		vector<pair<double, int> > change;
		for(i=0; i<n; i++) {
			if(!p[i].longer(2*r)) {
				double theta = atan2(p[i].y, p[i].x);
				double alpha = acos((p[i].len()/2)/r);
				change.push_back(pair<double, int>{theta+alpha, -1});
				change.push_back(pair<double, int>{theta-alpha, 1});
			}
		}
		for(i=0; i<change.size(); i++) {
			if(change[i].first > M_PI) {
				change[i].first -= 2*M_PI;
			}
			if(change[i].first < -M_PI) {
				change[i].first += 2*M_PI;
			}
		}
		sort(change.begin(), change.end());
		int count = 0;
		for(i=0; i<n; i++) {
			if(!(p[i]+vector2(r, 0)).longer(r)) {
				count++;
			}
		}
		int max_in = count;
		for(i=0; i<change.size(); i++) {
			count += change[i].second;
			max_in = max(max_in, count);
		}
		if(max_in >= k) {
			end = r;
		} else {
			start = r;
		}
	}
	printf("%.10f\n", start);
}