//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
pair<int,int> sweep[Maxn];
int x[Maxn],h[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int last = -1e9 - 10;
	int ans = 0,ed = 0;
	for(int i = 0; i < n;i++){
		cin >> x[i] >> h[i];
	}
	for(int i = 0; i < n;i++){
		if(i == n - 1 || x[i+1] > x[i] + h[i]){
			sweep[ed++] = make_pair(x[i]+h[i],x[i]);
		}
		if(!i || x[i - 1] < x[i] - h[i]) sweep[ed++] = make_pair(x[i],x[i] - h[i]);
	}
	sort(sweep,sweep + ed);
	for(int i = 0; i < ed;i++){
		int r = sweep[i].first,l = sweep[i].second;
		if(l > last) {
			ans++;
			last = r;
		}
	}
	cout << ans << endl;
	return 0;
}