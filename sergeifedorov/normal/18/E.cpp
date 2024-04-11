#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

const int nmax = 600;

int n,m;
int c1[nmax][26], c2[nmax][26];
int t[nmax][26][26];
pii p[nmax][26][26];
char a[nmax][nmax], b[nmax][nmax];

int main(){
	cin >> n >> m;
	forn(i,n)
		forn(j,m){
			cin >> a[i][j];
			a[i][j] -= 'a';
		}
	memset(t, 255, sizeof t);
	forn(i,n)
		forn(j,26){
			c1[i][j] = 0;
			for (int w = 0; w < m; w += 2)
				if (a[i][w] != j)
					c1[i][j] ++;
		}
	forn(i,n)
		forn(j,26){
			c2[i][j] = 0;
			for (int w = 1; w < m; w += 2)
				if (a[i][w] != j)
					c2[i][j] ++;
		}
			
	forn(j,26)
		forn(k,26)
			if (k != j)
			t[1][j][k] = c1[0][j] + c2[0][k];
	for (int i = 1; i < n; i++)
		forn(j,26)
			forn(k,26)
				forn(e,26)
					forn(w,26)
						if (j != k && e != w && j != e && k != w && (t[i+1][e][w] == -1 || t[i+1][e][w] > t[i][j][k] + c1[i][e] + c2[i][w])){
							t[i+1][e][w] = t[i][j][k] + c1[i][e] + c2[i][w];
							p[i+1][e][w] = mp(j,k);
						}
	int res = 1e9;
	int q,w;
	q = w = 0;
	forn(i,26)
		forn(j,26)
			if (t[n][i][j] != -1 && res > t[n][i][j]){
				res = t[n][i][j];
				q = i;
				w = j;
			}
	cout << res << endl;
	ford(i,n){
		forn(j,m)
			if (j & 1)
				b[i][j] = 'a' + w;
			else
				b[i][j] = 'a' + q;
		forn(j,m)
			if (b[i][j]-'a' != a[i][j]) res--;
		pii r = p[i+1][q][w];
		q = r.fs;
		w = r.sc;
	}
	forn(i,n){
		forn(j,m)
			cout << b[i][j];
		cout << endl;
	}
		



	return 0;
}