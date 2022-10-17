#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll a, b, ans_k{}, ans = 0x3f3f3f3f3f3f3f3f;
ll calc(ll a, ll b) {
    if (a <= b) return b;
    if (a % b == 0) return a;
    return (a + b - a % b);
}
std::vector<ll> fac;
int main() {
    scanf("%lld%lld", &a, &b);
    if (a == b){
    	puts("0");
    	return 0;
	}
	if (a<b){
		swap(a,b);
	}
    ans = a * b / gcd(a, b);
    ll upper = calc(b, a - b);
    for (ll i = 1; i * i <= upper; i++) {
        if (upper % i == 0) {
            fac.push_back(i);
            fac.push_back(upper / i);
        }
    }
    for (auto each : fac) {
        ll k = calc(b, each) - b, tmp = (a * b + (a + b) * k + k * k) / each;
        if (tmp < ans) {
            ans = tmp;
            ans_k = k;
        }
    }
    printf("%lld\n", ans_k);
    return 0;
}