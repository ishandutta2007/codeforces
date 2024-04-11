#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

ll powm(ll k, ll m) {
if (m == 0) return 1;
ll j = powm(k, m / 2);
(j*=j)%=MOD;
if(m&1) (j*=k)%=MOD;
return j;
}

int A, B, N;

int inv(int k) {
return powm(k, MOD - 2);
}

bool good(ll c) {
while (c) {
int dig = c % 10;
c /= 10;
if (dig != A && dig != B) return false;
}
return true;
}

int main() {
scanf("%d %d %d", &A, &B, &N);

ll sum = 0;
ll cur = 1;
ll cursum = A * N;
if (A == B) {
if(good(cursum)) ++sum;
} else
for(int i = 0; i <= N; ++i) {
if (good(cursum)) {
sum += cur;
sum %= MOD;
}
(cur *= N - i) %= MOD;
(cur *= inv(i + 1)) %= MOD;
cursum += B - A;
}

cout << sum << endl;
return 0;
}