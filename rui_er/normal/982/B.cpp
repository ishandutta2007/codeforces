//By: Luogu@rui_er(122461)..qwq
#include <bits/stdc++.h>
using namespace std;//
const int N = 2e5+5;

int n, vis[N];
string s;
struct Node {
	int id, w;
	Node(int a=0, int b=0) : id(a), w(b) {}
	~Node() {}
	friend bool operator < (const Node &a, const Node &b) {return a.w > b.w;}
	friend bool operator > (const Node &a, const Node &b) {return a.w < b.w;}
}a[N];
priority_queue<Node> p1;
priority_queue<Node, vector<Node>, greater<Node> > p2;

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i].w);
		a[i].id = i;
		p1.push(a[i]);
	}
	cin>>s;
	for(int i=0;i<2*n;i++) {
		int type = s[i] ^ 48;
		if(!type) {
			while(!p1.empty()) {
				Node qwq = p1.top(); p1.pop();
				if(!vis[qwq.id]){printf("%d ", qwq.id); p2.push(qwq); ++vis[qwq.id]; break;}
			}
		}
		else {
			assert(p2.size());
			Node qaq = p2.top(); p2.pop();
			printf("%d ", qaq.id);
		}
	}
	return 0;
}