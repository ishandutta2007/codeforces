#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int t,n;
vector<int> g[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			g[i].clear();
			int x; scanf("%d",&x); 
			while(x--) {
				int y; scanf("%d",&y); g[i].push_back(y);
			}
		}
		set<int> st;
		for(int i=1;i<=n;i++) st.insert(i);
		int cnt=0;
		int x,y;
		for(int i=1;i<=n;i++){
			bool fg=0;
			for(auto x:g[i]){
				if(st.count(x)){
					st.erase(x); cnt++; fg=1; break;
				}
			}
			if(fg==0){
				x=i;
			}
		}
		if(cnt==n) {
			printf("OPTIMAL\n");
		}else{
			y=*st.begin();
			printf("IMPROVE\n%d %d\n",x,y);
		}
	}
}