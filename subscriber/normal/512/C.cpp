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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
vector<int> A, B, aa, bb;
int q[555][555];
int in[555][555];
int S, T;
int f[555];

void er() {
	puts("Impossible");
	exit(0);
}

bool prime(int x) {
	for (int i = 2; i < x; i++) if (x % i == 0) return 0;
	return 1;
}

void ae(int x, int y, int f) {
	q[x][y] += f;
	in[x][y] += f;
}

void rec(int x) {
	for (int i = 0; i <= T; i++) if (q[x][i] > 0 && f[i] == -1) {
		f[i] = x;
		rec(i);
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);		
		if (x % 2) {
			A.pb(x);
			aa.pb(i);
		}			
	        else {
	        	B.pb(x);
	        	bb.pb(i);
		}	        	
	}
	if (A.size() != B.size()) er();

	S = 0;
	T = 1 + A.size() + B.size();

	for (int i = 0; i < A.size(); i++) ae(S, i + 1, 2);

	for (int i = 0; i < A.size(); i++) for (int j = 0; j < B.size(); j++) 
		if (prime(A[i] + B[j])) ae(i + 1, 1 + A.size() + j, 1);

	for (int i = 0; i < B.size(); i++) ae(1 + A.size() + i, T, 2);

	int fl = 0;
	for(;;) {
		for (int i = 0; i <= T; i++) f[i] = -1;
		rec(S);
		if (f[T] == -1) break;
		fl++;
		int x = T;
		while (x != S) {
			q[f[x]][x]--;
			q[x][f[x]]++;
			x = f[x];
		}
	}
	if (fl != A.size() * 2) er();
	vector<vector<int> > ans;

	for (int i = 0; i < A.size(); i++) f[i] = 0;

	for (int i = 0; i < A.size(); i++) if (!f[i]) {
		vector<int> t;

		int x = i;
		int pr = -1;

		for(;;) {
			f[x] = 1;

			t.pb(aa[x]);
			int g = -1;
			for (int j = 0; j < B.size(); j++) if (q[x + 1][1 + A.size() + j] < in[x + 1][1 + A.size() + j] && j != pr) g = j;
			t.pb(bb[g]);

			pr = x;

			for (int j = 0; j < A.size(); j++) if (q[1 + j][1 + A.size() + g] < in[1 + j][1 + A.size() + g] && j != pr) x = j;

			pr = g;
			if (x == i) break;
		}
		ans.pb(t);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size();
		for (int j = 0; j < ans[i].size(); j++) printf(" %d", ans[i][j] + 1);
		puts("");
	}
			
	return 0;
}