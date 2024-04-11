#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int sec[86500], cs, day[150000], ds, cur;
int s, m, h, d, dt, mt, T;
LL perioid, dd, ss, x, ans;

bool leap(int y){
	if(y % 4) return false;
	if(y % 100) return true;
	if(y % 400) return false;
	return true;
}

int leap_month(int y, int m){
	return (leap(y) && m == 1);
}

bool valid(int _mt, int _dt, int _d){
	if(mt != -1 && mt != _mt) return false;
	if( (dt == -1 && d == -1) || dt == _dt || d == _d) return true;
	return false;
}

const int dmon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void prepare(){
	for(int i = 0; i < 24; i ++) if(h == -1 || h == i)
		for(int j = 0; j < 60; j ++) if(m == -1 || m == j)
			for(int k = 0; k < 60; k ++) if(s == -1 || s == k)
				sec[cs ++] = i * 3600 + j * 60 + k;
	for(int i = 0; i < 400; i ++){
		for(int j = 0; j < 12; j ++){
			int tot = dmon[j] + leap_month(i + 1970, j);
			for(int k = 0; k < tot; k ++){
				if(valid(j, k, (cur + 3) % 7) ) day[ds ++] = cur;
				cur ++;
			}
		}
	}
	perioid = cur * 86400ll;
}

int main(){
	scanf("%d %d %d %d %d %d", &s, &m, &h, &d, &dt, &mt);
   if(d > 0) d --;
   if(dt > 0) dt --;
   if(mt > 0) mt --;
	prepare();
	for(scanf("%d", &T); T --; ){
		scanf("%I64d", &x);
		ans = x - x % perioid;
		x = x - ans;
		dd = x / 86400;
		ss = x % 86400;
		int it = lower_bound(day, day + ds, dd) - day;
		if(it == ds) ans += perioid + day[0] * 86400ll + sec[0];
		else if(day[it] > dd) ans += day[it] * 86400ll + sec[0];
		else{
			int id = upper_bound(sec, sec + cs, ss) - sec;
			if(id < cs) ans += day[it] * 86400ll + sec[id];
			else{
				it ++;
				if(it == ds) ans += perioid + day[0] * 86400ll + sec[0];
				else ans += day[it] * 86400ll + sec[0];
			}
		}
		printf("%I64d\n", ans);
	}
}