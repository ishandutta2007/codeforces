#include <bits/stdc++.h>

using namespace std;

const long long kN = 2e5 + 7;
const long long kP = 1e6 + 7;

long long a[kN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t timer = clock();
vector<long long> v;

long long ans2 = 0;

bool time_left(){
	if(((float)clock() - (float)timer) / (float)CLOCKS_PER_SEC <= (float)2)
		return true;
	return false;
}

long long rnd(long long mod){
	return rng() % mod;
}

vector<long long> primes;
bool tested[kP], comp[kP];

void primes_preprocess(){
	comp[1] = true;
	for(long long i = 2; i < kN; ++i){
		if(comp[i])
			continue;

		primes.push_back(i);
		for(long long j = i * i; j < kN; j += i)
			comp[j] = true;
	}
}

void update_ans2(long long prime){
	long long ans = 0;
	for(long long x: v){
		long long rem = x % prime;
		if(x == rem){
			ans += prime -rem;
			continue;
		}

		if(prime - rem < rem)
			rem = prime - rem;
		ans += rem;
	}

	ans2 = min(ans2, ans);
}

void update_x(long long x){
	for(int j = 0; j < primes.size() && x != 1; ++j){
		if(x % primes[j] == 0){
			update_ans2(primes[j]);
			while(x % primes[j] == 0)
				x /= primes[j];
		}
	}

	if(x != 1)
		update_ans2(x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	primes_preprocess();

	long long n;
	cin >> n;

	for(long long i = 0; i < n; ++i)
		cin >> a[i];

	
	for(long long i = 0; i < n; ++i)
		v.push_back(a[i]);

	random_shuffle(v.begin(), v.end(), rnd);
	for(long long x: v)
		ans2 += x & 1;

	if(!ans2){
		cout << "0\n";
		return 0;
	}

	for(long long i = 0; i < v.size() && time_left(); ++i){
		update_x(v[i]);
		update_x(v[i] + 1);
		if(v[i] != 1)
			update_x(v[i] - 1);
	}

	cout << ans2 << "\n";
}