#include <bits/stdc++.h>

using namespace std;
#define maxn 100010

int sa[maxn];
int ta[maxn];
int sb[maxn];
int tb[maxn];
string S, T;

bool check(int a, int b, int c, int d) {
	// cout << "checking  ";
	int sbcount = sb[b]-sb[a-1];
	int tbcount = tb[d]-tb[c-1];
	// cout << S.substr(a, b-a+1) << " " << T.substr(c, d-c+1) << " ";
	int trails = 0;
	int trailt = 0;
	if (sbcount % 2 != tbcount % 2) return false;

	if (sbcount > tbcount) return false;
	if (S[b] == 'A') {
		int lo = a;
		int hi = b;
		while (lo < hi) {
			int mid = (lo+hi)/2;
			if (sa[b]-sa[mid-1] == b-mid+1) {
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}
		// cout << "  lo:  " << lo << " " << sb[lo] << " " << sb[b] << " ";
		trails = b-lo+1;
	}
	if (T[d] == 'A') {
		int lo = c;
		int hi = d;
		while (lo < hi) {
			int mid = (lo+hi)/2;
			if (ta[d]-ta[mid-1] == d-mid+1) {
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}
		trailt = d-lo+1;
	}

	if (tbcount > 0 && sbcount == 0) { //account for no A's being able to create stuff
		if (trails <= trailt) return false;
		return true;
	}

	// cout << " " << trails << " " << trailt;
	if (trails < trailt) return false;
	if (trails == trailt) return true;
	int diff = trails - trailt;
	if (diff % 3 == 0) return true;
	return tbcount > sbcount; //implies a difference multiple of 2 as well

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Q;
	cin >> S >> T >> Q;
	//do one indexing
	S = " " + S;

	T = " " + T;
	int ns = S.length();
	int nt = T.length();
	int a, b, c, d;
	vector<int> ans;
	
	sa[0] = ta[0] = sb[0] = tb[0] = 0;
	for (int i = 1; i < ns; i++) {
		sa[i] = sa[i-1];
		sb[i] = sb[i-1];
		if (S[i] == 'A') {
			sa[i]++;
		}
		else sb[i]++;
	}
	for (int i = 1; i < nt; i++) {
		ta[i] = ta[i-1];
		tb[i] = tb[i-1];
		if (T[i] == 'A') ta[i]++;
		else tb[i]++;
	}
	//construted prefix arrays
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c >> d;
		if (check(a, b, c, d)) {
			ans.push_back(1);
		}
		else ans.push_back(0);
		// cout << endl;

	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
	cin >> Q;
	
}