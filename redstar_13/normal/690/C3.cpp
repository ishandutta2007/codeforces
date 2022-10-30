#include <bits/stdc++.h>
#define rep(i, a, b) for(i=(a); i<(b); i++)

using namespace std;
template <class T> inline void smax(T &a, T b) {if(a<b) a=b;}
template <class T> inline void smin(T &a, T b) {if(a>b) a=b;} 
#define NN 200020

struct NODE {
	int f, par;
	vector<int> adj, wei;

};

NODE node[NN];
int root=0, st[NN], nn;

int down(int u) {
	int i, deg, v;
	if(node[u].f==0) return 0;
	for(deg=node[u].adj.size(), i=0; i<deg; i++) {
		v=node[u].adj[i];
		if(v==node[u].par) smax(node[u].wei[i], node[u].f);
		else smax(node[v].f, node[u].f+1);
	}
	node[u].f=0;
}
	
int newnode(int k) {
	node[k].adj.clear();
	node[k].wei.clear();
	node[k].par=-1;
	node[k].f=0;
	return k;
}

int Splay(int u) {
	int i;
	nn=0;
	for(; u!=root; u=node[u].par) st[nn++]=u;
	for(i=nn-1; i>=0; i--) {
		u=st[i];
		down(u);
		node[root].par=u;
		node[u].par=-1;
		root=u;
	}
}

int add(int u) {
	int w=0, i, v, deg;
	for(deg=node[root].adj.size(), i=0; i<deg; i++) {
		smax(w, node[root].wei[i]);
	}
	node[root].adj.push_back(u);
	node[root].wei.push_back(1);
	node[root].f=1;
	node[root].par=u;
	node[u].adj.push_back(root);
	node[u].wei.push_back(w+1);
	root=u;
	node[root].par=-1;
}
void display(int k) {
	printf("----------->%d\n", k);
	int i, j, deg, v;
	rep(i, 0, k+1) {
		printf("---->%d\n", i);
		printf("par %d f %d\n", node[i].par, node[i].f);
		for(deg=node[i].adj.size(), j=0; j<deg; j++) {
			v=node[i].adj[j];
			printf("%d ", v);
		} puts("adj");
		for(deg=node[i].wei.size(), j=0; j<deg; j++) {
			v=node[i].wei[j];
			printf("%d ", v);
		} puts("wei");
	}
}
int main() {
	int n, i, u, pre=-1;
	scanf("%d", &n);
	root=newnode(0);
	rep(i, 1, n) {
		if(i>1) printf(" ");
		scanf("%d",&u);
		u--;
		Splay(u);
		newnode(i);
		add(i);
		smax(pre, node[root].wei[0]);
		printf("%d", pre);
//		display(i);
	} puts("");
	
	return 0;
}