#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int t,n,m,a,b;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d",&n,&m,&a,&b);
		if(n*a!=m*b) {
			printf("NO\n"); continue;
		}
		int mat[N][N]={0}, res[N]={0};

		set< pair<int,int> > st;
		for(int i=1;i<=m;i++) st.insert(make_pair(m,i));
		for(int i=1;i<=n;i++){
			int x=a;
			for(int j=1;j<=a;j++){
				pair<int,int> p = (*st.rbegin());st.erase(p);
				mat[i][p.second]=1; p.first--;
				st.insert(p);
			}
		}
		printf("YES\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d", mat[i][j]);
			}
			printf("\n");
		}
	}
}