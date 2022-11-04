#include <cstdio>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int N = 501;

int t, n, a, del;
deque<int> dq;
struct node{
	int p, c;
};
vector<node> add;
vector<int> seg;
queue<int> que;

int main(){
	scanf("%d", &t);
	while(t--){
		del = 0;
		dq.clear();
		add.clear();
		seg.clear();
		scanf("%d", &n);
		while(n--){
			scanf("%d", &a);
			dq.push_back(a);
		}
		int p;
		do{
			p = 1;
			while(p < dq.size() && dq[p] != dq[0]) p++;
			if(p >= dq.size()) break;
			for(int d = 1; d < p; d++)
				add.push_back((node){del + p + d, dq[d]});
			del += 2 * p;
			seg.push_back(2 * p);
			dq.pop_front();
			while(--p){
				que.push(dq[0]);
				dq.pop_front();
			}
			dq.pop_front();
			while(!que.empty()){
				dq.push_front(que.front());
				que.pop();
			}
		}while(true);
		if(dq.empty()){
			cout << add.size() << '\n';
			for(node &nd : add)
				printf("%d %d\n", nd.p, nd.c);
			cout << seg.size() << '\n';
			for(int x : seg)
				printf("%d ", x);
			putchar('\n');
		}else puts("-1");
	}
	return 0;
}