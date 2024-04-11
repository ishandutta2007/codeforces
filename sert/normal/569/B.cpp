#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 1e6 + 7;

ll n, a[N];
bool u[N];
vector <int> v;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	u[a[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
    	if (!u[i])
    		v.push_back(i);
    	u[i] = false;
    }
    for (int i = 0; i < n; i++) {
    	if (a[i] > n || u[a[i]]) {
    		cout << v.back() << " ";
    		v.pop_back();
    		continue;
    	}
    	cout << a[i] << " ";
    	u[a[i]] = true;
    }
}