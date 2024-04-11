#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set<pair<int,int> > st;
int an[200005];
int main(){
	int n,m,k;
	int a;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		st.insert(make_pair(a,i));
	}
	int ans=0;
	pair<int,int> tmp;
	while(!st.empty()){
		tmp=*st.begin();
		ans++;
		an[tmp.second]=ans;
		st.erase(tmp);
		while(st.lower_bound(make_pair(tmp.first+k+1,0))!=st.end()){
			tmp=*st.lower_bound(make_pair(tmp.first+k+1,0));
			an[tmp.second]=ans;
			st.erase(tmp);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d ",an[i]);
	}
	puts("");
	return 0;
}