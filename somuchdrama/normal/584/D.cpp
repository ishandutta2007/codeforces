#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define rep(a,b,c) for(int a=b;a<c;++a)
#define per(a,b,c) for(int a=b;a>c;--a)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e7;

bool arr[MAXN+3];
vector<int> pr;
int sz;

bool isprime(int x) {
	for (int i = 0; pr[i] * pr[i] <= x && i < sz; ++i) 
		if (!(x % pr[i]))
			return false;
	return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    for(int i = 2; i <= MAXN; ++i) arr[i] = 1;

    arr[0] = arr[1] = 0;
    for(int i = 2; i * 2 <= MAXN; ++i){
        if(arr[i]){
        	pr.pb(i);
            for(int j = i + i; j <= MAXN; j += i){
                arr[j] = 0;
            }
        }
    }
    sz = pr.size();
    int n;
    cin >> n;
    if (isprime(n)) {
    	cout << 1 << '\n' << n << '\n';
    	return 0;
    }
    if (isprime(n - 2)) {
    	cout << "2\n2 " << (n-2);
    	return 0;
    }
    for (int i = 0; i < sz; ++i)
    	for (int j = 0; j < sz; ++j) {
    		int k = n - pr[i] - pr[j];
    		if (k <= 1)
    			break;
    		if (isprime(k)) {
    			cout << 3 << '\n' << pr[i] << ' ' << pr[j] << ' ' << k << '\n';
    			return 0;
    		}
    	}

    return 0;
}