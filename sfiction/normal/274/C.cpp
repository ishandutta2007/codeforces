/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 274C
 */
#include <cstdio>
#include <cmath>

const int MAXN = 100 + 10;
const double EPS = 1E-8;

struct VEC{
	double x, y;

	void read(){
		scanf("%lf%lf", &x ,&y);
	}

	void out(){
		printf("%.2lf %.2lf\n", x, y);
	}
};

VEC operator+(const VEC& l, const VEC& r){
	return (VEC){l.x + r.x, l.y + r.y};
}

VEC operator-(const VEC& l, const VEC& r){
	return (VEC){l.x - r.x, l.y - r.y};
}

VEC operator*(double l, const VEC& r){
	return (VEC){l * r.x, l * r.y};
}

VEC operator/(const VEC& l, double r){
	return (VEC){l.x / r, l.y / r};
}

double operator*(const VEC& l, const VEC& r){
	return l.x * r.x + l.y * r.y;
}

double operator/(const VEC& l, const VEC& r){
	return l.x * r.y - l.y * r.x;
}

double operator!(const VEC& l){
	return sqrt(l * l);
}

bool operator==(const VEC& l, const VEC& r){
	return l.x == l.y && r.x == r.y;
}

int n;
VEC c[MAXN];

double ans;

void update(VEC ct, double dis){
	double temp;
	for (int i=0;i<n;++i){
		temp = !(ct - c[i]);
		if (temp + EPS < dis)
			return;
	}

	if (ans < dis)
		ans = dis;
}

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i)
		c[i].read();

	ans = -1;

	//find acute triangles
	double r;
	VEC ct;
	for (int i=0;i<n;++i)
		for (int j=i+1;j<n;++j)
			for (int k=j+1;k<n;++k){
				if ((c[j] - c[i]) * (c[k] - c[i]) <= 0
					|| (c[k] - c[j]) * (c[i] - c[j]) <= 0
					|| (c[i] - c[k]) * (c[j] - c[k]) <= 0)
					continue;

				r = -((c[j].x - c[k].x) * (c[k].x - c[i].x) - (c[j].y - c[k].y) * (c[i].y - c[k].y))
					/ ((c[j].y - c[i].y) * (c[k].x - c[i].x) - (c[i].x - c[j].x) * (c[i].y - c[k].y)) / 2;
				ct = (c[i] + c[j]) / 2;
				ct.x += r * (c[j].y - c[i].y);
				ct.y += r * (c[i].x - c[j].x);
				//ct.out();
				//dis = !(c[i] - c[j]) * !(c[j] - c[k]) * !(c[k] - c[i]) / 2.0 / std::abs((c[j] - c[i]) / (c[k] - c[i]));

				update(ct, !(ct - c[i]));
			}

	//find squares
	VEC temp;
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			if (j != i)
				for (int k=0;k<n;++k)
					if (k != i && k != j && (c[i] - c[j]) * (c[j] - c[k]) == 0){
						temp = c[i] + c[k] - c[j];
				
						bool find = false;
						for (int l=0;l<n;++l)
							if (temp == c[l]){
								find = true;
								break;
							}
						if (!find)
							continue;

						update((c[i] + c[k]) / 2, !(c[i] - c[k]) / 2.0);
					}
	
	if (ans < 0)
		puts("-1");
	else
		printf("%.6lf\n", ans);

	return 0;
}