//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string S[66];
int is[257];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n;i++) cin >> S[i];
	int ans = 0;
	for(int i = 1; i < n;i++){
		for(int j = 1; j < m;j++){
			for(int r = 0; r < 2;r++){
				for(int l = 0; l < 2;l++){
					is[S[i - r][j - l]] = 1;
				}
			}
			if(is['f'] && is['a'] && is['c'] && is['e']) ans++;
			memset(is,0,sizeof is);
		}
	}
	cout << ans << endl;
}