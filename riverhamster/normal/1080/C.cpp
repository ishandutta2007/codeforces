#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Rect{
	ll x1, y1, x2, y2;
	Rect(){}
	Rect(ll _x1, ll _y1, ll _x2, ll _y2){
		x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2;
	}
};
ll x[10], y[10];

inline bool inside(Rect x, Rect par){
	if(x.x1 >= par.x1 && x.x2 <= par.x2 && x.y1 >= par.y1 && x.y2 <= par.y2) return true;
	return false;
}
ll Count(Rect r){
	ll line1, line0, x0, x1;
	line0 = r.y2 / 2 - (r.y1-1) / 2;
	line1 = (r.y2 - r.y1 + 1) - line0;
	x0 = r.x2 / 2 - (r.x1-1) / 2;
	x1 = (r.x2 - r.x1 + 1) - x0;
//	printf("x0 = %lld x1 = %lld line0 = %lld line1 = %lld\n", x0, x1, line0, line1);
//	printf("have %lld blackblock!  ", x0 * line0 + x1 * line1);
	return x0 * line1 + x1 * line0;
}

int main(){
//	freopen("cf1080c.in", "r", stdin);
//	freopen("cf1080c.out", "w", stdout);
	int DC;
	Rect bl, wh, now;
	ll ans, n, m;
	scanf("%d", &DC);
	while(DC--){
		ans = 0;
		cin >> n >> m;
		cin >> wh.x1 >> wh.y1 >> wh.x2 >> wh.y2;
		cin >> bl.x1 >> bl.y1 >> bl.x2 >> bl.y2;
		x[1] = 1; x[2] = wh.x1; x[3] = wh.x2+1; x[4] = bl.x1; x[5] = bl.x2+1; x[6] = m+1;
		y[1] = 1; y[2] = wh.y1; y[3] = wh.y2+1; y[4] = bl.y1; y[5] = bl.y2+1; y[6] = n+1;
		sort(x+1, x+7); sort(y+1, y+7);
//		for(int i=1; i<=6; i++) printf("%d %d\n", x[i], y[i]);
		for(int i=1; i<6; i++)
			for(int j=1; j<6; j++){
				now = Rect(x[i], y[j], x[i+1]-1, y[j+1]-1);
				if(now.x1 > now.x2 || now.y1 > now.y2) continue; 
//				printf("Counting: (%lld, %lld) (%lld, %lld)\n", now.x1, now.y1, now.x2, now.y2);
				if(inside(now, bl)) ans += (x[i+1] - x[i]) * (y[j+1] - y[j]);//, puts("Black");
				else if(!inside(now, wh)) ans += Count(now);//, puts("Mixed"); 
//				else puts("White");
			}
		cout << n * m - ans << ' ' << ans << endl;
	}
	return 0;
}