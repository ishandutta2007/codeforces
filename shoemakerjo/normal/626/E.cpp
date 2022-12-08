#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define ll long long
vector<ll> nums;
ll pref[maxn];
int n; //need it as a global

ll query(int qs, int qe) {
	if (qs > qe) return 0LL;
	return pref[qe] - pref[qs-1]; //should be easier this way
}

double getdiff(int med, int take) {
	if (take < 0) {
		return -1.0; //negative val is always worse
	}
	int loval = med-take;

	int hival = n-take+1; //plus one
	double ct = 1.0+take*2.0;
	double sum = query(loval, med) + query(hival, n);
	double avg =  sum/(ct); //this should be the average
	double cur = nums[med];
	double ans = avg - cur;
	return ans; //get the difference
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	nums.push_back(-1); //allow for 1-indexing
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	pref[0] = 0LL;
	for (int i  = 1; i <= n; i++) {
		pref[i] = pref[i-1] + nums[i];
	}
	double best = -1.0;
	int med = 0; //the median value, this will be the index of it in the array
	int take = 0; //number we take past this guy (multiply by two)

	for (int i = 1; i <= n; i++) {
		int lo  = 0;
		int hi = min(i-1, n-i); //set reasonable bounds for the array
		while (lo < hi) {
			int mid = (lo+hi+1)/2;
			double d = getdiff(i, mid); 
			double d2 = getdiff(i, mid-1);
			if (d > d2) {
				lo = mid;
			}
			else hi = mid-1;
		}
		double val = getdiff(i, lo); 
		if (val > best) {
			best = val;
			med = i;
			take = lo;
		}
	}
	cout << 1 + 2*take << endl;
	for (int i = med-take; i <= med; i++) {
		cout << nums[i] << " ";
	}
	for (int i = n-take+1; i <= n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	cin >> n;

}