// Codeforces - mycopka

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef int64_t ll;

const ll N = (ll)(1e6) + 666;
const ll INF = (ll)(1e17) + 666;

struct Point {
	ll x, y, cost;

	Point(ll x, ll y, ll cost)
		: x(x), y(y), cost(cost) {}

	bool operator <(Point other) {
		return y < other.y;
	}
};

struct Result {
	ll sum, best_sum;

	Result(ll x = 0) 
		: sum(x), best_sum(x) {}

	Result(Result left, Result right) {
		sum = left.sum + right.sum;
		best_sum = max(left.best_sum, left.sum + right.best_sum);
	}
};

typedef struct Node* pNode;
struct Node {
	pNode child_left, child_right;
	ll left, right;
	Result result;

	Node(ll left, ll right)
		: left(left), right(right) {
			child_left = child_right = nullptr;
		}
};

pNode build(ll left, ll right) {
	pNode root = new Node(left, right);
	if (right - left == 1) {
		return root;
	}
	root->child_left = build(left, left + right >> 1);
	root->child_right = build(left + right >> 1, right);
	return root;
}

void add(pNode root, ll id, ll delta) {
	if (root->left >= id + 1 || root->right <= id) {
		return;
	}
	if (root->right - root->left == 1) {
		root->result.sum += delta;
		root->result.best_sum += delta;
		return;
	}
	add(root->child_left, id, delta);
	add(root->child_right, id, delta);
	root->result = Result(root->child_left->result, root->child_right->result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	ll n, m, k;
	cin >> n >> m >> k;
	vector<Point> points;

	vector<pair<ll, ll>> a;
	for (ll i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		a.emplace_back(x, y);
	}
	a.emplace_back(N - 1, INF);
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.first == b.first; }) - a.begin());
	for (ll i = (ll)a.size() - 1; i > 0; --i) {
		points.emplace_back(a[i - 1].first, 0, -a[i].second + a[i - 1].second);
	}
	points.emplace_back(0, 0, -a[0].second);
	
	a.clear();
	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		a.emplace_back(x, y);
	}
	a.emplace_back(N - 1, INF);
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.first == b.first; }) - a.begin());
	for (ll i = (ll)a.size() - 1; i > 0; --i) {
		points.emplace_back(0, a[i - 1].first, -a[i].second + a[i - 1].second);
	}
	points.emplace_back(0, 0, -a[0].second);

	for (ll i = 0; i < k; ++i) {
		ll x, y, z;
		cin >> x >> y >> z;
		points.emplace_back(x, y, z);
	}

	sort(points.begin(), points.end());

	ll result = -INF;

	pNode root = build(0, N);

	ll ptr = 0;
	while (ptr < points.size()) {
		ll y = points[ptr].y;
		while (ptr < points.size() && points[ptr].y == y) {
			add(root, points[ptr].x, points[ptr].cost);
			++ptr;
		}
		result = max(result, root->result.best_sum);
	}

	cout << result << endl;

	return 0;
}