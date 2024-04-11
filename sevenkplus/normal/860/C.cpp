#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

set<int> EA; // example available
set<int> RA; // regular available
set<string> E, EE; // E in wrong location
set<string> R, RR; // R in wrong location
int e;
int n;
vector<pair<string, int> > inp; // input

string tos(int t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

int toi(string s) {
	int t;
	istringstream iss(s);
	iss >> t;
	return t;
}

int chk(string s) {
	int t = toi(s);
	if (tos(t) == s) return t;
	else return -1;
}

vector<pair<string, string> > S;

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		string s; int t;
		cin >> s >> t;
		e += t;
		inp.pb(mp(s, t));
	}
	
	for (int i = 1; i <= e; i ++)
		EA.insert(i);
	for (int i = e+1; i <= n; i ++)
		RA.insert(i);
	
	for (int i = 0; i < n; i ++) {
		int c = chk(inp[i].fi);
		if (c >= 1 && c <= n) {
			if (c <= e) EA.erase(c);
			else RA.erase(c);
			if ((c <= e) == inp[i].se) continue;
			
			if (inp[i].se) EE.insert(inp[i].fi);
			else RR.insert(inp[i].fi);
			continue;
		}
		if (inp[i].se) E.insert(inp[i].fi);
		else R.insert(inp[i].fi);
	}
	if (E.empty() && R.empty() && EE.empty() && RR.empty()) {
		puts ("0");
		return 0;
	}
	//cout << EA.size() << RA.size() << E.size() << R.size() << EE.size() << RR.size() << endl;
	if (EA.empty() && RA.empty()) {
		string u;
		while (true) {
			u = "";
			for (int i = 0; i < 6; i ++)
				u += (char)('a'+(rand()%26));
			if (E.find(u) == E.end() && R.find(u) == R.end()) break;
		}
		if (!EE.empty()) {
			string c = *EE.begin();
			EE.erase(c);
			E.insert(u);
			RA.insert(toi(c));
			S.pb(mp(c, u));
		} else {
			assert(!RR.empty());
			string c = *RR.begin();
			RR.erase(c);
			R.insert(u);
			EA.insert(toi(c));
			S.pb(mp(c, u));
		}
	}
	
	while (!EA.empty() || !RA.empty()) {
		if (!EE.empty() && !EA.empty()) {
			int y = *EA.begin();
			EA.erase(y);
			string x = *EE.begin();
			EE.erase(x);
			RA.insert(toi(x));
			S.pb(mp(x, tos(y)));
		} else
		if (!RR.empty() && !RA.empty()) {
			int y = *RA.begin();
			RA.erase(y);
			string x = *RR.begin();
			RR.erase(x);
			EA.insert(toi(x));
			S.pb(mp(x, tos(y)));
		} else
		if (!E.empty() && !EA.empty()) {
			int y = *EA.begin();
			EA.erase(y);
			string x = *E.begin();
			E.erase(x);
			S.pb(mp(x, tos(y)));
		} else
		if (!R.empty() && !RA.empty()) {
			int y = *RA.begin();
			RA.erase(y);
			string x = *R.begin();
			R.erase(x);
			S.pb(mp(x, tos(y)));
		} else assert(false);
	}
	cout << S.size() << endl;
	for (int i = 0; i < (int) S.size(); i ++)
		cout << "move " << S[i].fi << " " << S[i].se << endl;
	return 0;
}