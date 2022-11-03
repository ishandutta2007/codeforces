#include <cstdio>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

const int MAXL = 3E5 + 10, MAXK = 20;

struct TrieGraph{
	static const int SIGMA = 26, MAXNode = MAXL + 10 << 1;
	struct node{
		bool vis;
		node *child[SIGMA], *fail;
		int mark;

		void init(){
			vis = false;
			memset(child, 0, sizeof(child));
			mark = 0;
		}
	};
	static node a[MAXNode];
	static int lastNode;
	static vector<node*> lst;

	node *root;

	node* getNode(){
		node* ret;
		if (lst.empty())
			ret = a + (lastNode++);
		else
			ret = lst.back(), lst.pop_back();
		ret->init();
		return ret;
	}

	void backNode(node *u){
		lst.push_back(u);
	}

	TrieGraph(){
		root = getNode();
	}

	~TrieGraph(){
		queue<node*> Q;
		node *u;
		root->vis = true;
		Q.push(root);
		for (; !Q.empty(); Q.pop()){
			u = Q.front();
			backNode(u);
			for (int i = 0; i < SIGMA; ++i)
				if (u->child[i] && !u->child[i]->vis){
					u->child[i]->vis = true;
					Q.push(u->child[i]);
				}
		}
	}

	void insert(const char *s){
		node *u = root;
		int i;
		for (; *s; ++s){
			i = *s - 'a';
			if (!u->child[i])
				u->child[i] = getNode();
			u = u->child[i];
		}
		++u->mark;
	}

	void build(){
		queue<node*> Q;
		root->fail = root;
		for (int i = 0; i < SIGMA; ++i){
			if (root->child[i])
				root->child[i]->fail = root, Q.push(root->child[i]);
			else
				root->child[i] = root;
		}
		node *u;
		for (; !Q.empty(); Q.pop()){
			u = Q.front();
			u->mark += u->fail->mark;
			for (int i = 0; i < SIGMA; ++i)
				if (u->child[i])
					u->child[i]->fail = u->fail->child[i], Q.push(u->child[i]);
				else
					u->child[i] = u->fail->child[i];
		}
	}

	ll match(const char *s){
		node *u = root;
		ll ret = u->mark;
		for (; *s; ++s){
			u = u->child[*s - 'a'];
			ret += u->mark;
		}
		return ret;
	}
};

TrieGraph::node TrieGraph::a[TrieGraph::MAXNode];
int TrieGraph::lastNode = 0;
vector<TrieGraph::node*> TrieGraph::lst;

char buf[MAXL];

vector<string> a[2];
TrieGraph *b[2][MAXK];

void insert(vector<string> &a, TrieGraph *b[], char *s){
	a.push_back(string(s));
	int i = 0;
	for (; i < MAXK && b[i]; ++i)
		delete b[i], b[i] = NULL;
	b[i] = new TrieGraph;
	for (int j = a.size() ^ 1 << i; j < a.size(); ++j)
		b[i]->insert(a[j].c_str());
	b[i]->build();
}

int main(){
	int q;
	scanf("%d", &q);
	for (int qi = 1; qi <= q; ++qi){
		int type;
		scanf("%d%s", &type, buf);

		if (type == 1)
			insert(a[0], b[0], buf);
		else if (type == 2)
			insert(a[1], b[1], buf);
		else if (type == 3){
			ll ret = 0;
			for (int i = 0; i < MAXK; ++i){
				if (b[0][i])
					ret += b[0][i]->match(buf);
				if (b[1][i])
					ret -= b[1][i]->match(buf);
			}
			printf("%I64d\n", ret);
			fflush(stdout);
		}
	}
	return 0;
}