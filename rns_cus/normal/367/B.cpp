#include<bits/stdc++.h>
using namespace std;

#define N 400020

map <int, int> mp;
vector <int> ans;

int n, m, p;
int a[N], b[N];

int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &p);
	///cout << n << " " << m << " " << p << endl;
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= m; i ++) scanf("%d", b + i);

	for(int i = 1; i <= p; i ++){
		int cnt = (n - i) / p + 1;
		if(cnt < m) continue;
		mp.clear();
		for(int i = 1; i <= m; i ++) mp[b[i]] ++;

		for(int j = i; j < i + m * p; j += p){
			mp[a[j]] --;
			if(mp[a[j]] == 0) mp.erase(a[j]);
		}

		if(mp.size() == 0) ans.push_back(i);
		for(int j = i + m * p; j <= n; j += p){
			mp[a[j]] --;
			if(mp[a[j]] == 0) mp.erase(a[j]);
			mp[a[j - m * p]] ++;
			if(mp[a[j - m * p]] == 0) mp.erase(a[j - m * p]);
			if(mp.size() == 0) ans.push_back(j - m * p + p);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(auto x : ans) printf("%d ", x); puts("");
}