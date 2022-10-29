#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 1, sho = n; i < 100; ++i, sho+=n){
		if(sho%10 == k || sho%10 == 0){
			cout << i << "\n";
			return;
		}
	}
		
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}