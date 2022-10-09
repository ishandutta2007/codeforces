#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    int t; cin >> t;
    while(t--){
		int n; cin >> n;
		map<int ,int> map;
		for(int i=0; i< n ;i++) {
			int e; cin >> e;
            int l;
			if(map.count(e) && map.count(-e)){
                l++;
            }
			else if(map.count(e)){
				map[-e]++;
			}
			else if(map.count(-e)){
				map[e]++;
			}
			else{
				map[e]++;
			}
		}
		cout << map.size() << ln;
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}