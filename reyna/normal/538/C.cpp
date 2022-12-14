//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 2e6 + 9;
typedef long long ll;
int day[Maxn],h[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	bool flag = 0;
	int ans = 0;
	for(int i = 0; i < m;i++){
		cin >> day[i] >> h[i];
	}
	for(int i = 1; i < m;i++){
		if(abs(day[i] - day[i-1]) < abs(h[i] - h[i-1]))
			flag = 1;
	}
	ans = max(ans,day[0] - 1 + h[0]);
	ans = max(ans,n - day[m-1] + h[m-1]);
	for(int i = 1; i < m;i++){
		int len = day[i] - day[i-1] + 1;
		ans = max(ans,(h[i] - h[i-1] + len - 1) / 2 + h[i-1]);
	}
	if(flag){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << ans << endl;
	return 0;
}