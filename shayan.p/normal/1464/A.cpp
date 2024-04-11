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

int f[maxn];
bool mark[maxn];
bool mark2[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, m;
	cin >> n >> m;
	fill(f + 1, f + n + 1, -1);
	fill(mark + 1,  mark + n + 1, 0);
	fill(mark2 + 1,  mark2 + n + 1, 0);

	while(m--){
	    int x, y;
	    cin >> x >> y;
	    f[x] = y;
	    mark2[y] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
	    if(mark2[i] || mark[i] || f[i] == -1 || f[i] == i)
		continue;
	    int tmp = i;
	    while(tmp != -1 && !mark[tmp])
		mark[tmp] = 1, tmp = f[tmp], ans++;
	    if(mark[tmp])
		ans++;
	    else
		ans--;
	}
	for(int i = 1; i <= n; i++){
	    if(mark[i] || f[i] == -1 || f[i] == i)
		continue;
	    int tmp = i;
	    while(tmp != -1 && !mark[tmp])
		mark[tmp] = 1, tmp = f[tmp], ans++;
	    if(mark[tmp])
		ans++;
	    else
		ans--;
	}
	cout << ans << "\n";
    }
    return 0;
}