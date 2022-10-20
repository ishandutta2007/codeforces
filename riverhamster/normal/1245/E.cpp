#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
typedef long double ld;
const int N = 13;
int h[N][N];
ld f[N][N][2];

void adv(int &x, int &y){
	if(x & 1){
		if(y == 1) --x;
		else --y;
	}
	else{
		if(y == 10) --x;
		else ++y;
	}
}

int main(){
	// File("e");
	for(int i=1; i<=10; i++)
		for(int j=1; j<=10; j++)
			in(h[i][j]);
	for(int i=1; i<=10; i++){
		if(i & 1){
			int sj = 1;
			if(i == 1){
				f[1][1][0] = 0;
				sj = 2;
			}
			for(int j=sj; j<=10; j++){
				f[i][j][0] = 0;
				if(h[i][j]) f[i][j][1] = f[i-h[i][j]][j][0];
				else f[i][j][1] = 1e12;
				ld sum = 0;
				int x = i, y = j;
				ld kf = 0;
				for(int i=1; i<=6; i++){
					adv(x, y);
					// printf("Advance %d: (%d, %d)\n", i, x, y);
					if(x < 1) kf += 1.0 / (ld)6.0, sum += 1.0 / (ld)6.0;
					else sum += (min(f[x][y][0], f[x][y][1]) + 1.0) / (ld)6.0;
				}
				sum /= (1 - kf);
				f[i][j][0] = sum;
				// printf("f[%d][%d] = %.12Lf\n", i, j, f[i][j]);
			}
		}
		else{
			for(int j=10; j>=1; j--){
				f[i][j][0] = 0;
				if(h[i][j]) f[i][j][1] = f[i-h[i][j]][j][0];
				else f[i][j][1] = 1e12;
				ld sum = 0;
				int x = i, y = j;
				ld kf = 0;
				for(int i=1; i<=6; i++){
					adv(x, y);
					if(x < 1) kf += 1.0 / (ld)6.0, sum += 1.0 / (ld)6.0;
					else sum += (min(f[x][y][0], f[x][y][1]) + 1.0) / (ld)6.0;
				}
				sum /= (1 - kf);
				f[i][j][0] = sum;
				// printf("f[%d][%d] = %.12Lf\n", i, j, f[i][j]);
			}
		}
	}
	printf("%.12Lf\n", f[10][1][0]);
	return 0;
}