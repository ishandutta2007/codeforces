#include <bits/stdc++.h>
 
using namespace std;

#define ve vector
#define pa pair
#define tu tuple
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t uint;

typedef ve< int > vi;
typedef pa< int, int > pii;
typedef ve< pii > vpii;

const int maxn = 1500; 

int n, k; 
vi b[maxn][7]; 
bool used[7]; 
int ax[maxn], ay[maxn], mx[maxn], my[maxn]; 

int gcd(int a, int b) {
	while (b) {
		a %= b; 
		swap(a, b); 
	}; 
	assert(a > 0); 
	return a;
}

void norm(int & a, int & b) {
	int t = gcd(abs(a), abs(b)); 
	a /= t; 
	b /= t; 
}

bool blocks(int x, int y, int ax, int ay, int bx, int by) {
	int dx = x - ax, dy = y - ay; 
	int ddx = bx - ax, ddy = by - ay; 
	norm(dx, dy); 
	norm(ddx, ddy); 
	return dx == ddx && dy == ddy 
		&& abs(x - ax) + abs(y - ay) < abs(bx - ax) + abs(by - ay); 
}

vi blockers(int enemy, int telep) {
	vi ans; 
	for (int i = 0; i < n; i++) {
		if (i == enemy) continue; 

		if (blocks(ax[i], ay[i], mx[telep], my[telep], ax[enemy], ay[enemy])) {
			ans.pb(i); 
		}
	}

	return ans; 
}

void kill(int tokill, int killer, vi & cur) {
	for (int i = 0; i < b[tokill][killer].size(); i++) {
		cur.pb(b[tokill][killer][i]);	
	}
}

int can(int left, vi blockers) {
	sort(blockers.begin(), blockers.end()); 
	blockers.resize(unique(blockers.begin(), blockers.end()) - blockers.begin());

	int level = rand(); 
	/*cerr << "left " << left << " " << " current blockers:\n"; 
	for (int i = 0; i < blockers.size(); i++) {
		cerr << blockers[i] << " "; 
	}
	cerr << endl;  */

	if (blockers.size() == 0) {
		return 1; 
	}
	if (blockers.size() > left) {
		return 0; 
	}
	for (int tokill : blockers) {
		vi newb; 
		for (int t = 0; t < blockers.size(); t++) {
			if (blockers[t] == tokill) {
				continue; 
			}
			newb.pb(blockers[t]); 
		}

		for (int i = 0; i < k; i++) {
			if (used[i]) continue; 
			//cerr << "level " << level << " killing " << tokill << " with " << i << endl; 
			used[i] = 1;
			kill(tokill, i, newb); 

			if (can(left -  1, newb)) {
				return 1; 
			}
			used[i] = 0; 
			newb.resize(newb.size() - b[tokill][i].size()); 
		}	
	}
	
	return 0; 
}

int main()
{
	/*cout << 7 << " " << 1000 << endl;
	for (int i = 0; i < 7; i++) {
		cout << -i - 1 << " " << -i - 1 << endl; 
	}
	for (int i = 0; i < 1000; i++) {
		cout << i << " " << i << endl;
	}
	return 0;*/

    ios_base::sync_with_stdio(false);
	cin >> k >> n; 

	for (int i = 0; i < k; i++) {
		cin >> mx[i] >> my[i]; 
	}

	for (int j = 0; j < n; j++) {
		cin >> ax[j] >> ay[j]; 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			b[i][j] = blockers(i, j); 
			/*cout << "blockers for " << i << " " << j << ":\n"; 
			for (int k = 0; k < b[i][j].size(); k++) {
				cout << b[i][j][k] << " "; 
			}
			cout << endl; */
		}
	}

	int ans = 0; 
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof(used)); 
		if (can(k, vi(1, i))) {
			ans++; 
			//cout << ax[i] << " " << ay[i] << endl;
		} else {

			//cout << ax[i] << " " << ay[i] << endl;
		}
	}

	cout << ans << endl; 

}