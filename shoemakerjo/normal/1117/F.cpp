#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const int mp = 17; //max p
int n, p;

bool bad[1 << mp];

bool ok[17][17];

int lastind[17];
int cmask[17]; //mask between me and last seen
int ct[17];
int nums[maxn];

int delt[1 << 17]; //should be good i think

int cb[1 << 17];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p;	
	string st; cin >> st; st = " " + st;
	for (int i = 1; i <= n; i++) {
		nums[i] = st[i]-'a';
		ct[nums[i]]++;
	}
	for (int i  = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			cin >> ok[i][j];
		}
	}

	fill(lastind, lastind+17, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < p; j++) {
			if (lastind[j] == 0) continue;

			int cm = cmask[j];
			if (cm & (1 << nums[i])) continue; //not adjacent
			if (ok[nums[i]][j]) continue; //nothing bad

			// cout << cm << " is bad " << endl;
			bad[cm] = true; //this is a bad mask

			delt[cm]--;
			delt[cm | (1 << nums[i])]++;
			delt[cm | (1 << j)]++;
			delt[cm | (1 << nums[i]) | (1 << j)]--;

			//this mask is bad
			//this is also bad if i add anything to it??
			//if i add not eqaul to either end it is bad

		}
		lastind[nums[i]] = i;
		// cmask[nums[i]] = 0;
		for (int j = 0; j < p; j++) {
			cmask[j] |= 1 << nums[i];
		}
		cmask[nums[i]] = 0;

	}
	//do not need to run back b/c it will be covered in first

	int ans = n;

	//p * p * n is 34 mil (can go in array even)
	//the subset thing is 120 mil

	//idea: have a bad count thing
	//contribution of cm is 1
	//contribution of cm | lval is -1
	//contribution of cm | rval is -1
	//contribution of cm | lval | rval is 1

	for (int i = 1; i < (1 << p); i++) {

		//do the subset thing
		//loop over all subsets of i
		//s = i, s = (s-1) & i

		for  (int mm = i; mm >= 0; mm = (mm-1) & i) {
			cb[i] += delt[mm];
			if (mm == 0) break;
		}

		if (cb[i] < 0) bad[i] = true;

		if (bad[i]) continue;
		bool hasg = false;
		for (int j = 0; j < p; j++) {
			if (i & (1 << j)) {
				if (!bad[i-(1 << j)]) {
					hasg = true;
					break;
				}
			}
		}
		if (!hasg) bad[i] = true;
		if (!bad[i]) {

			// cout << i << " is ok" << endl;

			int res=  n;
			for (int j = 0; j < 17; j++) {
				if (i & (1 << j)) res -= ct[j];
			}
			ans = min(ans, res);
		}

	}
	cout << ans << endl;
}