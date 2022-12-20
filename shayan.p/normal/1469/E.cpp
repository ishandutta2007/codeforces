#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10;

bool bad[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int k, n;
	cin >> n >> k;
	string s;
	cin >> s;
	fill(bad, bad + n + 3, 0);
	deque<int> d;
	for(int i = 0; i < n; i++){
	    if(s[i] == '0')
		d.PB(i);
	    while(sz(d) && i-k == d[0])
		d.pop_front();
	    if(i >= k-1){
		if(d.empty())
		    bad[0] = 1;
		else if(i - d[0] <= 20){
		    int msk = 0;
		    for(int x : d)
			msk+= 1<<(i-x);
		    if(msk < maxn)
			bad[msk] = 1;
		}
	    }
	}
	int ans = 0;
	while(bad[ans])
	    ans++;
	if(32-__builtin_clz(ans) > k){
	    cout << "NO\n";
	    continue;
	}
	cout << "YES\n";
	for(int i = 0; i < k; i++){
	    if(k-1-i > 24)
		cout << 0;
	    else
		cout << bit(ans, k-1-i);
	}
	cout << "\n";
    }
    return 0;
}