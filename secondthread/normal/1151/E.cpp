#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	ll total=0;
	ll last; cin>>last;
	for (int i=1; i<n; i++) {
		ll next; cin>>next;
		if (next<last) {
			total+=(n-last+1)*(last-next);
		}
		else {
			total+=last*(next-last);
		}
		last=next;
	}
	total+=(n-last+1)*(last);
	cout<<total<<endl;
	return 0;
}