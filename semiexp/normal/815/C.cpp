#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, B;
int C[5050], D[5050], R[5050]; // base price, price after using coupon, parent
vector<int> ch[5050];

vector<int>* join(vector<int>* a, vector<int>* b)
{
	vector<int> *ret = new vector<int>(a->size() + b->size() - 1, B + 1);

	for (int i = 0; i < a->size(); ++i) {
		for (int j = 0; j < b->size(); ++j) {
			(*ret)[i + j] = min((*ret)[i + j], (*a)[i] + (*b)[j]);
		}
	}

	return ret;
}
vector<int>* join(vector<int>* a, vector<int>* b, vector<int> *bd)
{
	vector<int> *ret = new vector<int>(a->size() + b->size() - 1, B + 1);

	for (int i = 0; i < a->size(); ++i) {
		for (int j = 0; j < b->size(); ++j) {
			(*ret)[i + j] = min((*ret)[i + j], (*a)[i] + min((*b)[j], (*bd)[j]));
		}
	}

	return ret;
}
void show(vector<int>* v)
{
	for (int i = 0; i < v->size(); ++i) printf("%d ", (*v)[i]);
	puts("");
}

// { no coupon, coupon allowed }
pair<vector<int>*, vector<int>*> solve(int p)
{
	vector<int> *nc = new vector<int>, *ca = new vector<int>;
	nc->push_back(0);
	ca->push_back(D[p]);
	nc->push_back(C[p]);
	ca->push_back(D[p]);

	for (int q : ch[p]) {
		auto tmp = solve(q);
		nc = join(nc, tmp.first);
		ca = join(ca, tmp.first, tmp.second);

		delete tmp.first;
		delete tmp.second;
	}

//	printf("%d: \n", p);
//	show(nc);
//	show(ca);

	return{ nc, ca };
}

int main()
{
	scanf("%d%d", &N, &B);
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			scanf("%d%d", C + i, D + i);
			R[i] = -1;
		} else {
			scanf("%d%d%d", C + i, D + i, R + i);
			--R[i];
			ch[R[i]].push_back(i);
		}
		D[i] = C[i] - D[i];
	}

	auto hoge = solve(0);
	int ret = 0;
	for (int i = 0; i < hoge.first->size(); ++i) {
		if ((*hoge.first)[i] <= B) ret = i;
		if ((*hoge.second)[i] <= B) ret = i;
	}
	printf("%d\n", ret);

	return 0;
}