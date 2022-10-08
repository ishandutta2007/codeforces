#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
struct BIT {
	int n;
	vector<T> a;

	BIT(int n): n(n), a(vector<T>(n+1, 0)) {}

	T query(int i)  {
		assert(i>=0 && i<n);
		T sum=0;
		for (++i; i; i-=i&-i) sum+=a[i];
		return sum;
	}
	
	void update(int i, T by) {
		if (i<0 || i>=n) cout<<" i: "<<i<<" when n: "<<n<<endl;
		assert(i>=0 && i<n);
		for (++i; i<=n; i+=i&-i) a[i]+=by;
	}

	T query(int from, int to) {
		if (to==from-1) return 0;
		assert(from<=to);
		if (from==0) return query(to);
		return query(to)-query(from-1);
	}
};

const int maxn=5001;
const ll mod=998244353;
//ways of doing x, maxZeros, placedMax?
int dp[maxn][maxn][2];
int main() {
	int n, maxSquareSize; cin>>n>>maxSquareSize;
	for (int maxZeros=0; maxZeros<=n; maxZeros++) {
		BIT<ll> haventPlacedMax(n+1);
		BIT<ll> havePlacedMax(n+1);
		dp[n][maxZeros][1]=1;
		dp[n][maxZeros][0]=0;
		havePlacedMax.update(n, 1);
		for (int i=n-1; i>=0; i--) {
			//haven't placed max
			ll ways=0;
			if (maxZeros!=0) {
				//these are the index of the one
				int leftmostEnd=i, rightmostEnd=min(i+maxZeros-1, n-1);
				if (leftmostEnd<=rightmostEnd) {
					ll queryRes=haventPlacedMax.query(leftmostEnd+1, rightmostEnd+1);
					ways+=queryRes;
					ways%=mod;
				}
			}
			//try placing maxZeros
			if (i+maxZeros<n) {
				ways+=dp[i+maxZeros+1][maxZeros][1];
				ways%=mod;
			}
			dp[i][maxZeros][0]=(int)ways;
			//cout<<"Dp["<<i<<"]["<<maxZeros<<"][0] = "<<ways<<endl;
			haventPlacedMax.update(i, ways);

			//have placed max
			ways=0;
			int leftmostEnd=i, rightmostEnd=min(i+maxZeros, n-1);
			ll queryRes=havePlacedMax.query(leftmostEnd+1, rightmostEnd+1);
			ways=(ways+queryRes)%mod;
			dp[i][maxZeros][1]=(int)ways;
			havePlacedMax.update(i, ways);
			//cout<<"Dp["<<i<<"]["<<maxZeros<<"][1] = "<<ways<<endl;
		}
	}

	ll ans=0;
	for (int leftZeros=0; leftZeros+1<min(n+1, maxSquareSize); leftZeros++) {
		int leftWidth=leftZeros+1;
		int maxRightWidth=(maxSquareSize-1)/leftWidth;
		int rightZeros=maxRightWidth-1;
		rightZeros=min(rightZeros, n);
		ans+=dp[0][leftZeros][0]*(ll)dp[0][rightZeros][1];
		//cout<<"With leftmost zeros: "<<leftZeros<<" we get "<<
			//dp[0][leftZeros][0]*dp[0][rightZeros][1]<<endl;
		//cout<<"Right zeros: "<<rightZeros<<endl;
		ans%=mod;
	}
	//top left could be black or white
	ans=ans*2%mod;
	cout<<ans<<endl;
	return 0;
}