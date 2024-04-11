#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<string> s(n,"");
		for (int i = 0; i < n; i ++)
			cin >> s[i];
		//for (int i = 0; i < n; i ++) cout << s[i] << "\n";
		vector<vector<bool> > f(n,vector<bool>(m,false));

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (s[i][j] == '*' && i-k>=0 && j-k>=0 && j+k<m) {
					//printf("# %d %d\n", i, j);
					bool ok=1;
					for (int x=0;x<=k;x++){
						if(s[i-x][j-x]!='*') ok=0;
						if(s[i-x][j+x]!='*') ok=0;
					}
					if(ok) {
						for (int x=0;;x++){
							if(i-x>=0 && j-x>=0 && j+x<m && s[i-x][j-x]=='*' && s[i-x][j+x]=='*') {
								f[i-x][j-x]=1;
								f[i-x][j+x]=1;
							}else{
								break;
							}
						}						
					}
				}
			}
		}
		bool can=true;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)
			if((s[i][j]=='*') != f[i][j]) can=false;
		cout << (can?"YES":"NO") << "\n";
	}		
}
/*
L
dp[i][j]
*/