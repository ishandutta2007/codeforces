#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

int a[10], b[10];
int op[7][3] = {
	{1}, 
	{0, 1},
	{0, 0, 1},
	{1, 1},
	{1, 0, 1},
	{0, 1, 1},
	{1, 1, 1}
};
int BC[1000];

int main(){
	// File("a");
	int T, res = 0;
	gi(T);
	while(T--){
		gi(b[0]); gi(b[1]); gi(b[2]);
		sort(b, b+3);
		res = 0;
		for(int i=0; i<(1<<7); i++){
			BC[i] = BC[i>>1] + (i & 1);
			fill(a, a+3, 0);
			for(int j=0; j<7; j++)
				if((i >> j) & 1)
				for(int k=0; k<3; k++)
					a[k] += op[j][k];
			bool flag = true;
			for(int k=0; k<3; k++)
				if(a[k] > b[k]) flag = false;
			if(flag) res = max(res, BC[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}