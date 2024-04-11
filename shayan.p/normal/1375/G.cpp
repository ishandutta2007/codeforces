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

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<int> v[maxn];
int cnt[2];

void dfs(int u, int h = 0, int par = -1){
    cnt[h&1]++;
    for(int y : v[u])
	if(y != par)
	    dfs(y, h+1, u);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    return cout << min(cnt[0], cnt[1])-1 << "\n", 0;
}