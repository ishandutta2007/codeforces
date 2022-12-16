// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-04

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 310, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn][maxn], b[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		cin >> a[i][j];
	bool bad = 0;
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
		int cnt = 0;
		for(int k = 0; k < 4; k++){
		    int x = i + dx[k], y = j + dy[k];
		    if(x >= 0 && y >= 0 && x < n && y < m)
			cnt++;
		}
		bad|= cnt < a[i][j];
		b[i][j] = cnt;
	    }
	}
	if(bad){
	    cout << "NO\n";
	}
	else{
	    cout << "YES\n";
	    for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		    cout << b[i][j] << " \n"[j == m-1];
	}		    
    }
    return 0;
}