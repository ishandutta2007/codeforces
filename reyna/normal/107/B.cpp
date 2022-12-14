//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int Maxn = 1e6 + 9;
int s[Maxn];
int main(){
	int n,m,id;
	cin >> n >> m >> id;
	int sum = 0;
	for(int i = 0; i < m;i++) cin >> s[i],sum += s[i];
	s[--id]--;
	sum--;
	n--;
	if(sum < n){
		cout << -1 << endl;
		return 0;
	}
	int x = sum - s[id];
	if(x < n){
		cout << 1 << endl;
		return 0;
	}
	ld ans = 1;
	for(int i = 0; i < n;i++){
		ans *= (((ld)x - i) / (sum - i));
	}
	cout << setprecision(10) << fixed << 1 - ans << endl;
	return 0;
}