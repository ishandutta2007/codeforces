#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
const int N = 5e5 + 1;
typedef pair<int, int> duo;

int t, n, a[N], b[N];
struct node{
	int id;
	duo seg;
	bool operator<(const node &b) const{
		return seg < b.seg;
	}
} nd[N];

struct pqnode{
	int id, r;
	bool operator<(const pqnode &b) const{
		return r > b.r;
	}
};

priority_queue<pqnode> pq;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			nd[i].id = i;
			scanf("%d", &b[i]);
			if(b[i] == 0){
				nd[i].seg.first = i + 1;
				nd[i].seg.second = n;
			}
			else{
				nd[i].seg.second = i / b[i];
				nd[i].seg.first = i / (b[i] + 1) + 1;
			}

		}
		sort(nd + 1, nd + 1 + n);
		int p = 1;
		for (int i = 1; i <= n; i++){
			while(p <= n && nd[p].seg.first == i){
				pqnode tmp;
				tmp.id = nd[p].id;
				tmp.r = nd[p].seg.second;
				pq.push(tmp);
				p++;
			}
			a[pq.top().id] = i;
			pq.pop();
		}
			for (int i = 1; i <= n; i++)
				printf("%d ", a[i]);
		putchar('\n');
	}
	return 0;
}