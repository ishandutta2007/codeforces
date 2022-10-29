#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int stx = 1, sty = 1;
	int mxx = 1, mxy = 1;
	int cux = 1, cuy = 1;
	for(char c : s){
		if(c == 'L'){
			cux--;
			if(cux <= 0){
				if(mxx == m)break;
				stx++;
				cux = 1;
				mxx++;
			}
		}else if(c == 'R'){
			cux++;
			if(cux > mxx){
				if(mxx == m)break;
				mxx++;
			}

		}else if(c == 'U'){
			cuy--;
			if(cuy <= 0){
				if(mxy == n)break;
				sty++;
				cuy = 1;
				mxy++;
			}

		}else{
			cuy++;
			if(cuy > mxy){
				if(mxy == n)break;
				mxy++;
			}
		}
	}
	cout << sty << ' ' << stx << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t--){
		solve();
	}
}