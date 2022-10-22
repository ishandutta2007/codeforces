#include <iostream>
#include <vector>
using namespace std;

vector<int> v[200005];

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i <= n; i++) v[i].clear();
		int a[200005];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			v[a[i]].push_back(i);
		}
		vector<int> ans;
		int i = 0;
		while(i < n){
			int j = i + 1;
			for(int c = 0; c <= n; c++){
				auto itr = lower_bound(v[c].begin(), v[c].end(), i);
				if(itr == v[c].end()){
					ans.push_back(c);
					break;
				}
				j = max(j, *itr + 1);
			}
			i = j;
		}
		cout << ans.size() << endl;
		for(int j : ans) cout << j << " ";
		cout << endl;
	}
}