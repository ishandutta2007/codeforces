#include <cstdio>
#include <set>
using namespace std;
set<int> st;
int main(){
	int n,k;
	int a;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		st.insert(a);
	}
	int now=0;
	while(k--){
		while(!st.empty()&&(*st.begin())-now<=0){
			st.erase(st.begin());
		}
		if(st.empty()){
			puts("0");
			continue;
		}
		printf("%d\n",(*st.begin())-now);
		now=*(st.begin());
	}
	return 0;
}