#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int kN = 1e6 + 7;

const int kCntHashes = 1;
const ll kBase[kCntHashes]{29};
const ll kMod[kCntHashes]{(ll)1e9 + 9};

struct MultipleHash{
	array<ll, kCntHashes> hashes;

	MultipleHash(ll val = 0){
		for(ll &x: hashes)
			x = val;
	}

	friend MultipleHash operator+(MultipleHash lvalue, long long rvalue){
		MultipleHash ret;
		for(int i = 0; i < kCntHashes; ++i){
			ret.hashes[i] = lvalue.hashes[i] + rvalue;
			ret.hashes[i] %= kMod[i];
		}
		return ret;
	}

	friend MultipleHash operator*(MultipleHash lvalue, long long rvalue){
		MultipleHash ret;
		for(int i = 0; i < kCntHashes; ++i){
			ret.hashes[i] = lvalue.hashes[i] * rvalue;
			ret.hashes[i] %= kMod[i];
		}
		return ret;
	}

	friend MultipleHash operator*(MultipleHash lvalue, MultipleHash rvalue){
		MultipleHash ret;
		for(int i = 0; i < kCntHashes; ++i){
			ret.hashes[i] = lvalue.hashes[i] * rvalue.hashes[i];
			ret.hashes[i] %= kMod[i];
		}
		return ret;
	}

	friend MultipleHash operator-(MultipleHash lvalue, MultipleHash rvalue){
		MultipleHash ret;
		for(int i = 0; i < kCntHashes; ++i){
			ret.hashes[i] = lvalue.hashes[i] - rvalue.hashes[i];
			ret.hashes[i] += kMod[i];
			ret.hashes[i] %= kMod[i];
		}
		return ret;
	}

	friend MultipleHash operator+(MultipleHash lvalue, MultipleHash rvalue){
		MultipleHash ret;
		for(int i = 0; i < kCntHashes; ++i){
			ret.hashes[i] = lvalue.hashes[i] + rvalue.hashes[i];
			ret.hashes[i] %= kMod[i];
		}
		return ret;
	}

	friend MultipleHash multiply_by_base(MultipleHash x){
		MultipleHash ret;
		for(int i = 0; i < kCntHashes; ++i){
			ret.hashes[i] = x.hashes[i] * kBase[i];
			ret.hashes[i] %= kMod[i];
		}
		return ret;
	}

	friend bool operator==(MultipleHash lvalue, MultipleHash rvalue){
		for(int i = 0; i < kCntHashes; ++i)
			if(lvalue.hashes[i] != rvalue.hashes[i])
				return false;
		return true;
	}
};

MultipleHash prefix[kN], suffix[kN], base_power[kN];
int mx1[kN], mx2[kN];
string s;
int n;

MultipleHash get_prefix_sum(int l, int r){
	if(!l)
		return prefix[r] * base_power[n - 1];
	return (prefix[r] - prefix[l - 1]) * base_power[n - 1 - l];
}

MultipleHash get_suffix_sum(int l, int r){
	if(r == n - 1)
		return suffix[l] * base_power[n - 1];
	return (suffix[l] - suffix[r + 1]) * base_power[r];
}

void solve(){
	cin >> s;

	n = s.size();

	base_power[0] = MultipleHash(1);
	for(int i = 1; i <= n; ++i)
		base_power[i] = multiply_by_base(base_power[i - 1]);

	prefix[0] = s[0] - 'a' + 1;
	for(int i = 1; i < n; ++i){
		prefix[i] = prefix[i - 1] + base_power[i] * ((ll)(s[i] - 'a' + 1));
	}

	suffix[n - 1] = s[n - 1] - 'a' + 1;
	for(int i = n - 2; i >= 0; --i){
		suffix[i] = suffix[i + 1] + base_power[n - 1 - i] * ((ll)(s[i] - 'a' + 1));
	}

	int k = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] != s[n - i - 1])
			break;
		++k;
	}

	if(k == n){
		cout << s << "\n";
		return ;
	}

	int l = k, r = n - 1 - k;
	int left_max = 0, right_max = 0;
	for(int i = r; i >= l; --i){
		if(get_suffix_sum(l, i) == get_prefix_sum(l, i)){
			left_max = i - l + 1;
			break;
		}
	}
	for(int i = l; i <= r; ++i){
		if(get_suffix_sum(i, r) == get_prefix_sum(i, r)){
			right_max = r - i + 1;
			break;
		}
	}

	for(int i = 0; i < l; ++i)
		cout << s[i];
	if(left_max >= right_max){
		for(int i = l; i < l + left_max; ++i)
			cout << s[i];
	}
	else{
		for(int i = r - right_max + 1; i <= r; ++i)
			cout << s[i];
	}
	for(int i = r + 1; i < n; ++i)
		cout << s[i];
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}