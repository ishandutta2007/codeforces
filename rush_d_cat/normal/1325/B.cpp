#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int t,n;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		set<int> st;
		for(int i=1;i<=n;i++){
			int x; scanf("%d",&x); st.insert(x);
		}
		printf("%d\n", st.size());
	}
}