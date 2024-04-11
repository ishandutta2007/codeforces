#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int a[7];
int n,b[N],v[N][7];
map<int, vector<int> > vec;
set<int> s[N];
int main() {
	for(int i=1;i<=6;i++)scanf("%d",&a[i]);
	scanf("%d",&n);
	set<int> st;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		for(int j=1;j<=6;j++) {
			s[i].insert(b[i]-a[j]);
			st.insert(b[i]-a[j]);
		}
		for(auto x:s[i]){
			vec[x].push_back(i);
		}
	}
	int ans=2e9;
	int mx=0,cur=*st.begin();
	for(int i=1;i<=n;i++){
		mx=max(mx,*s[i].lower_bound(cur));
	}
	ans=mx-cur;

	bool gg=0;
	for(auto x:st){
		ans=min(ans,mx-x);
		for(auto row:vec[x]){
			s[row].erase(x);
			if(s[row].size()==0){
				gg=1;
				break;
			}
			mx=max(mx, *s[row].upper_bound(x));
		}
		if(gg)break;
	}
	printf("%d\n", ans);
}