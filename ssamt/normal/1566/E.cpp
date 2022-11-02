#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int answer;

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
			a[j].push_back(i);
		}
};

int cur(AdjGraph& tree, int u, int parent) {
	int i;
	int child = 0;
	for(i=0; i<tree.a[u].size(); i++) {
		if(tree.a[u][i] != parent) {
			int exist = cur(tree, tree.a[u][i], u);
			if(exist) {
				child++;
			}
		}
	}
	if(child > 0) {
		answer += child-1;
		return 0;
	} else {
		return 1;
	}
}

int main() {
	int h, i, j, k;
	int t, n, m;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		AdjGraph tree(n);
		for(j=0; j<n-1; j++) {
			scanf("%d %d", &u, &v);
			tree.add(u-1, v-1);
		}
		answer = 1;
		cur(tree, 0, 0);
		printf("%d\n", answer);
	}
}