#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	vector<string> gr(8);
	for(auto &x : gr)cin >> x;
	for(int i = 1; i < 7; ++i){
		for(int j = 1; j < 7; ++j){
			int x = i, y = j;
			while(x < 8 && y < 8){
				if(gr[x][y] == '.')goto nxt;
				x++;
				y++;
			}
			x = i, y = j;
			while(x < 8 && ~y){
				if(gr[x][y] == '.')goto nxt;
				x++, y--;
			}
			x = i, y = j;
			while(~x && ~y){
				if(gr[x][y] == '.')goto nxt;
				x--;
				y--;
			}
			x = i, y = j;
			while(~x && y < 8){
				if(gr[x][y] == '.')goto nxt;
				x--, y++;
			}
			cout << i+1 << ' ' << j+1 << '\n';
		nxt:
		;

		}
	}

}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}