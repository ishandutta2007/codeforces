#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[502];
		for(int i = 0; i < n; i++) cin >> a[i];
		int s = 0;
		bool f = true;
		vector<P> ans1;
		vector<int> ans2;
		while(n){
			int r;
			for(r = 1; r < n; r++){
				if(a[r] == a[0]) break;
			}
			if(r == n){
				f = false;
				break;
			}
			for(int i = 1; i < r; i++){
				ans1.push_back(P(s + r + i, a[i]));
			}
			s += r * 2;
			ans2.push_back(r * 2);
			reverse(a, a + r);
			n -= 2;
			for(int i = r - 1; i < n; i++) a[i] = a[i + 2];
		}
		if(!f) cout << -1 << "\n";
		else{
			cout << ans1.size() << "\n";
			for(P p : ans1) cout << p.first << " " << p.second << "\n";
			cout << ans2.size() << "\n";
			for(int r : ans2) cout << r << " ";
			cout << "\n";
		}
	}
}