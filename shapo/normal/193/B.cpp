#include <iostream>
#include <cmath>

#define maxn 42

using namespace std;

int n, u, r;
int a[maxn], b[maxn], k[maxn], p[maxn], cur[maxn];
long long res;

void inp_mass(int *sm){for(int i = 1; i <= n; ++i)cin >> sm[i];}

void input_data(){
	cin >> n >> u >> r;
	inp_mass(a);
	inp_mass(b);
	inp_mass(k);
	inp_mass(p);
}

void calc(const int *pa, const int *pk, long long& rres){
	long long cur = 0;
	for(int i = 1; i <= n; ++i){
		long long tmp = pa[i] * pk[i];
		cur += tmp;
	}
	rres = max(cur, rres);
}

int per(const int *tmp, const int& num, const bool& first){
	if(num == u){calc(tmp, k, res); return 0;}
	if((u - num) % 2 == 0)calc(tmp, k, res);
	int cur_t[maxn];
	if(!first){
		for(int i = 1; i <= n; ++i)cur_t[i] = tmp[i] ^ b[i];
		per(cur_t, num + 1, true);
	}
	for(int i = 1; i <= n; ++i)cur_t[i] = tmp[p[i]] + r;
	per(cur_t, num + 1, false);
	return 0;
}

void gen(){
	res = -(1LL << 33);
	per(a, 0, false);
}

void output_data(){cout << res << "\n";}

int main(){
	input_data();
	gen();
	output_data();
	return 0;
}