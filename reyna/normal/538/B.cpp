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
int add[9][9];
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	int ans = 0;
	while(n){
		for(int i = 0; i < n % 10;i++)
			add[i][cnt]++;
		ans = max(ans,n % 10);
		cnt++;
		n /= 10;
	}
	cout << ans << endl;
	for(int i = 0; i < ans;i++){
		int num = 0;
		for(int j = 8; j + 1;--j){
			num *= 10;
			num += add[i][j];
		}
		cout << num << ' ';
	}
	return 0;
	
}