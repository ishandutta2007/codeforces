//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 185; // 85
int arr[Maxn];
int cur[Maxn];
int main(){
	int n,sadasfasf,c;
	cin >> n >> sadasfasf >> c;
	for(int i = 0; i < n;i++){
		cin >> arr[i];
	}
	int ans = 1;
	for(int i = 0; i <= n;i++){
		for(int j = 0; j < i;j++) cur[j] = arr[j];
		cur[i] = c;
		for(int j = i + 1; j <= n;j++) cur[j] = arr[j - 1];
		int cnt = 0;
		while(1){
			bool flag = 0;
			for(int j = 0; j <= n;j++){
				int s = 0;
				if(cur[j] == -1) continue;
				for(int k = j;k <= n;k++){
					if(cur[k] == -1) continue;
					if(cur[k] != cur[j]) break;
					s++;
				}
				if(s >= 3){
					flag = 1;
					int p = cur[j];
					for(int k = j;k <= n;k++){
						if(cur[k] == -1) continue;
						if(cur[k] != p) break;
						cur[k] = -1;
						cnt++;
					}
					break;
				}
			}
			if(!flag) break;
		}
		ans = max(ans,cnt);
	}
	cout << ans - 1 << endl;
	return 0;
}