#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int count(vector<int> &v, int x){
	return upper_bound(v.begin(),v.end(),x) - v.begin();
}
int count(vector<int> &v, int l, int r) {
	return count(v,r) - count(v,l-1);
}

int solve(vector<int> a, vector<int> b) {
	if(a.size()==0||b.size()==0) return 0;
	
	vector<int> need;
	for(int i=1;i<a.size();i++){
		need.push_back(a[i]-i);
	}
	int now=0,len=1,ans=0;
	set<int> sa;
	for(auto x: a) sa.insert(x);

	vector<int> eq;
	for(auto bb: b) if (sa.count(bb)) {
		eq.push_back(bb);
	}


	for(auto bb: b){ 
		if(bb>=a[0]){
			while(now<need.size() && need[now]<=bb) {
				now++; len++;
			}
			ans=max(ans,count(b,bb,bb+len-1)+(int)eq.size() - count(eq,bb+len-1));
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t --) {
		int n, m; cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);

		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<m;i++)cin>>b[i];

		int ans=0;
		{
			vector<int> x,y;
			for(int i=0;i<n;i++)if(a[i]>0)x.push_back(a[i]);
			for(int i=0;i<m;i++)if(b[i]>0)y.push_back(b[i]);
			sort(x.begin(),x.end()); sort(y.begin(),y.end());
			ans += solve(x,y);
		}
		{
			vector<int> x,y;
			for(int i=0;i<n;i++)if(a[i]<0)x.push_back(-a[i]);
			for(int i=0;i<m;i++)if(b[i]<0)y.push_back(-b[i]);
			sort(x.begin(),x.end()); sort(y.begin(),y.end());
			ans += solve(x,y);
		}
		cout<<ans<<endl;
	}
}