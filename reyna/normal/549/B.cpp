//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 105;
int g[Maxn],mat[Maxn][Maxn],deg[Maxn];
vector<int> ans;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n;j++){
			char c;
			cin >> c;
			mat[i][j] = c - '0';
		}
	for(int i = 0; i < n;i++) cin >> g[i];
	for(int k = 0; k < n;k++)
		for(int i = 0; i < n;i++){
			if(g[i] == deg[i]){
				ans.push_back(i + 1);
				for(int j = 0; j < n;j++){
					deg[j] += mat[i][j];
				}
				break;
			}
		}
	for(int k = 0; k < n;k++){
		if(g[k] == deg[k]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size();i++) cout << ans[i] << ' ';
}