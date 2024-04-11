#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
struct D {
	int v1; int v2;
	vector<int> *i;
	bool operator < (const D&b) const {
		if (v1 != b.v1) return v1 < b.v1;
		return v2 < b.v2;
	}
}inp[1000010];

map<D, int> rev;
vector<int> ans;
vector<int > anp;

typedef long long LL;
LL cross(LL a, LL b, LL c, LL d) {
	return a*d-b*c;
}
int main() {
	scanf("%d", &n);
	int s=0;
	for (int i=0; i<n; i++) {
		scanf("%d%d", &inp[s].v1, &inp[s].v2);
		if (rev.count(inp[s])) {
			inp[rev[inp[s]]].i->push_back(i);
		} else {
			inp[s].i = new vector<int>();
			inp[s].i->push_back(i);
			rev[inp[s]] = s;
			s++;
		}
	}
	sort(inp, inp+s);
	int maa = -1;
	for (int i=s-1; i>=0; i--) {
		if (inp[i].v2 > maa) {
			maa = inp[i].v2;
			if (ans.size() < 2) ans.push_back(i);
			else {
				while (ans.size() >= 2) {
					D &p1 = inp[ans.back()], &p2 = inp[ans[ans.size()-2]];
					if ((LL)inp[i].v1 * p2.v2 * (p2.v1-p1.v1) * (inp[i].v2-p1.v2) - (LL)inp[i].v2 * p2.v1 * (p2.v2-p1.v2) * (inp[i].v1-p1.v1)  <= 0) break;
					ans.pop_back();
				}
				ans.push_back(i);
			}
		}
	}
	for (int i=0; i<ans.size(); i++) {
		for (int j=0; j<inp[ans[i]].i->size(); j++) anp.push_back((*inp[ans[i]].i)[j]);
	}
	sort(anp.begin(), anp.end());
	for (int i=0; i<anp.size(); i++) {
		printf("%d%c", anp[i]+1, " \n"[i==anp.size()-1]);
	}
	return 0;
}