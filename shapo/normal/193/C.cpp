#include <iostream>
#include <cstring>

#define maxn 1000000

using namespace std;

int x12, x13, x14, x23, x24, x34;
int a, b, c, d, e, f, g, h, res = maxn * 100;
int ta, tb, tc, td, tf, tg, th;
bool ok = true;
char s1[maxn], s2[maxn], s3[maxn], s4[maxn];

int input_data(){
	cin >> x12 >> x13 >> x14 >> x23 >> x24 >> x34;
	return 0;
}

int pd(){
	int f1 = x12 - tb - tc, f2 = x13 - tc - tg, f3 = x14 - tb - tf, f4 = x23 - tb - tg, f5 = x24 - tf - tc;
	if(f2 == f3 && f4 == f5){
		int tmp1 = f2 + f1 - f4, tmp2 = f2 - f1 + f4;
		if(!(tmp1 % 2) && !(tmp2 % 2)){
			td = tmp1 / 2; th = tmp2 / 2;
			ta = f1 - td;
			if(ta >= 0 && th >= 0 && td >= 0){
				if(res > ta + tb + tc + td + tf + tg + th){
					a = ta;
					b = tb;
					c = tc;
					d = td;
					f = tf;
					g = tg;
					h = th;
					res = a + b + c + d + f + g + h;
				}
			}
		}
	}
	return 0;
}

int find_ans(){
	if(!(x12 + x13 + x23 + x34 + x14 + x24)){
		e = 1;
		res = 1;
		return 0;
	}
	int a1 = x34 + x23 - x24, a2 = x34 - x23 + x24, a4 = x13 - x14 + x34, a3 = x14 - x13 + x34;
	if(a1 % 2 || a2 % 2 || a3 % 2 || a4 % 2)ok = false;
	if(!ok)return 0;
	a1 /= 2; a2 /= 2; a3 /= 2; a4 /= 2;
	for(tb = 0; tb <= a1; ++tb){
		tg = a1 - tb;
		tf = a3 - tb;
		tc = a4 - tg;
		if(tb + tg == a1 && tf + tc == a2 && tb + tf == a3 && tg + tc == a4 && tb + tc + tf + tg == x34 && tb >= 0 && tc >= 0 && tf >= 0 && tg >= 0)pd();
	}
	if(res == maxn * 100)ok = false;
	return 0;
}

int output_data(){
	if(!ok)cout << "-1\n";
	else{
		cout << res << "\n";
		int cnt = 0;
		for(int i = 1; i <= a; ++i){
			s1[cnt] = s3[cnt] = s4[cnt] = 'a';
			s2[cnt] = 'b';
			++cnt;
		}		
		for(int i = 1; i <= b; ++i){
			s1[cnt] = s3[cnt] = 'a';
			s2[cnt] = s4[cnt] = 'b';
			++cnt;
		}
		for(int i = 1; i <= c; ++i){
			s1[cnt] = s4[cnt] = 'a';
			s2[cnt] = s3[cnt] = 'b';
			++cnt;
		}
		for(int i = 1; i <= d; ++i){
			s1[cnt] = 'a';
			s2[cnt] = s3[cnt] = s4[cnt] = 'b';
			++cnt;
		}
		for(int i = 1; i <= e; ++i){
			s1[cnt] = s2[cnt] = s3[cnt] = s4[cnt] = 'a';
			++cnt;
		}
		for(int i = 1; i <= f; ++i){
			s1[cnt] = s2[cnt] = s3[cnt] = 'a';
			s4[cnt] = 'b';
			++cnt;
		}
		for(int i = 1; i <= g; ++i){
			s1[cnt] = s2[cnt] = s4[cnt] = 'a';
			s3[cnt] = 'b';
			++cnt;
		}
		for(int i = 1; i <= h; ++i){
			s1[cnt] = s2[cnt] = 'a';
			s3[cnt] = s4[cnt] = 'b';
			++cnt;
		}
		cout << s1 << "\n" << s2 << "\n" << s3 << "\n" << s4;
	}
	return 0;
}

int main(){
	input_data();
	find_ans();
	output_data();
	return 0;
}