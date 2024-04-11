#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
char s[N];
int stk[N],vis[N],top;
vector< vector<int> > v;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);

	for(int i=1;i<=n;i++){
		vector<int> tmp;
		for(int l=1,r=n;l<=n;l++){
			if(vis[l]||s[l]==')') continue;
			while(r>l && (vis[r]==1||s[r]=='(') ) --r;
			if(l>=r) break;
			tmp.push_back(l); vis[l]=1;
			tmp.push_back(r); vis[r]=1;
		}
		if(tmp.size()){
			sort(tmp.begin(),tmp.end());
			v.push_back(tmp);
		}else{
			break;
		}
	}
	printf("%d\n", v.size());
	for(auto vec: v) {
		printf("%d\n", vec.size());
		for(auto x: vec) {
			printf("%d ", x);
		}
		printf("\n");
	}
}