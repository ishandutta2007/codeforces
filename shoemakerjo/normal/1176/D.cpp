#include <bits/stdc++.h>

using namespace std;

const int mil3 = 3000000;
const int maxn = 200010;
int n;

bool comp[mil3+10];
int maxfact[mil3+10];
int nums[2*maxn];
vector<int> primes;

void sieve() {
	for (int i = 2; i <= mil3; i++) {
		if (!comp[i]) primes.push_back(i);
		for (int j = i+i; j <= mil3; j += i) {
			maxfact[j] = i;
			comp[j] = true;
		}
	}
}

multiset<int> ccomp;
multiset<int> cprime;
vector<int> res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();

	//extract all composites
	//use a multiset for them
	cin >> n;
	for (int i = 1; i <= 2*n; i++) {
		cin >> nums[i];
		if (comp[nums[i]]) ccomp.insert(nums[i]);
		else cprime.insert(nums[i]);
	}

	// cout << "START" << endl;

	while (ccomp.size()) {
		//grab the largest one
		int v = *(ccomp.rbegin());
		ccomp.erase(ccomp.find(v));
		res.push_back(v);
		int cv = maxfact[v];

		// cout << v << " : " << cv << endl;
		if (comp[cv]) {
			ccomp.erase(ccomp.find(cv));
		}
		else cprime.erase(cprime.find(cv));
	}
	// cout << "HERE" << endl;
	// sort(res.begin(), res.end());

	//now we just have a set of primes
	//each one points to another guy
	//if degree is 0, I am obviously in left part
	primes.insert(primes.begin(), -1); //just for 1-indexing
	//always point to something bigger than me
	//this means we can just take out the smallest prime each time
	while (cprime.size()) {
		int v = *(cprime.begin());
		cprime.erase(cprime.find(v));
		res.push_back(v);
		cprime.erase(cprime.find(primes[v]));
	}

	sort(res.begin(), res.end());
	for (int vv : res) {
		cout << vv << " ";
	}
	cout << endl;
}