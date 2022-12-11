#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define INF 2000000000

using namespace std;

struct shirt {
	int price;
	int front;
	int back;
	shirt(int p, int f, int b) : price(p), front(f), back(b) {}
};

const bool operator < (const shirt a, const shirt b) {
	return (a.price < b.price);
}

int main() {
	int n; scanf("%d", &n);
	vector<int> prices(n, 0);
	vector<int> fcolor(n, 0);
	vector<int> bcolor(n, 0);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &prices[i]);
	}
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &fcolor[i]);
		--fcolor[i];
	}
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &bcolor[i]);
		--bcolor[i];
	}
	
	vector<shirt> inventory(n, shirt(0, 0, 0));
	
	vector<set<shirt>> deals(3, set<shirt>());
	
	for (int i = 0; i < n; ++i) {
		inventory[i].price = prices[i];
		inventory[i].front = fcolor[i];
		inventory[i].back = bcolor[i];
		deals[fcolor[i]].insert(inventory[i]);
		if (fcolor[i] != bcolor[i]) {
			deals[bcolor[i]].insert(inventory[i]);
		}
	}
	
	
	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int ci; scanf("%d", &ci); --ci;
		if (deals[ci].size() == 0) {
			printf("%s-1", (i == 0 ? "" : " "));
			continue;
		}
		shirt cheapest = *(deals[ci].begin());
		printf("%s%d", (i == 0 ? "" : " "), cheapest.price);
		deals[cheapest.front].erase(cheapest);
		if (cheapest.front != cheapest.back) {
			deals[cheapest.back].erase(cheapest);
		}
	}
	return 0;
	
}