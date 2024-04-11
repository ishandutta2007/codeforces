#include <bits/stdc++.h>
using namespace std;
const int N=1000000+10;
int n,pre[N],ans[N];
char s[N];
vector<int> v[N];

int main() {
	scanf("%d%s",&n,s+1);
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')x=i;
		if(s[i]=='1')y=i;
		pre[i]=i-min(x,y);
		v[pre[i]].push_back(i);
	}
	set<int> st;
	for(int i=n;i>=1;i--){
		for(auto x:v[i]) {
			st.insert(x);
			//printf("ins %d\n", x);
		}
		for(int j=1;j<=n;){
			//printf("i=%d, j=%d\n", i,j);
			if(j+i-1>n){
				break;
			}
			if(pre[j+i-1]>=i) j=j+i,ans[i]++;
			else{
				int lef=j+i-1;
				//printf("lef=%d\n", lef);
				auto it=st.lower_bound(lef);
				if(it==st.end()) break;
				j=(*it)+1; ans[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ", ans[i]);
}