//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 350;
int vis[2*Maxn];
int use[2*Maxn];
int main(){
	int n,t,r;
	cin >> n >> t >> r;
	if(t < r){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n;i++)
		cin >> vis[i];
	for(int i = 0; i < n;i++)
		vis[i]+=Maxn;
	for(int i = 0; i < n;i++){
		int hi = 0;
		for(int j = vis[i]-1; j >= vis[i]-t;j--){
			hi += use[j];
		}
		if(hi >= r)
			continue;
		int now = 0;
		for(int j = vis[i]-1;j >= vis[i]-t;j--){
			if(!use[j])
				use[j] = 1,now++;
			if(now == r - hi){
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 2 * Maxn;i++){
		ans += use[i];
	}
	
	cout << ans << endl;
	return 0;
}