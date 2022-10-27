#include <bits/stdc++.h>
using namespace std;
const int N=12;
int t,n,m;
char s[N][N];
int dp[N][1<<N];

pair< pair<int,int>, int > pre[N][1<<N]; 

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<m;i++){
			int st[30] = {0};
			for(int j=0;j<26;j++){
				for(int k=1;k<=n;k++){
					if(s[k][i+1]!=('a'+j)) st[j]|=(1<<(k-1));
				}
			}
			for(int mask=0;mask<1<<n;mask++){
				if(dp[i][mask]==0)continue;
				for(int j=0;j<26;j++){
					if(st[j]&mask) continue;
					dp[i+1][st[j]|mask]=1;
					pre[i+1][st[j]|mask] = make_pair(make_pair(i,mask),j);
				}
			}
		}
		bool flag=0;
		for(int i=0;i<1<<n;i++){
			if(dp[m][i]) {
				flag=1;
				int x=m, y=i;
				vector<char> vec;
				while(x) {
					int nx = pre[x][y].first.first;
					int ny = pre[x][y].first.second;
					vec.push_back(pre[x][y].second + 'a');
					x = nx, y = ny;
				}
				reverse(vec.begin(), vec.end());
				for (auto c: vec) printf("%c", c); 
				printf("\n");
				break;
			}
		}
		if (flag==0) printf("-1\n");
	}
}