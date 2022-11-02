#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const ll inf = ll(1e10);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);

struct point{
	ll x, y;
};

int pos[N + 100];
ll min_pref[N + 100], max_pref[N + 100], min_suff[N + 100], max_suff[N + 100];
pair <ll, int> lx[N + 100], rx[N + 100];
ll x[2 * N + 100];
point p[N + 100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		ll x, y;
		scanf(LLD" "LLD, &x, &y);
		x *= 2;
		y *= 2;
		p[i].x = x + y;
		p[i].y = x - y;
	}
	for(int i = 0; i < n; i++){
		lx[i] = mp(p[i].x, i);
		rx[i] = mp(p[i].x, i);
		x[2 * i] = p[i].x;
		x[2 * i + 1] = p[i].x;
	}
	sort(lx, lx + n);
	sort(rx, rx + n);
	sort(x, x + 2 * n);
	int k = unique(x, x + 2 * n) - x;
	ll ans = inf, l = 0, r = inf;
	while(l <= r){
		ll mid = (l + r) / 2;
		bool can = false;
		for(int i = 0; i < n; i++){
			min_pref[i] = min((i > 0 ? min_pref[i - 1] : inf), p[lx[i].sc].y + mid);
			max_pref[i] = max((i > 0 ? max_pref[i - 1] : -inf), p[lx[i].sc].y - mid);
		}
		for(int i = n - 1; i >= 0; i--){
			min_suff[i] = min((i + 1 < n ? min_suff[i + 1] : inf), p[rx[i].sc].y + mid);
			max_suff[i] = max((i + 1 < n ? max_suff[i + 1] : -inf), p[rx[i].sc].y - mid);
		}
		int i = 0, j = 0, lptr = -1, rptr = 0;
		while(i < k && j < k){
			if(x[i] - mid < x[j] + mid){
				ll cx = x[i++] - mid;
				while(lptr + 1 < n && lx[lptr + 1].fs + mid < cx){
					lptr++;
				}
				while(rptr < n && rx[rptr].fs - mid <= cx){
					rptr++;
				}
				ll lft = -inf, rgh = inf;
				if(lptr >= 0){
					lft = max(lft, max_pref[lptr]);
					rgh = min(rgh, min_pref[lptr]);
				}
				if(rptr < n){
					lft = max(lft, max_suff[rptr]);
					rgh = min(rgh, min_suff[rptr]);
				}
				if(lft <= rgh){
					can = true;
					break;
				}
			}
			else{
				ll cx = x[j++] + mid;
				while(lptr + 1 < n && lx[lptr + 1].fs + mid < cx){
					lptr++;
				}
				while(rptr < n && rx[rptr].fs - mid <= cx){
					rptr++;
				}
				ll lft = -inf, rgh = inf;
				if(lptr >= 0){
					lft = max(lft, max_pref[lptr]);
					rgh = min(rgh, min_pref[lptr]);
				}
				if(rptr < n){
					lft = max(lft, max_suff[rptr]);
					rgh = min(rgh, min_suff[rptr]);
				}
				if(lft <= rgh){
					can = true;
					break;
				}
			}
		}
		while(i < k && !can){
			ll cx = x[i++] - mid;
			while(lptr + 1 < n && lx[lptr + 1].fs + mid < cx){
				lptr++;
			}
			while(rptr < n && rx[rptr].fs - mid <= cx){
				rptr++;
			}
			ll lft = -inf, rgh = inf;
			if(lptr >= 0){
				lft = max(lft, max_pref[lptr]);
				rgh = min(rgh, min_pref[lptr]);
			}
			if(rptr < n){
				lft = max(lft, max_suff[rptr]);
				rgh = min(rgh, min_suff[rptr]);
			}
			if(lft <= rgh){
				can = true;
				break;
			}
		}
		while(j < k && !can){
			ll cx = x[j++] - mid;
			while(lptr + 1 < n && lx[lptr + 1].fs + mid < cx){
				lptr++;
			}
			while(rptr < n && rx[rptr].fs - mid <= cx){
				rptr++;
			}
			ll lft = -inf, rgh = inf;
			if(lptr >= 0){
				lft = max(lft, max_pref[lptr]);
				rgh = min(rgh, min_pref[lptr]);
			}
			if(rptr < n){
				lft = max(lft, max_suff[rptr]);
				rgh = min(rgh, min_suff[rptr]);
			}
			if(lft <= rgh){
				can = true;
				break;
			}
		}
		if(can){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf(LLD".%d\n", ans / 2, (ans % 2 ? 5 : 0));
	return 0;
}