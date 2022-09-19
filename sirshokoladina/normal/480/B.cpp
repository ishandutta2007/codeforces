#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

const int size = 300 * 1000 + 100;

int a[size];
set <int> marks;

int n, len, x, y;
	

set <int> couldget(int val) {
	set <int> psb;

	for (int i = 0; i < n; i++)
		if (marks.find(a[i] + val) != marks.end())
			psb.insert(a[i]);
			
	return psb;
}

int main () {
	#ifdef SG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	scanf("%d%d%d%d", &n, &len, &x, &y);
	
	
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
		marks.insert(a[i]);
	}
	
	set <int> cx = couldget(x);
	set <int> cy = couldget(y);
	set <int> csum = couldget(x + y);
	set <int> cdif = couldget(y - x);
	
	if (!cx.empty() && !cy.empty()) {
		cout << 0 << endl;
		return 0;
	}
	
	if (!cx.empty() || !cy.empty()) {
		cout << 1 << endl;
		if (!cx.empty())
			cout << y << endl;
		else
			cout << x << endl;
			
		return 0;
	}
	
	if (!csum.empty()) {
		cout << 1 << endl;
		cout << *csum.begin() + x << endl;
		
		return 0;
	}
		
	if (!cdif.empty() && (*cdif.begin() + y <= len || *cdif.rbegin() >= x)) {
		cout << 1 << endl;
		if (*cdif.begin() + y <= len) {
			cout << *cdif.begin() + y << endl;
		} else {
			cout << *cdif.rbegin() - x << endl;
		}
		
		return 0;
	}
	
	cout << 2 << endl;
	cout << x << ' ' << y << endl;
	
	return 0;
}