#include <bits/stdc++.h>

using namespace std;

long long read () {
	long long x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ? -1 : 1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

long long n , ans;

pair <long long , long long> m;

priority_queue < long long , vector <long long> , greater <long long> > a;

vector < pair <long long , long long> > b;

int main() {
	n = read() , m.first = read() , m.second = read();
	for (long long i = 1 ; i < n ; i ++) {
		long long t = read() , w = read();
		if (t > m.first) a.push(w - t + 1);
		else b.push_back(make_pair(-t , -w));
	}
	sort(b.begin() , b.end());
	ans = a.size() + 1;
	for (long long i = 0 ; !a.empty() ; ) {
		long long now = a.top(); 
		if (now <= m.first) a.pop() , m.first -= now; else break;
		for ( ; i < b.size() ; i ++) 
			if (-b[i].first > m.first) a.push(-b[i].second + b[i].first + 1); 
			else break;
		ans = min(ans , (long long) a.size() + 1ll);
	}
	printf("%I64d\n" , ans);
	return 0;
}