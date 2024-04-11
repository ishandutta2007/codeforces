#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,m,a[N],b[N];
multiset<int> st;
struct Nod {
	int x,y;
	bool operator<(const Nod&o)const{
		return (x+y)%m < (o.x+o.y)%m;
	}
};
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]); st.insert(b[i]);
	}
	vector<int> ans;
	priority_queue<Nod> q;

	for(int i=1;i<=n;i++){
		int r1=m-1-a[i];
		int res1=-1,val1=-1;
		int res2=-1,val2=-1;
		auto it = st.upper_bound(r1); 
		if(it != st.begin()) {
			--it; res1=*(it); val1=(res1+a[i])%m;
		}
		res2=*(st.rbegin()); val2=(res2+a[i])%m;

		if(val1>val2){
			q.push((Nod){a[i], res1});
		}else{
			q.push((Nod){a[i], res2});
		}
	}
	while(q.size()){
		Nod now = q.top(); q.pop();
		if(st.find(now.y) != st.end()) {
			ans.push_back((now.x+now.y)%m); st.erase(st.find(now.y));
		} else {
			int r1=m-1-now.x;
			int res1=-1,val1=-1;
			int res2=-1,val2=-1;
			auto it = st.upper_bound(r1); 
			if(it != st.begin()) {
				--it; res1=*(it); val1=(res1+now.x)%m;
			}
			res2=*(st.rbegin()); val2=(res2+now.x)%m;
			if(val1>val2){
				q.push((Nod){now.x, res1});
			}else{
				q.push((Nod){now.x, res2});
			}			
		}	
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	for(auto x:ans)printf("%d ", x);printf("\n");
}