#include<bits/stdc++.h>

using namespace std;
int a[10000], f[1005];
set<int> s, tmp;
vector<int> ans;
int main(){

//	freopen("in.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, t;
	for(cin >> t; t --;) {
		cin >> n;
		s.clear();
		ans.clear();
		tmp.clear();
		memset(f, 0, sizeof(f));
		for(int i = 0; i < n; i ++)  cin >> a[i], f[a[i]] ++, tmp.insert(i);
		for(int i = 0; i <= n; i ++) if(!f[i]) s.insert(i);
		int rlt = 0;
		while(rlt < n) {
			int p = *s.begin();
			if(p == n) {
				int vv = *tmp.begin();
				ans.push_back(vv + 1);
				f[a[vv]] = 0;
				s.insert(a[vv]);
				a[vv] = n;
			}
			else{
				f[a[p]] --;
				s.erase(s.begin());
				if(f[a[p]] == 0) s.insert(a[p]);
				ans.push_back(p + 1);
				tmp.erase(p);
				a[p] = p;
				rlt ++;
			}
		}
//		for(int i = 0; i < n ; i ++) cout << a[i] << " ";
//		 cout << endl;
		cout << ans.size() << endl;
		for(auto v: ans) cout << v << " ";
		cout << endl;
	}
	return 0;
}