// Never let them see you bleed...
// Shayan.P  2020-04-26

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

int cnt[maxn], lim[maxn];
vector<int> ans[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	cnt[x]++;
    }
    for(int i = 1; i <= k; i++){
	cin >> lim[i];
    }
    int ANS = 0;
    for(int i = k; i >= 1; i--){
	int pt = 0;
	int l = -1, r = ANS;
	while(r-l > 1){
	    int mid = (l+r) >> 1;
	    if(sz(ans[mid]) == lim[i])
		l = mid;
	    else
		r = mid;
	}
	pt = r;
	while(cnt[i]){
	    while(cnt[i] && sz(ans[pt]) < lim[i])
		ans[pt].PB(i), cnt[i]--;
	    pt++;
	}
	ANS = max(ANS, pt);
    }
    cout << ANS << "\n";
    for(int i = 0; i < ANS; i++){
	cout << sz(ans[i]) << " ";
	for(int x : ans[i])
	    cout << x << " ";
	cout << "\n";
    }
    return 0;
}