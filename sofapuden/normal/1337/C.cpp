#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define dep(i,a,b) for(ll i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (ll fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (ll fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

vvi tr;
vector<pair<ll,ll>> de;
set<ll> vis;
queue<pair<ll, ll>> q;
queue<pair<ll, ll>> q2;
vi dis;
set<ll> done;

void bfs(ll ind, ll val) {
	de[ind].first = val;
	de[ind].second = ind;
	rep(i, 0, tr[ind].size()) {
		if (!vis.count(tr[ind][i])) {
			vis.insert(tr[ind][i]);
			pair<ll, ll> tmpp;
			tmpp.first = tr[ind][i];
			tmpp.second = val+1;
			q.push(tmpp);
		}
	}
	return;
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ll t = 1;
	while (t--) {

		ll n, k;
		cin >> n >> k;
		tr.resize(n);
		pair<ll, ll> tmp;
		tmp.first = 0;
		tmp.second = 0;
		de.resize(n,tmp);
		dis.resize(n, 0);
		rep(i, 0, n - 1) {
			ll tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			tmp1--; tmp2--;
			tr[tmp1].push_back(tmp2);
			tr[tmp2].push_back(tmp1);
		}
		pair<ll,ll>start = make_pair(0, 0);
		q.push(start);
		vis.insert(0);
		while (!q.empty()) {
			pair<ll, ll> tmpp = q.front();
			q.pop();
			bfs(tmpp.first, tmpp.second);
		}
		vector<pair<ll, ll>> code = de;
		sort(all(de));
		reverse(all(de));
		rep(i, 0, de.size()) {
			done.insert(de[i].second);
			rep(ii, 0, tr[de[i].second].size()) {
				if (!done.count(tr[de[i].second][ii])) {
					dis[tr[de[i].second][ii]] += dis[de[i].second] + 1;
				}
			}
		}
		rep(i, 0, code.size()) {
			dis[i] = code[i].first - dis[i];
		}
		sort(all(dis));
		reverse(all(dis));
		ll ans = 0;
		rep(i, 0, k) {
			ans += dis[i];
		}
		cout << ans << endl;
	}
	return 0;
}