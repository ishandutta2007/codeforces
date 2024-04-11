#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	node *back, *next, *cmp;
	int con, dist;
};

int N, K;
node *con[50000], pool[200000]; int pLast;
long long ret;

node* add_node(int S, int D, int dist)
{
	node* ret = &(pool[pLast++]);
	ret->con = D;
	ret->dist = dist;
	ret->back = con[S];
	ret->next = con[S]->next;
	if(con[S]->next) con[S]->next->back = ret;
	con[S]->next = ret;

	return ret;
}

void remove(node* nd)
{
	nd->back->next = nd->next;
	if(nd->next) nd->next->back = nd->back;
}

int buf[50000], bLast;
int buf2[50000], b2Last;
pair<int, int> bpos;

void visit1(int p, int c)
{
	buf[bLast++] = p;
	for(node* nd=con[p]->next;nd!=NULL;nd=nd->next)
		if(nd->con != c) visit1(nd->con, p);
}

void visit2(int p, int c, int d)
{
	buf[bLast++] = d;
	for(node* nd=con[p]->next;nd!=NULL;nd=nd->next)
		if(nd->con != c) visit2(nd->con, p, d + nd->dist);
}

long long find_sum(int* left, int* right)
{
	--right;
	long long rt = 0;
	while(left < right){
		while(left < right && *left + *right > K) --right;
		if(left<right) rt += right - left;
		left++;
	}
	return rt;
}

int best_point(int p, int c, int S)
{
	int ret = 1, sp = 0;
	for(node* nd=con[p]->next;nd!=NULL;nd=nd->next) if(nd->con != c){
		int tmp = best_point(nd->con, p, S);
		sp = max(sp, tmp);
		ret += tmp;
	}
	sp = max(sp, S - ret);
	bpos = min(bpos, make_pair(sp, p));
	return ret;
}

void solve(int p)
{
	bLast = 0;
	visit1(p, -1);

	if(bLast==1) return;

	bpos = make_pair(100000, -1);
	best_point(p, -1, bLast);
	int rp = bpos.second;
	//fprintf(stderr, "%d: %d\n", p, rp);

	bLast = 0;
	buf[bLast++] = 0;

	for(node* nd=con[rp]->next;nd!=NULL;nd=nd->next){
		int bp = bLast;
		visit2(nd->con, rp, nd->dist);
		sort(buf+bp, buf+bLast);

		ret -= find_sum(buf+bp, buf+bLast);
	}
	sort(buf, buf+bLast);
	ret += find_sum(buf, buf+bLast);

	for(node* nd=con[rp]->next;nd!=NULL;nd=nd->next){
		remove(nd);
		remove(nd->cmp);
		solve(nd->con);
	}
}

int main()
{
	vector<int> a, b;
	int x, y;
	node *n1, *n2;

		scanf("%d%d", &N, &K);

		for(int i=0;i<N-1;i++){
			scanf("%d%d", &x, &y);
			a.push_back(--x);
			b.push_back(--y);
		}
		pLast = 0;
		for(int i=0;i<N;i++){
			con[i] = &(pool[pLast++]);
			con[i]->back = con[i]->next = con[i]->cmp = NULL;
		}
		for(int i=0;i<N-1;i++){
			n1 = add_node(a[i], b[i], 1);
			n2 = add_node(b[i], a[i], 1);
			n1->cmp = n2;
			n2->cmp = n1;
		}

		ret = 0;
		solve(0);

		long long sub = ret;
		K--;
		pLast = 0;
		for(int i=0;i<N;i++){
			con[i] = &(pool[pLast++]);
			con[i]->back = con[i]->next = con[i]->cmp = NULL;
		}
		for(int i=0;i<N-1;i++){
			n1 = add_node(a[i], b[i], 1);
			n2 = add_node(b[i], a[i], 1);
			n1->cmp = n2;
			n2->cmp = n1;
		}

		ret = 0;
		solve(0);

		printf("%d\n", sub - ret);

	return 0;
}