#include <iostream>
//#include <vector>
//#include <cmath>

using namespace std;

const int SQRT_MAXN = 18000;
const int S = 60000;
char nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;

int main() {
	int n, l;
	cin >> l >> n;
	//l =1;
	//n=3*100*1000*1000;
	int nsqrt = SQRT_MAXN;
	for (int i=3; i<=nsqrt; i+=2)
		if (!nprime[i]){
			primes[cnt++] = i;
			for (int j=i+i; j<=nsqrt; j+=i)
				nprime[j] = true;
		}
	int result = 0;
	int maxk = n/S;
	for (int k=0; k<=maxk; ++k) {
		memset(bl, 0, sizeof bl);
		int start = k * S;
		for (int i=0; i<cnt; ++i)
			for (int j=max((start+primes[i]-1)/primes[i],2)*primes[i]-start; j<S; j+=primes[i])
				bl[j] = true;
		if (k == 0)
			bl[0] = bl[1] = true;
		for (int i=1; i<S && start+i<=n; i+=4)
			if ((!bl[i]) && (start+i>=l))++result;
	}
	if ((l <= 2) && (n >= 2)) result++;
	cout << result;
    return 0;
}