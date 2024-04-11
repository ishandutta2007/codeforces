#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int cVertex = 2; //label of the next vertex to be allocated
vector<pair<int, int>> elist;

int addSplitComp(int x, int ct) {
	for (int i = 0; i < ct; ++i) {
		elist.emplace_back(x, cVertex + i);
	}
	for (int i = 0; i < ct; ++i) {
		elist.emplace_back(cVertex + i, cVertex + ct);
	}
	cVertex += ct;
	return cVertex++;
}

pair<int, int> createTridentTrail(int len, int triPart, bool toDouble) {
	int start = cVertex;
	int cHead = start;
	++cVertex;
	for (int i = 0; i < triPart; ++i) {
		cHead = addSplitComp(cHead, 3);
	}
	if (toDouble) {
		cHead = addSplitComp(cHead, 2);
	}
	for (int i = triPart + (toDouble ? 1 : 0); i < len; ++i) {
		cHead = addSplitComp(cHead, 1);
	}
	return make_pair(start, cHead);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k; cin >> k;
	vector<int> p3D1;
	vector<int> p3D2;
	int cp3 = 0;
	while (k > 0) {
	//	printf("ck = %d\n", k);
		if (k % 3 == 1) {
	//		printf("p1case\n");
			p3D1.push_back(cp3);
		} else if (k % 3 == 2) {
	//		printf("p2case\n");
			p3D2.push_back(cp3);
		}
		cp3++;
		k /= 3;
	}
	//printf("finished k decomp\n");
	vector<pair<int, int>> heads;
	for (int i : p3D1) {
		heads.push_back(createTridentTrail(cp3, i, false));
	}
	for (int i : p3D2) {
	//	printf("creating d2 component of size %d\n", i);
		heads.push_back(createTridentTrail(cp3, i, true));
	}
	for (auto p : heads) {
		elist.emplace_back(0, p.first);
		elist.emplace_back(p.second, 1);
	}
	cout << cVertex << endl;
	vector<vector<bool>> isEdge(cVertex, vector<bool>(cVertex, false));
	for (auto e : elist) {
		isEdge[e.first][e.second] = true;
		isEdge[e.second][e.first] = true;
		//cout << e.first << "<->" << e.second << endl;
	}
	for (int i = 0; i < cVertex; ++i) {
		for (int j = 0; j < cVertex; ++j) {
			cout << (isEdge[i][j] ? "Y" : "N");
		}
		cout << endl;
	}
	return 0;
}