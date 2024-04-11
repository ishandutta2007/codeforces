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

vector<int> order;
int comp[N], was[N];

string al, s;

int n, m;
int p1[N], p2[N];
char t1[N], t2[N];

vector<int> v[N], rev[N];

void go(int x) {
	if (was[x]) return;
	was[x] = 1;
	for (int i = 0; i < v[x].size(); i++) go(v[x][i]);
	order.pb(x);
}

void col(int x, int o) {
	if (comp[x] != -1) return;
	comp[x] = o;
	for (int i = 0; i < rev[x].size(); i++) col(rev[x][i], o);
}

int can(string w) {

	for (int i = 0; i < n; i++) if (w[i] != '?') {
		if (al[w[i] - 'a'] == 'V') {
			v[i + n].pb(i); 
			rev[i].pb(i + n);
		}
		else {
			v[i].pb(i + n);
			rev[i + n].pb(i);
		}			
        }

        order.clear();
        for (int i = 0; i < n * 2; i++) was[i] = 0, comp[i] = -1;
        for (int i = 0; i < n * 2; i++) if (!was[i]) go(i);
        reverse(order.begin(), order.end());

        int comps = 0;
        for (int i = 0; i < 2 * n; i++) if (comp[order[i]] == -1) {
        	comps++;
        	col(order[i], comps);
        }
	for (int i = 0; i < n; i++) if (w[i] != '?') {
		if (al[w[i] - 'a'] == 'V') {
			v[i + n].pop_back(); 
			rev[i].pop_back();
		}
		else {
			v[i].pop_back();
			rev[i + n].pop_back();
		}			
        }

        
        for (int i = 0; i < n; i++) if (comp[i] == comp[i + n]) return 0;
        return 1;

}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	int nq = 0;
	cin >> al;
	for (int i = 1; i < al.size(); i++) if (al[i] != al[i - 1]) nq = 1;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> p1[i] >> t1[i] >> p2[i] >> t2[i];	
		p1[i]--;
		p2[i]--;
	}		
	for (int i = 0; i < m; i++) {
		int x = p1[i];
		int y = p2[i];

		if (t1[i] == 'C') x += n;
		if (t2[i] == 'C') y += n;

		v[x].pb(y);
		rev[y].pb(x);
		
		int xx = x;
		int yy = y;
		if (xx < n) xx += n; else xx -= n;
		if (yy < n) yy += n; else yy -= n;
		v[yy].pb(xx);
		rev[xx].pb(yy);
		
	}
	


	cin >> s;
	if (can(s)) {
		cout << s << endl;
		return 0;
	} else if (nq == 0) {
		puts("-1");
		return 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		int s1 = 0, s2 = 0;
		for (char c = s[i] + 1; c < al.size() + 'a'; c++) {
			if (al[c - 'a'] == 'V') {
				if (s1) continue; else s1 = 1;
			} else{
				if (s2) continue; else s2 = 1;
			}

			string t = s;
			t[i] = c;
			for (int j = i + 1; j < n; j++) t[j] = '?';
			if (can(t)) {
				for (int j = i + 1; j < n; j++) {
					int ss1 = 0, ss2 = 0;
					for (int c = 'a'; c < al.size() + 'z'; c++) {
						if (al[c - 'a'] == 'V') {
							if (ss1) continue; else ss1 = 1;
						} else {
							if (ss2) continue; else ss2 = 1;
						}

						t[j] = c;
						if (can(t)) break;
					}
				}
				cout << t << endl;
				return 0;
			}
		}				
	}
	puts("-1");
	return 0;
}