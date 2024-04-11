// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }
typedef long long LL;

#define all(o) o.begin(), o.end()
typedef pair<int,int> pii;

const int N = (int) 0, mod = (int) 0;
const int maxn = 212;
const int M = 200;
int par[4][4][maxn][maxn]; // score of losing
int lost[4][4][maxn][maxn];
bool mark[4][4][maxn][maxn];
void dj(int p0, int p1,int s0,int s1,int val,int lo);
void dfs(int p0,int p1,int s0,int s1){
	//cout << p0 << " " << p1 << " " << s0 << " " << s1 << endl;
	//if(p0 == 2 && p1 == 0)
	//	cout << p0 << " " << p1 << " " << s0 << " " << s1 << endl;	
	if(p0 >= 3 || p1 >= 3){
		mark[p0][p1][s0][s1] = 1;
		return;
	}
	if(mark[p0][p1][s0][s1])
		return;
	mark[p1][p1][s0][s1] = 1;
	int cur = p0 + p1;
	int lim = (cur == 4 ? 15 : 25);
	for(int i=0; i<=lim - 2; i++){
		dj(p0 + 1, p1, lim + s0, i + s1, i, 1);
		dj(p0, p1 + 1, i + s0, lim + s1, i, 0);
	}
	for(int i=lim - 1; i<200; i++){
		dj(p0 + 1, p1, i+2 + s0, i + s1, i, 1);
		dj(p0, p1 + 1, i + s0, i+2 + s1, i, 0);
	}
}
void dj(int p0, int p1,int s0,int s1,int val,int lo){
	if(s0 > M || s1 > M)
		return;
	if(par[p0][p1][s0][s1] != -1)
		return;
	par[p0][p1][s0][s1] = val;
	lost[p0][p1][s0][s1] = lo;
	dfs(p0, p1, s0, s1);
}
string ans[maxn][maxn];
string toS(int i){
	if(i == 0)
		return "0";
	string res;
	while(i){
		int x = i % 10;
		res += char('0' + x);
		i /= 10;
	}
	reverse(all(res));
	return res;
}
string ans2[maxn][maxn];
int main() {
	int q;
	cin >> q;
	memset(par, -1, sizeof par);	
	par[0][0][0][0] = 0;
	dfs(0, 0, 0, 0);
	//cout << par[3][0][75][0] << endl;
	//cout << mark[3][0][76][0] << endl;
	for(int i=0; i<=200; i++){
		for(int j=0; j<=200; j++){
			int can = 0;
			/*if(i == 75 && j == 0)
				cout << "SPE" << endl;*/
			for(int d=3; d>=-3 && !can; d--){
				for(int a=3; a>=0 && !can; a--){
					int b = a - d;
					if(b < 0 || b > 3) continue;
					if(a != 3 && b != 3)
						continue;
					if(mark[a][b][i][j]){
						/*if(i == 75 && j == 0){
							cout << "A" << a << " " << b << endl;
						}*/
						can = 1;
						int cur = a + b;
						string res = "";
						int ii = i, jj = j;
						int A = a, B = b;
						while(cur){
							int x = par[a][b][ii][jj];
							int lo = lost[a][b][ii][jj];
							int lim = (cur != 5 ? 25 : 15);
							int win = (x <= lim - 2 ? lim : x + 2);
							//if(i == 75 && j == 0)
							//	cout << x << "xwin " << win << endl;
							if(lo == 0){
								if(res != "")
									res  = ' ' + res;
								res = toS(x) + ":" + toS(win) + res;
								ii -= x;
								jj -= win;
								b--;
							}
							else{
								if(res != "")
									res = ' ' + res;
								res = toS(win) + ":" + toS(x) + res;	
								jj -= x;
								ii -= win;
								a--;
							}
							cur--;
						}
						ans[i][j] = res;
						ans2[i][j] = toS(A) + ":" + toS(B);
					}
				}
			}
			if(can == 0)
				ans[i][j] =  "Impossible";
				
		}
	}
	for(int i=0; i<q; i++){
		int x, y;
		cin >> x >> y;
		if(ans[x][y][0] == 'I')
			cout << ans[x][y];
		else{
			cout << ans2[x][y] << endl;
			cout << ans[x][y];
		}
		cout << endl;
	}
}