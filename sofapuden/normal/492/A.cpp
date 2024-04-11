#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n; cin >> n;
	int ans = -1;
	int i = 1;
	while(n>=0){
		ans++;
		n-=i*(i+1)/2;
		++i;
	}
	cout << ans << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}