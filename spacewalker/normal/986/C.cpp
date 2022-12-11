#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> arr;
vector<bool> inArray;
vector<int> visitOrder;
vector<int> sccID;

int invertMask(int i) {
	return ((1 << n) - 1) & (~i);
}

void buildVisitOrder(int i) {
	if (sccID[i] != -1) return;
	sccID[i] = 1;
	if (inArray[i]) buildVisitOrder(invertMask(i));
	for (int b = 0; b < n; ++b) {
		if (i & (1 << b)) buildVisitOrder(i ^ (1 << b));
	}
	visitOrder.push_back(i);
}

void computeSCC(int i, int comp) {
	if (sccID[i] != -1) return;
	sccID[i] = comp;
	if (inArray[invertMask(i)]) computeSCC(invertMask(i), comp);
	for (int b = 0; b < n; ++b) {
		if ((i & (1 << b)) == 0) computeSCC(i ^ (1 << b), comp);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	inArray = vector<bool>(1 << n);
	sccID = vector<int>(1 << n, -1);	
	arr = vector<int>(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &arr[i]);
		inArray[arr[i]] = true;
	}
	for (int i = 0; i < (1 << n); ++i) buildVisitOrder(i);
	reverse(begin(visitOrder), end(visitOrder));
	sccID.assign(1 << n, -1);
	for (int v : visitOrder) computeSCC(v, v);
	set<int> posComps;
	for (int x : arr) posComps.insert(sccID[x]);
	printf("%lu\n", posComps.size());
	return 0;
}