#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int a[1010][1010];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int x;
	scanf("%d", &x);
	int ans = inf;
	for(int i = 1; i <= 30; i++){
		for(int j = 0; j < 2; j++){
			int sum = 0;
			for(int z = 0; z < i; z++){
				for(int h = 0; h < i; h++){
					a[z][h] = (j + z + h) % 2;
					if(z < i - 1 && h < i - 1){
						sum += 4 * a[z][h];
					}
					else{
						if(z == i - 1 && h == i - 1){
							sum += a[z][h];
						}
						else{
							sum += 2 * a[z][h];
						}
					}
					if(sum > x){
						if(z < i - 1 && h < i - 1){
							sum -= 4 * a[z][h];
						}
						else{
							if(z == i - 1 && h == i - 1){
								sum -= a[z][h];
							}
							else{
								sum -= 2 * a[z][h];
							}
						}
						a[z][h] = 0;
					}
				}
			}
			for(int z = 0; z < 2 * i - 1; z++){
				for(int h = 0; h < 2 * i - 1; h++){
					if(z < i && h < i){
						continue;
					}
					if(z < i){
						a[z][h] = a[z][2 * i - h - 2];
						continue;
					}
					if(h < i){
						a[z][h] = a[2 * i - z - 2][h];
						continue;
					}
					a[z][h] = a[z][2 * i - h - 2];
				}
			}
			bool fl = true;
			for(int z = 0; z < 2 * i - 1 && fl; z++){
				for(int h = 0; h < 2 * i - 1 && fl; h++){
					if(a[z][h] != 1){
						continue;
					}
					for(int t = 0; t < 4; t++){
						int nz = z + dx[t], nh = h + dy[t];
						if(nz >= 0 && nz < 2 * i - 1 && nh >= 0 && nh < 2 * i - 1 && a[nz][nh] == 1){
							fl = false;
							break;
						}
					}
				}
			}
			if(fl){
				int sum = 0;
				for(int z = 0; z < 2 * i - 1; z++){
					for(int h = 0; h < 2 * i - 1; h++){
						sum += a[z][h];
					}
				}
				if(sum == x){
					ans = min(ans, 2 * i - 1);
				}
			}
			sum = 0;
			for(int z = 0; z < i; z++){
				for(int h = 0; h < i; h++){
					a[z][h] = (j + z + h) % 2;
					sum += 4 * a[z][h];
					if(sum > x){
						sum -= 4 * a[z][h];
						a[z][h] = 0;
					}
				}
			}
			for(int z = 0; z < 2 * i; z++){
				for(int h = 0; h < 2 * i; h++){
					if(z < i && h < i){
						continue;
					}
					if(z < i){
						a[z][h] = a[z][2 * i - h - 1];
						continue;
					}
					if(h < i){
						a[z][h] = a[2 * i - z - 1][h];
						continue;
					}
					a[z][h] = a[z][2 * i - h - 1];
				}
			}
			fl = true;
			for(int z = 0; z < 2 * i && fl; z++){
				for(int h = 0; h < 2 * i && fl; h++){
					if(a[z][h] != 1){
						continue;
					}
					for(int t = 0; t < 4; t++){
						int nz = z + dx[t], nh = h + dy[t];
						if(nz >= 0 && nz < 2 * i && nh >= 0 && nh < 2 * i && a[nz][nh] == 1){
							fl = false;
							break;
						}
					}
				}
			}
			if(fl){
				int sum = 0;
				for(int z = 0; z < 2 * i; z++){
					for(int h = 0; h < 2 * i; h++){
						sum += a[z][h];
					}
				}
				if(sum == x){
					ans = min(ans, 2 * i);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}