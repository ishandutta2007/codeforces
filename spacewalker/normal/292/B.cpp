#include <vector>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main () {
	int n, m; scanf("%d %d", &n, &m);

	vector<vector<int>> net(n, vector<int>());

	int temp1, temp2;

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &temp1, &temp2);
		--temp1; --temp2;
		net[temp1].push_back(temp2);
		net[temp2].push_back(temp1);
	}

	// do a single search
	vector<bool> visited(n, false);
	stack<int> DFSStack;
	DFSStack.push(0); 
	while (DFSStack.size() > 0) {
		int cVertex = DFSStack.top(); DFSStack.pop();
		visited[cVertex] = true;
		for (int adj : net[cVertex]) {
			if (!visited[adj]) {
				DFSStack.push(adj);
			}
		}
	}

	for (bool b : visited) {
		if (!b) { // there was some unvisited vertex
			printf("unknown topology");
			return 0; // end already
		}
	}

	// if not, check degrees
	int oneCount = 0;
	int twoCount = 0;
	int maxDeg = 0;

	for (vector<int> adjToV : net) {
		if (adjToV.size() == 1) {
			++oneCount;
		} else if (adjToV.size() == 2) {
			++twoCount;
		} else {
			maxDeg = max((int)adjToV.size(), maxDeg);
		}
	}

	// if twoCount == n, it's a ring
	if (twoCount == n) {
		printf("ring topology");
	} else if (oneCount == 2 && twoCount == n-2) {
		printf("bus topology");
	} else if (oneCount == n-1 && maxDeg == n-1) {
		printf("star topology");
	} else {
		printf("unknown topology");
	}

	return 0;
}