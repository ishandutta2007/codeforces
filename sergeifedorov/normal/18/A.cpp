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

int px[] = {0,1,0,-1};
int py[] = {1,0,-1,0};

pii a[3];

long long dist(pii a, pii b){
	return sqr(a.fs - b.fs) + sqr(a.sc - b.sc);
}

bool good(pii a, pii b, pii c){
	vector<long long> e;
	e.pb(dist(a,b));
	e.pb(dist(b,c));
	e.pb(dist(a,c));
	sort(all(e));
	return e[0] + e[1] == e[2] && a != b && a != c && b != c;
}

int main(){
//	freopen(inp.data(), "rt", stdin);
//	freopen(oup.data(),"wt", stdout);

	forn(i,3)
		cin >> a[i].fs >> a[i].sc;
	if (good(a[0],a[1],a[2])){
		puts("RIGHT");
		exit(0);
	}
	forn(i,3)
		forn(j,4){
			a[i].fs += px[j];
			a[i].sc += py[j];
			if (good(a[0],a[1],a[2])){
				puts("ALMOST");
				exit(0);
			}
			a[i].fs -= px[j];
			a[i].sc -= py[j];
			
		}
	puts("NEITHER");




	return 0;
}