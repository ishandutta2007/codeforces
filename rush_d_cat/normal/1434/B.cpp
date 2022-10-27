#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
char s[N][2]; int x[N];
int top, stk[N];
int main() {
	scanf("%d",&n);
	set<int> st;
	vector<int> ans;
	for(int i=1;i<=2*n;i++){
		scanf("%s",s[i]);
		if(s[i][0]=='-') {
			scanf("%d",&x[i]);
			while(top && x[stk[top]] < x[i]) --top;
			int lef=stk[top];
			stk[++top]=i;
			if(st.lower_bound(lef) == st.end()) return !printf("NO\n");
			//printf("i=%d,lef=%d\n", i,lef);
			x[*st.lower_bound(lef)] = x[i];
			st.erase(*st.lower_bound(lef));
		} else {
			st.insert(i);
		}
	}
	printf("YES\n");
	for(int i=1;i<=2*n;i++)if(s[i][0]=='+')printf("%d ", x[i]);
	printf("\n");
}