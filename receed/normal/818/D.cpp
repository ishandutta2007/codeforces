#include <bits/stdc++.h>

using namespace std;




int main(){
	int n, a;
	cin >> n >> a;
	vector<int> c(n);
	for(int i = 0; i < n; i++)
		cin >> c[i];
	set<pair<int, int> > pos;
	vector<int> cnt(1000001, 0);
	for(int i = 1; i <= 1000000; i++)
		if(i != a)
			pos.insert(make_pair(0, i));
	for(int i = 0; i < n; i++){
		if(c[i] == a){
			cnt[a]++;
			while(!pos.empty() && (*pos.begin()).first < cnt[a]){
				cnt[(*pos.begin()).second] = -1e9;
				pos.erase(pos.begin());
			}
		}
		else if(cnt[c[i]] >= 0){
			pos.erase(make_pair(cnt[c[i]], c[i]));
			cnt[c[i]]++;
			pos.insert(make_pair(cnt[c[i]], c[i]));
		}
	}
	if(pos.empty())
		cout << -1;
	else
		cout << (*pos.begin()).second;
}