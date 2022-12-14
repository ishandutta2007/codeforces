//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 9;
ll arrr[N],pl[N];
pair<ll,ll> arr[N];
ll t[N],sum[N];
int n;
void update(int i,int j,int v = 1,int b = 0,int e = n-1) {
	if(i > e || b > j) return;
	if(b == e) {
		t[v] = 0;
		sum[v] = arr[b].first;
		return;
	}
	ll mid = b + e >> 1,l = v << 1,r = l | 1,sz1 = mid - b + 1,sz2 = e - mid;
	update(i,j,l,b,mid);
	update(i,j,r,mid+1,e);
	t[v] = t[l] + t[r] + sz2 * -sum[l] + sz1 * sum[r];
	sum[v] = sum[l] + sum[r];
	return;
}
ll query(int i,int j,int v = 1,int b = 0,int e = n-1) {
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) {
		return t[v] + ((ll)b - i) * sum[v] - ((ll)j - e) * sum[v];
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i].first,arr[i].second = i;
	sort(arr,arr+n);
	for(int i = 0; i < n;i++) pl[arr[i].second] = i;
	update(0,n-1);
	int m; cin >> m;
	while(m--) {
		int c; cin >> c; --c;
		if(c) {
			ll lf,rg; cin >> lf >> rg;
			int l = lower_bound(arr,arr+n,make_pair(lf,(ll)-1)) - arr;
			int r = lower_bound(arr,arr+n,make_pair(rg+1,(ll)-1)) - arr;
			--r;
			if(r < l) cout << 0 << '\n';
			else cout << query(l,r) << '\n';
		} else {
			int l = 0,r = 0;
			int v,d; cin >> v >> d;
			--v;
			int id = pl[v];
			arr[id].first += d;
			l = id;
			r = id;
			if(id && arr[id].first < arr[id-1].first) {
				while(l && arr[l].first < arr[l-1].first) swap(arr[l],arr[l-1]) , l , pl[arr[l].second]++,pl[arr[l-1].second]--,l--;
			} else {
				while(r != n-1 && arr[r].first > arr[r+1].first) swap(arr[r],arr[r+1]), r,pl[arr[r+1].second]++,pl[arr[r].second]--,r++;
			}
			update(l,r);
		}
	}
}