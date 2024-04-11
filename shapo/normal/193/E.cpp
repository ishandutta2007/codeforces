#include <iostream>
#include <vector>

#define dvs 100000000LL

using namespace std;

long long to_find, res = -1;
long long mlt[2][2], tmp[2][2], mr[2][2];
long long period[14];

long long mult(const long long &p1, const long long &p2, const long long &md){
	long long a = p1 / dvs, b = p1 % dvs;
	long long c = p2 / dvs, d = p2 % dvs;
	long long tmp = (((dvs * dvs % md) * a  % md) * c % md + (dvs * d % md) * a % md + (dvs * b % md) * c % md + b * d % md) % md;
	return tmp;	
}

long long number(const long long &pos, const long long &p){
	mlt[0][0] = mlt[0][1] = mlt[1][0] = mr[0][0] = mr[1][1] = 1;
	mlt[1][1] = mr[0][1] = mr[1][0] = 0;
	long long cur = pos - 1;
	if(!pos)return 0;
	while(cur){
		if(cur % 2){
			for(int i = 0; i < 2; ++i)
				for(int j = 0; j < 2; ++j){
					tmp[i][j] = 0;
					for(int k = 0; k < 2; ++k)
						tmp[i][j] = (tmp[i][j] + mult(mr[i][k], mlt[k][j], p)) % p;
				}
			for(int i = 0; i < 2; ++i)
				for(int j = 0; j < 2; ++j)
					mr[i][j] = tmp[i][j];
			--cur;
		}
		cur >>= 1;
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j){
				tmp[i][j] = 0;
				for(int k = 0; k < 2; ++k)
					tmp[i][j] = (tmp[i][j] + mult(mlt[i][k], mlt[k][j], p)) % p;
			}
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j)
				mlt[i][j] = tmp[i][j];
	}
	return(mr[0][0]);
}

void init_per(){
	period[1] = 60;
	period[2] = 300;
	period[3] = 1500;
	for(int i = 4; i < 14; ++i)period[i] = period[i - 1] * 10;
}

inline void input_data(){cin >> to_find;}
inline void output_data(){cout << res << "\n";}

int calc(){
	long long cur = 10000000000000LL;
	init_per();
	vector< long long > sm;
	vector< long long > tmp;
	long long cur_n = 10, cur_mod = to_find % cur_n;
	if(!cur_mod)sm.push_back(0);
	if(cur_mod == 1){sm.push_back(1); sm.push_back(2);}
	int mp = 1, pr = 1, itr = 1;
	for(int i = 3; i <= 59; ++i){
		int tmp = (mp + pr) % cur_n;
		if(cur_mod == tmp)sm.push_back(i);
		pr = mp; mp = tmp;
	}
	while(cur_n != cur){
		long long prd = period[itr], next_prd = period[++itr], now = 0;
		cur_n *= 10;
		cur_mod = to_find % cur_n;
		tmp.clear();
		while(now < next_prd){
			for(int i = 0; i < sm.size(); ++i){
				long long nmb = number(sm.at(i) + now, cur_n);
				if(nmb == cur_mod)tmp.push_back(sm.at(i) + now);
			}
			now += prd;
		}
		if(tmp.empty())return 0;
		sm = tmp;
	}
	res = sm.at(0);
	return 0;
}

int main(){
	input_data();
	calc();
	output_data();
	return 0;
}