#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10, INF = 15e8;

ll a[maxn], used[maxn];
int n, k;

priority_queue<pii, vector<pii>, greater<pii> > pq;

void extract(){
    pii p = pq.top();
    int h = p.F;
    int id = p.S;
    pq.pop();
    if(id == -1)
	return;
    used[id]++;
    if(a[id] == used[id])
	return;
    if(used[id] & 1){
	pq.push({h, id});
    }
    else{
	pq.push({h+1, id});
    }
}

bool ok(int len){
    while(sz(pq))
	pq.pop();
    
    ll cnt = 1;
    pq.push({0, -1});
    for(int i = 0; sz(pq) && i < n; i++){
	int tp = pq.top().F;
	extract();
	if(tp > len)
	    return 0;
	cnt--;
	ll x = a[i]/2;
	ll y = a[i] & 1;
	cnt+= 1ll * (min(tp + 1 + x, ll(len)) - tp - 1) * 2;
	if(tp + 1 + x + 1 <= len)
	    cnt+= y;
	if(cnt >= k)
	    return 1;
	used[i] = 0;
	pq.push({tp + 2, i});
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    cin >> n >> k;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	--a[i];
    }
    sort(a, a + n, greater<int>());
    int l = 0, r = INF;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	if(ok(mid))
	    r = mid;
	else
	    l = mid;
    }
    int ans = r;
    if(ans == INF)
	ans = -1;
    return cout << ans << endl, 0;
}