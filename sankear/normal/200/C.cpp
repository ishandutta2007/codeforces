#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e3);

bool good[100][100];
int g1[100][100], g2[100][100];
char v[100], u[100];
int x[100], y[100], a[100], b[100], balls[100], cnt1[100], cnt2[100], perm[100];
map <string, int> num;
string name[100];

inline bool cmp(int a, int b){
	if(balls[a] != balls[b]){
		return balls[a] > balls[b];
	}
	if(cnt1[a] - cnt2[a] != cnt1[b] - cnt2[b]){
		return cnt1[a] - cnt2[a] > cnt1[b] - cnt2[b];
	}
	if(cnt1[a] != cnt1[b]){
		return cnt1[a] > cnt1[b];
	}
	return name[a] < name[b];
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	int k = 0;
	for(int i = 0; i < 5; i++){
		scanf("%s %s %d:%d", v, u, &a[i], &b[i]);
		string s = v;
		if(num.find(s) == num.end()){
			name[k] = s;
			num[s] = k++;
		}
		x[i] = num[s];
		s = u;
		if(num.find(s) == num.end()){
			name[k] = s;
			num[s] = k++;
		}
		y[i] = num[s];
	}
	for(int i = 0; i < 5; i++){
		if(x[i] > y[i]){
			swap(x[i], y[i]);
			swap(a[i], b[i]);
		}
		good[x[i]][y[i]] = true;
		cnt1[x[i]] += a[i];
		cnt2[x[i]] += b[i];
		cnt1[y[i]] += b[i];
		cnt2[y[i]] += a[i];
		g1[x[i]][y[i]] = a[i];
		g2[x[i]][y[i]] = b[i];
	}
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 4; j++){
			if(!good[i][j]){
				continue;
			}
			if(g1[i][j] > g2[i][j]){
				balls[i] += 3;
			}
			if(g1[i][j] == g2[i][j]){
				balls[i]++;
				balls[j]++;
			}
			if(g1[i][j] < g2[i][j]){
				balls[j] += 3;
			}
		}
	}
	int X = inf, Y = 0;
	int l = 1, r = inf;
	while(l <= r){
		int mid = (l + r) / 2;
		bool can = false;
		int cl = 0, cr = inf;
		while(cl <= cr){
			int cm = (cl + cr) / 2;
			for(int i = 0; i < 3; i++){
				for(int j = i + 1; j < 4; j++){
					if(!good[i][j]){
						if(name[i] == "BERLAND"){
							balls[i] += 3;
							cnt1[i] += cm + mid;
							cnt2[i] += cm;
							cnt1[j] += cm;
							cnt2[j] += cm + mid;
						}
						else{
							balls[j] += 3;
							cnt1[j] += cm + mid;
							cnt2[j] += cm;
							cnt1[i] += cm;
							cnt2[i] += cm + mid;
						}
					}
				}
			}
			for(int i = 0; i < 4; i++){
				perm[i] = i;
			}
			sort(perm, perm + 4, cmp);
			if(name[perm[0]] == "BERLAND" || name[perm[1]] == "BERLAND"){
				if(mid < X - Y || (mid == X - Y && cm < Y)){
					Y = cm;
					X = cm + mid;
				}
				cr = cm - 1;
				can = true;
			}
			else{
				cl = cm + 1;
			}
			for(int i = 0; i < 3; i++){
				for(int j = i + 1; j < 4; j++){
					if(!good[i][j]){
						if(name[i] == "BERLAND"){
							balls[i] -= 3;
							cnt1[i] -= cm + mid;
							cnt2[i] -= cm;
							cnt1[j] -= cm;
							cnt2[j] -= cm + mid;
						}
						else{
							balls[j] -= 3;
							cnt1[j] -= cm + mid;
							cnt2[j] -= cm;
							cnt1[i] -= cm;
							cnt2[i] -= cm + mid;
						}
					}
				}
			}
		}
		if(can){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	if(X == inf){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	printf("%d:%d\n", X, Y);
	return 0;
}