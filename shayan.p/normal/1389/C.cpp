// And you curse yourself for things you never done
// Shayan.P  2020-07-29

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int cnt[10], a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	string s;
	cin >> s;
	int n = sz(s);
	memset(cnt, 0, sizeof cnt);
	int ans = 0;
	for(int i = 0; i < n; i++){
	    a[i] = s[i] - '0';
	    ans = max(ans, ++cnt[a[i]]);
	}
	for(int i = 0; i < 10; i++){
	    for(int j = i+1; j < 10; j++){
		int lst = -1, num = 0;
		for(int k = 0; k < n; k++){
		    if(a[k] == i){
			if(lst != 0)
			    lst = 0, num++;
		    }
		    if(a[k] == j){
			if(lst != 1)
			    lst = 1, num++;
		    }
		}
		ans = max(ans, num - (num & 1));
	    }
	}
	cout << n - ans << "\n";
    }
    return 0;
}