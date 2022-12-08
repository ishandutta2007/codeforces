#include <bits/stdc++.h>

using namespace std;
const int tho = 10000; //just a sum variable

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());

	double dp[tho+1]; //pluys one b/c zero index
	fill(dp, dp+tho+1, 0.0); //ways to get here after two

	double count[tho+1]; //just the count of this number
	fill(count, count+tho+1, 0.0); //seems familiar
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i+1; j < nums.size(); j++) {
			count[nums[j]-nums[i]]++; //count is the same as ways to get here after 1
		}
		
	}
	for (int i = 0; i <= tho; i++) { //should run in one second
		for (int j = 1; j < i; j++) { //no zero allowed (fixed it here)
			dp[i] += count[j]*count[i-j]; //either order 
		}
	}
	
	double sum = 0.0;
	double running = 0.0;
	for (int i = 0; i <= tho; i++) {
		sum += count[i]*running;
		running += dp[i];
	}
	double tot = (n+0.0)*(n+0.0)*(n+0.0)*(n-1.0)*(n-1.0)*(n-1.0)/8.0;
	double ans = sum/tot;
	cout << fixed << setprecision(10) << ans << endl;
	// cout << sum << "   " << tot << endl;
	cin >> n;
}