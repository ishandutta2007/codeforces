#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

void solve(){
	int n; cin >> n;
	int hi, lo, start;
	int ans = 0;
	cin >> start;
	hi = start;
	lo = start;
	for(int i = 0, tmp; i < n-1; ++i){
		cin >> tmp;
		if(tmp < lo){
			ans++;
			lo = tmp;
		}
		if(tmp > hi){
			ans++;
			hi = tmp;
		}
	}
	cout << ans << "\n"; 
			
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}