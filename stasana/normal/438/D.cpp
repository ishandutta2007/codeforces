#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;
typedef struct Node* pNode;

struct Node {
	pNode child_left, child_right;
	ll left, right;
	ll value, sum;

	Node(ll left, ll right)
		: left(left), right(right) {
		sum = value = 0;
		child_left = child_right = nullptr;
	}

	void update() {
		value = max(child_left->value, child_right->value);
		sum = child_left->sum + child_right->sum;
	}
};

pNode build(vector<ll>& a, ll left, ll right) {
	pNode root = new Node(left, right);
	if (right - left == 1) {
		root->sum = root->value = a[left];
		return root;
	}
	root->child_left = build(a, left, (right + left) / 2);
	root->child_right = build(a, (right + left) / 2, right);
	root->update();
	return root;
}

ll get(pNode root, ll left, ll right) {
	if (root->left >= right || root->right <= left) {
		return 0;
	}
	if (root->left >= left && root->right <= right) {
		return root->sum;
	}
	return get(root->child_left, left, right) + get(root->child_right, left, right);
}

void set(pNode root, ll index, ll value) {
	if (root->left >= index + 1 || root->right <= index) {
		return;
	}
	if (root->right - root->left == 1) {
		root->value = root->sum = value;
		return;
	}
	set(root->child_left, index, value);
	set(root->child_right, index, value);
	root->update();
}

void f(pNode root, ll left, ll right, ll x) {
	if (root->left >= right || root->right <= left) {
		return;
	}
	if (root->value < x) {
		return;
	}
	if (root->right - root->left == 1) {
		root->value = root->sum = root->value % x;
		return;
	}
	f(root->child_left, left, right, x);
	f(root->child_right, left, right, x);
	root->update();
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	pNode root = build(a, 0, n);
	for (ll i = 0; i < m; ++i) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll left, right;
			cin >> left >> right;
			cout << get(root, left - 1, right) << "\n";
		}
		if (type == 2) {
			ll left, right, x;
			cin >> left >> right >> x;
			f(root, left - 1, right, x);
		}
		if (type == 3) {
			ll index, x;
			cin >> index >> x;
			set(root, index - 1, x);
		}
	}
	return 0;
}