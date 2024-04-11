
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll mod=998244353;
struct Num {
	ll val;
	Num(ll val): val(val) {}
	Num operator+(const Num& o) const {return Num((val+o.val)%mod);}
	Num operator-(const Num& o) const {return Num(((val-o.val)%mod+mod)%mod);}
	Num operator*(const Num& o) const {return Num((val*o.val)%mod);}
};

Num countWaysToSort(vector<ii> a) {
	sort(a.begin(), a.end());
	Num ways(1);
	int prevEqual=1;
	for (int i=1; i<a.size(); i++) {
		if (a[i]==a[i-1])
			prevEqual++;
		else
			prevEqual=1;
		ways=ways*Num(prevEqual);
		if (a[i].first<a[i-1].first || a[i].second<a[i-1].second)
			ways=Num(0);
	}
	return ways;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<ii> input;
	for (int i=0; i<n; i++) {
		int a, b; cin>>a>>b;
		input.push_back({a, b});
	}
	vector<ii> firstErased, secondErased;
	for (int i=0; i<n; i++) {
		firstErased.push_back({0, input[i].second});
		secondErased.push_back({input[i].first, 0});
	}
	Num ans=countWaysToSort(firstErased)+countWaysToSort(secondErased)-countWaysToSort(input);
	ll fact=1;
	for (int i=2; i<=n; i++) {
		fact=fact*i%mod;
	}
	ans=Num(fact)-ans;
	cout<<ans.val<<'\n';

	return 0;
}