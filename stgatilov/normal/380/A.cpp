//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 1<<20;

struct Oper {
    int type;
    int elem;
    int first, cnt;
};

struct Query {
    int64 idx;
    int name;
    inline bool operator< (const Query &q) const {
        if (idx != q.idx) return idx < q.idx;
        return name < q.name;
    }
};

int n, m;
vector<Oper> arr;
vector<Query> qarr;

int64 len;
int str[SIZE];
int pos;

int ans[1<<20];
void Answer(int elem) {
    ans[qarr[pos].name] = elem;
    pos++;
}

void Add(int elem) {
    while (qarr[pos].idx == len)
        Answer(elem);

    if (len < SIZE)
        str[len] = elem;
    len++;
}

void AddCopy(int first, int cnt) {
    while (1) {
        int64 per = (qarr[pos].idx - len) / first;
        if (per >= cnt) break;
        int rem = (qarr[pos].idx - len) % first;
        Answer(str[rem]);
    }
    int64 oldlen = len;
    for (int i = 0; len < SIZE && i<cnt; i++)
        for (int j = 0; len < SIZE && j<first; j++)
            str[len++] = str[j];
    len = oldlen + int64(first) * cnt;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        Oper op;
        scanf("%d", &op.type);
        if (op.type == 1)
            scanf("%d", &op.elem);
        else
            scanf("%d%d", &op.first, &op.cnt);
        arr.push_back(op);
    }
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        Query q;
        q.name = i;
        scanf("%I64d", &q.idx);
        q.idx--;
        qarr.push_back(q);
    }
    Query q;
    q.name = -1;
    q.idx = 1000000000000000000LL;
    qarr.push_back(q);

    sort(qarr.begin(), qarr.end());

    memset(str, -1, sizeof(str));
    len = pos = 0;

    for (int i = 0; i<arr.size(); i++) {
        Oper op = arr[i];
        if (op.type == 1)
            Add(op.elem);
        else
            AddCopy(op.first, op.cnt);
    }

    for (int i = 0; i<n; i++)
        printf("%d ", ans[i]);

	return 0;
}