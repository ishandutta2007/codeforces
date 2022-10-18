#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

// Very complex based on editorial https://codeforces.com/blog/entry/65295

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// if a(i)^..^a(x) = a(x+1)^..^a(j), then the two sides being equal and Z^Z=0, we have that a(i)^....^a(j)=0
	// so we have to find all ranges of xor-sums a(i)^...^a(j) of even length which are 0
	// we can calculate xor-sums with a prefix array exactly like regular sums

	vector<int> p(n);
	p[0] = a[0];
	// using this array,  the xor sum of i..j is  p[j]^p[i-1] because
	// p[j] = a[0]^...^a[j]
	// = a[0]^...^a[i-1]^a[i]^...^a[j]
	// = p[i-1]^a[i]^...^a[j]
	// use the Z^Z=0 rule again then p[j]^p[i-1] = p[i-1]^(a[i]^...^a[j])^p[i-1] and reorder then p[i-1]^p[i-1] = 0, and also we know Z^0=Z, so that leaves just a[i]^..^a[j]

	// so now we have to compute at each j, how many i there are which satisfy. If j-i+1 is even then j and (i-1) have the same parity
	// We want a[i]^..^a[j] = 0
	// => p[j]^p[i-1] = 0
	// The value p[i-1] which makes the above equation 0 is again just p[j]
	// so we're simply counting how many times p[j] has occurred in the past in indexes of the same parity, each of those is a pair
	// add the counts already record, then, update the current count
	vector<vector<int>> c(2,vector<int>((1<<20)+2, 0));

	c[0][a[0]] = 1;
	c[1][0] = 1; // this is for index i=0, in which case i-1=-1, which is odd, and we need to know count[i-1] in that case but we don't have count[-1] luckily all we care is the parity
	LL res = 0;
	for (int j = 1; j < n; j++) {
		p[j] = a[j] ^ p[j-1];
		res += c[j%2][p[j]]; // p[j] is the value of all the prior p[i-1]'s we want, such that p[i-1]^p[j]= a[i]^..^a[j] = 0. This line adds up the prior counts
		c[j%2][p[j]]++; // now update this count
	}
	cout << res << endl;
	exit(0);
}

//3 2 2 3 7 6
//0,3=1
//i=1: 0
//i=2: 1