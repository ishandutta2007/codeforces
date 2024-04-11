#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxL = 8000000;

struct Node {
	int value;
	Node *L;
	Node *R;

	Node(int value, Node *L, Node *R) : value(value), L(L), R(R) {}
};

Node *build(int l, int r, int value = 0) {
	if (l == r) {
		return new Node(value, NULL, NULL);
	}
	Node *L = build(l, (l + r) / 2, value);
	Node *R = build((l + r) / 2 + 1, r, value);
	return new Node(value, L, R);
}

int get(Node *root, int l, int r, int cl, int cr) {
	if (cl > cr) {
		return 0;
	}
	if (l == cl && r == cr) {
		return root->value;
	}

	if (cl > (l + r) / 2) {
		return get(root->R, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(root->L, l, (l + r) / 2, cl, cr);
	}

	int A = get(root->L, l, (l + r) / 2, cl, (l + r) / 2);
	int B = get(root->R, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return max(A, B);
}

/*int getlastlessthanorequal(Node *root, int value) {
	if (root->value <= value) {
		return root->r;
	}
	if (root->l == root->r) {
		return -1;
	}
	if (root->L->value <= value) {
		return max(root->L->r, getlastlessthanorequal(root->R, value));
	}
	return getlastlessthanorequal(root->L, value);
}*/

int getlastlessthanorequal(Node *root, int l, int r, int value) {
	if (root->value <= value) {
		return r;
	}
	if (l == r) {
		return -1;
	}
	if (root->L->value <= value) {
		return max((l + r) / 2, getlastlessthanorequal(root->R, (l + r) / 2 + 1, r, value));
	}
	return getlastlessthanorequal(root->L, l, (l + r) / 2, value);
}

int getlastgreaterthanorequal(Node *root, int l, int r, int value) {
	if (root->value < value) {
		return -1;
	}
	if (l == r) {
		return l;
	}
	if (root->R->value >= value) {
		return getlastgreaterthanorequal(root->R, (l + r) / 2 + 1, r, value);
	}
	return getlastgreaterthanorequal(root->L, l, (l + r) / 2, value);
}

Node *update(Node *root, int l, int r, int k, int value) {
	Node *current = new Node(value, root->L, root->R);
	if (l == r) {
		current->value = value;
		return current;
	}
	
	if (k > (l + r) / 2) {
		current->R = update(root->R, (l + r) / 2 + 1, r, k, value);
	} else {
		current->L = update(root->L, l, (l + r) / 2, k, value);
	}
	current->value = max(current->L->value, current->R->value);
	return current;
}

void updatesimple(Node *root, int l, int r, int k, int value) {
	if (l == r) {
		root->value = value;
		return;
	}

	if (k > (l + r) / 2) {
		updatesimple(root->R, (l + r) / 2 + 1, r, k, value);
	} else {
		updatesimple(root->L, l, (l + r) / 2, k, value);
	}
	root->value = max(root->L->value, root->R->value);
}

const int maxN = 410000;
int n, m;
int h[maxN];
int a[maxN], b[maxN];

Node *t[maxN];
Node *root;

int res[maxN];

void gen() {
	int n = 400000;
	int m = 400000;
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", i);
	}
	printf("\n");
	for (int i = 0; i < m; ++i) {
		printf("%d %d\n", i + 1, n + i);
	}
}

vector < int > order;

bool comp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	//return 0;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
		order.push_back(i);
	}

	sort(order.begin(), order.end(), comp);

	t[n] = build(0, n, -1000000000);
	t[n] = update(t[n], 0, n, 0, 1000000000);
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		int index = getlastgreaterthanorequal(t[i + 1], 0, n, h[i] + 1);

		ans = max(ans, index + 1);

		if (h[i] > get(t[i + 1], 0, n, index + 1, index + 1)) {
			t[i] = update(t[i + 1], 0, n, index + 1, h[i]);
		} else {
			t[i] = t[i + 1];
		}
	}

	root = build(0, n, 1000000000);
	updatesimple(root, 0, n, 0, -1000000000);

	int curindex = 0;
	for (int s = 0; s < order.size(); ++s) {
		int i = order[s];
		int index = a[i];
		while (curindex < index) {
			int pos = getlastlessthanorequal(root, 0, n, h[curindex] - 1);
			if (h[curindex] < get(root, 0, n, pos + 1, pos + 1)) {
				updatesimple(root, 0, n, pos + 1, h[curindex]);
			}
			++curindex;
		}

		int x = getlastlessthanorequal(root, 0, n, b[i] - 1);
		int y = getlastgreaterthanorequal(t[index + 1], 0, n, b[i] + 1);
		if (x + y + 1 >= ans) {
			res[i] = x + y + 1;
			continue;
		}

		int ox = getlastlessthanorequal(root, 0, n, h[index] - 1);
		int oy = getlastgreaterthanorequal(t[index + 1], 0, n, h[index] + 1);
		if (ox + oy + 1 < ans) {
			res[i] = ans;
			continue;
		}

		const int D = 50;
		for (int j = max(0, ox - D); j <= min(ans, ox + D); ++j) {
			if (get(root, 0, n, j, j) < get(t[index + 1], 0, n, ans - j, ans - j)) {
				res[i] = ans;
				break;
			}
		}
		if (res[i] == ans) {
			continue;
		}

		res[i] = ans - 1;
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\n", res[i]);
	}

	return 0;

	/*int ans = get(rootl[n], 0, cntp - 1);

	for (int i = 0; i < m; ++i) {
		int index = a[i];
		int x = get(rootl[index], 0, b[i] - 1);
		int y = get(rootr[index + 1], b[i] + 1, cntp - 1);
		if (x + 1 + y >= ans) {
			printf("%d\n", x + 1 + y);
			continue;
		}
		int ox = get(rootl[index], 0, h[index] - 1);
		int oy = get(rootr[index + 1], h[index] + 1, cntp - 1);
		if (ox + oy + 1 < ans) {
			printf("%d\n", ans);
			continue;
		}
		if (get(tl[index], ox + 1, ox + 1) < get(tr[index + 1], oy, oy)) {
			printf("%d\n", ans);
			continue;
		}
		if (get(tl[index], ox, ox) < get(tr[index + 1], oy + 1, oy + 1)) {
			printf("%d\n", ans);
			continue;
		}
		printf("%d\n", ans - 1);
	}

	cerr << clock() << endl;*/

	return 0;
}