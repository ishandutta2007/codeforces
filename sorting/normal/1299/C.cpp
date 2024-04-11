#include <bits/stdc++.h>

using namespace std;

const long long kMaxN = 1e6 + 7;
long long a[kMaxN], prefix[kMaxN];
pair<long long, long long> fraction[kMaxN];

long long find_sum(long long l, long long r){
	if(l)
		return prefix[r] - prefix[l - 1];
	return prefix[r];
}

bool smaller(pair<long long, long long> a, pair<long long, long long> b){
	return a.first * b.second < b.first * a.second;
}

bool smaller_or_equal(pair<long long, long long> a, pair<long long, long long> b){
	return a.first * b.second <= b.first * a.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	for(long long  i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		fraction[i] = {1, 0};

	prefix[0] = a[0];
	for(long long i = 1; i < n; ++i)
		prefix[i] = prefix[i - 1] + a[i];

	vector<long long> idx;
	idx.push_back(0);
	fraction[0] = {a[0], 1};
	for(int i = 1; i < n; ++i){
		long long sum = find_sum(idx.back(), i), cnt = i - idx.back() + 1;
		long long idx_back = idx.back();
		while(smaller({sum, cnt}, fraction[idx.back()])){
			idx_back = idx.back();
			idx.pop_back();
			fraction[idx_back] = {sum, cnt};
			if(idx.empty())
				break;
			sum = find_sum(idx.back(), i), cnt = i - idx.back() + 1;
		}
		if(idx.empty() || idx.back() != idx_back)
			idx.push_back(idx_back);
		else{
			idx.push_back(i);
			fraction[i] = {a[i], 1};
		}
	}
	idx.push_back(n);

	for(int i = 0; i < idx.size() - 1; ++i){
		long double d = find_sum(idx[i], idx[i + 1] - 1) / (long double)(idx[i + 1] - idx[i]);
		for(int j = idx[i]; j < idx[i + 1]; ++j)
			cout << fixed << setprecision(12) << d << "\n";
	}
}