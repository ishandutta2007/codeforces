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

int cnt[maxn], a[maxn];

int solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cnt[i] = 0;
    }
    for(int i = 0; i < n; i++){
	cin >> a[i];
	a[i]--;
    }
    cnt[a[0]]++;
    cnt[a[n-1]]++;
    for(int i = 0; i < n-1; i++){
	if(a[i] == a[i+1])
	    cnt[a[i]]+= 2;
    }
    int sm = 0, mxid = 0;
    for(int i = 0; i < n; i++){
	sm+= cnt[i];
	if(cnt[mxid] < cnt[i])
	    mxid = i;
    }
    if(cnt[mxid] <= (sm/2)+1)
	return (sm/2)-1;
    int df = cnt[mxid] - (sm/2) - 1;
    int can = 0;
    for(int i = 0; i < n-1; i++){
	if(a[i] != a[i+1] && a[i] != mxid && a[i+1] != mxid)
	    can++;
    }
    if(can >= df)
	return (sm/2)-1 + df;
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