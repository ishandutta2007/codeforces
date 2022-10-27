#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			q.push(i);
		}	
		vector< pair<int,int> > ans;
		while(q.size()>1){
			int x=q.top(); q.pop();
			int y=q.top(); q.pop();
			ans.push_back(make_pair(x,y));
			q.push((x+y+1)/2);
		}
		printf("%d\n", q.top());
		for(auto p:ans)printf("%d %d\n", p.first,p.second);
	}
}