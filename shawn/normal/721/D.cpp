#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll read () {
	ll x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

set < pair < ll , ll > > s;

ll n , k , x , a[200100];

bool flag;

int main() {
	n = read() , k = read() , x = read();
	for (int i = 1 ; i <= n ; i ++) {
		a[i] = read();
		if (a[i] < 0) flag ^= 1;
		s.insert(make_pair(abs(a[i]) , i));
	}
	for (int i = 1 ; i <= k ; i ++) {
		int pos = s.begin() -> second;
		s.erase(s.begin());
		if (a[pos] < 0) flag ^= 1;
		if (flag) a[pos] += x;
		else a[pos] -=x;
		if (a[pos] < 0) flag ^= 1;
		s.insert(make_pair(abs(a[pos]) , pos));
	}
	for (int i = 1 ; i <= n ; i ++) printf("%I64d " , a[i]);
	return 0;
}