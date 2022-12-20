#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int n, k;
pii p[maxn];

int solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
	cin >> p[i].F >> p[i].S;
    if(n == 1)
	return 0;
    for(int i = 0; i < n; i++){
	int dis = 0;
	for(int j = 0; j < n; j++)
	    dis = max(dis, abs(p[i].F - p[j].F) + abs(p[i].S - p[j].S));
	if(dis <= k)
	    return 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
    return 0;
}