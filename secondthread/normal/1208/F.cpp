
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1<<21, maxBits=21;
typedef pair<int, int> ii;

//dp[i]=rightmost index of a superset of i
//dp2[i]=secondRightmost index of some superset of i
ii dp[maxn];

ii merge(ii a, ii b) {
	if (a.first>b.first) {
		return {a.first, max(b.first, a.second)};
	}
	return {b.first, max(a.first, b.second)};
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];
	vector<int> rightmostIndexOf(maxn, -1), secondRightmostIndexOf(maxn, -1);
	for (int i=0; i<n; i++)
		rightmostIndexOf[a[i]]=i;
	for (int i=0; i<n; i++)
		if (rightmostIndexOf[a[i]]!=i)
			secondRightmostIndexOf[a[i]]=i;

	for (int i=0; i<maxn; i++)
		dp[i]={rightmostIndexOf[i], secondRightmostIndexOf[i]};
	for (int canChange=0; canChange<maxBits; canChange++) {
		for (int i=0; i<maxn; i++) {
			if ((i&(1<<canChange))==0) {
				dp[i]=merge(dp[i], dp[i+(1<<canChange)]);
			}
		}
	}
	int best=0;
	for (int aIndex=0; aIndex+2<n; aIndex++) {
		int requiredMask=0;
		int aVal=a[aIndex];
		for (int bit=maxBits-1; bit>=0; bit--) {
			if (aVal&(1<<bit)) continue;
			int newRequiredMask=requiredMask+(1<<bit);	
			if (dp[newRequiredMask].second>aIndex) {
				requiredMask=newRequiredMask;
			}
		}
		best=max(best, requiredMask|aVal);
	}
	cout<<best<<'\n';

	return 0;
}