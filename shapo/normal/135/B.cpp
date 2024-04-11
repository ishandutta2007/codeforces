#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct point{
	double x, y;
};

point mass[8];
int used[8];
bool res = false;
point aa[4], bb[4], mk[4];
int snm[4];

point v(point a, point b){
	point res;
	res.x = b.x - a.x;
	res.y = b.y - a.y;
	return res;
}

int CP(point a, point b){
	return (a.x * b.y - a.y * b.x);
}

int DP(point a, point b){
	return (a.x * b.x + a.y * b.y);
}

double len(point p){
	return (p.x * p.x + p.y * p.y);
}

bool rav(point a, point b){
	return (a.x == b.x && a.y == b.y);
}

void pr(point p){
	printf("p = %lf %lf\n", p.x, p.y);
}

bool check(int x){
	bool mm = true;
	/*for (int i = 0; i < 4; ++i)
	printf("x = %d a[%d] == %lf %lf\n", x, i, mk[i].x, mk[i].y);*/
	if (x == 0){
		point a1 = v(mk[0], mk[1]), a2 = v(mk[3], mk[2]), a3 = v(mk[1], mk[2]), a4 = v(mk[0], mk[3]);
		//pr(a1); pr(a2); pr(a3); pr(a4);
		mm = mm && rav(a1, a2) && rav(a3, a4);
		mm = mm && (DP(a1, a3) == 0);
		mm = mm && (len(a1) == len(a4));
	}
	else
	{
		point a1 = v(mk[0], mk[1]), a2 = v(mk[3], mk[2]), a3 = v(mk[1], mk[2]), a4 = v(mk[0], mk[3]);
		//pr(a1); pr(a2); pr(a3); pr(a4);
		mm = mm && rav(a1, a2) && rav(a3, a4);
		mm = mm && (DP(a1, a3) == 0);
	}
	//printf("\n");
	//if (mm == true) printf("mm = 1\n"); else printf("mm = 0\n");
	return mm;
}

bool make(int a, bool xx, int k){
	//printf("%d == a\n", a);
	if (a != 4){
		for (int i = 0; i < 4; ++i){
			if(snm[i] == 0){
				snm[i] = 1;
				if (k == 0) mk[a] = aa[i]; else mk[a] = bb[i];
				xx = xx || make(a + 1, xx, k);
				snm[i] = 0;
			}
		}
	}
	else xx = xx || check(k);
	//if (xx == true) printf("xx = 1\n"); else printf("xx = 1\n");
	return xx;
}

bool ok1(void){
	bool rs1 = false;
	for (int i = 0; i < 4; ++i) snm[i] = 0;
	return make(0, rs1, 0);
}

bool ok2(void){
	bool rs2 = false;
	for (int i = 0; i < 4; ++i) snm[i] = 0;
	return make(0, rs2, 1);
}

bool ok(void){
	int num1 = -1, num2 = -1;
	bool rs = true;
	for (int i = 0; i < 8; ++i)
		if (used[i] == 1){
			++num1; aa[num1] = mass[i];
		}else{
			++num2; bb[num2] = mass[i];
		}
		rs = rs && ok1() && ok2();
	return rs || res;
}

bool obr(int a, int b){
	if (!res && (b == 5 || a < 8)){
		if (b != 5){
			used[a] = 1;
			res = res || obr(a + 1, b + 1);
			if (!res){
				used[a] = 0;
				res = res || obr(a + 1, b);
				if (!res) return false;
			}
			return true;
		}
		else return ok();
	}
	return res;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 8; ++i)
		scanf("%lf%lf", &mass[i].x, &mass[i].y);
	if (obr(0, 1)){
		printf("YES\n");
		for (int i = 0; i < 8; ++i)
			if (used[i] == 1) printf("%d ", i + 1);
			printf("\n");
		for (int i = 0; i < 8; ++i)
			if (used[i] != 1) printf("%d ", i + 1);
			printf("\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}