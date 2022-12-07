#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;


map<int, int> w1, w2;
map<pair<int, int>, int> w3;
int n;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	long long s1 = 0;
	long long s2 = 0;
	long long s3 = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		s1 += w1[x];
		w1[x]++;
		s2 += w2[y];
		w2[y]++;
		
		s3 += w3[mp(x, y)];
		w3[mp(x, y)]++;
	}
	cout << s1 + s2 - s3 << endl;

	return 0;
}