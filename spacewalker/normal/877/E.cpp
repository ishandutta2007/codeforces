#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> childList;
vector<int> subEnter, subExit;
vector<int> origLight;
vector<int> lightInTrav;
vector<int> trav;

void place(int i) {
	subEnter[i] = subExit[i] = trav.size();
	trav.push_back(i);
	lightInTrav.push_back(origLight[i]);
	for (int next : childList[i]) {
		//printf("moving to %d from %d\n", next, i);
		place(next);
		subExit[i] = trav.size() - 1;
	}
}

class LightSwitch {
	int lBound, rBound;
	LightSwitch *left, *right = NULL;
	void propagate() {
		if (!pendingSwitch) {
			return;
		}
		oneCount = (rBound - lBound + 1) - oneCount;
		pendingSwitch = false;
		if (lBound != rBound) {
			left->pendingSwitch = !left->pendingSwitch;
			right->pendingSwitch = !right->pendingSwitch;
		}
	}
public:
	int oneCount = 0;
	bool pendingSwitch = false;
	LightSwitch() {}
	LightSwitch(vector<int> &orig, int al, int ar) {
		lBound = al;
		rBound = ar;
		if (al == ar) {
			oneCount = orig[lBound];
		} else {
			int mid = (al + ar) / 2;
			left = new LightSwitch(orig, al, mid);
			right = new LightSwitch(orig, mid + 1, ar);
			oneCount = left->oneCount + right->oneCount;
		}
	}
	~LightSwitch() {
		if (lBound != rBound) {
			delete left;
			delete right;
		}
	}
	void update(int al, int ar) {
		propagate();
		if (al <= lBound && rBound <= ar) {
			pendingSwitch = true;
			propagate();
		} else if ((rBound < al || ar < lBound)) {
			return;
		} else {
			left->update(al, ar);
			right->update(al, ar);
			oneCount = left->oneCount + right->oneCount;
		}
	}
	int query(int al, int ar) {
		propagate();
		if (al <= lBound && rBound <= ar) {
			return oneCount;
		} else if ((rBound < al || ar < lBound)) {
			return 0;
		} else {
			return left->query(al, ar) + right->query(al, ar);
		}
	}
};

int main() {
	int n; scanf("%d", &n);
	childList.resize(n);
	subEnter.resize(n);
	subExit.resize(n);
	trav.reserve(n);
	lightInTrav.reserve(n);
	origLight.resize(n);
	for (int i = 1; i < n; ++i) {
		int pi; scanf("%d", &pi); --pi;
		childList[pi].push_back(i);
		//printf("%d is child of %d\n", pi, i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &origLight[i]);
	}
	place(0);
	int q; scanf("%d", &q);
	LightSwitch danil(lightInTrav, 0, n-1);
	char type[4] = "...";
	for (int qta = 0; qta < q; ++qta) {
		int v; scanf("%s %d", type, &v); --v;
		if (type[0] == 'p') {
			danil.update(subEnter[v], subExit[v]);
		} else {
			printf("%d\n", danil.query(subEnter[v], subExit[v]));
		}
	}
	return 0;
}