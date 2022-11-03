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


//Must be power of two!
//const int SIZE = 8;
const int SIZE = 1<<19;
const int INF = 0x3f3f3f3f;

struct State {
	int ind;
	int l, r;
	inline State() {}
	inline State(int _i, int _l, int _r) : ind(_i), l(_l), r(_r) {}
};
State StartState() { return State(0, 0, SIZE); }

struct Transform {
	int a;		//	x' = x+a;
};
struct Value {
    int val;
    int ind;
};

struct Node {
	Transform t;		//transform to be applied to subtree
	Value m;			//m - maximal value in subtree (after transform)
};

Node arr[2*SIZE];

int doleft;
int doright;
Transform dot;

inline Value Apply(Value x, const Transform &t) {
    Value res;
    res.val = x.val + t.a;
    res.ind = x.ind;
	return res;
}

Transform Multiply(const Transform &t1, const Transform &t2) {
	Transform res;
    res.a = t1.a + t2.a;
	return res;
}

void MoveDown(Node &v, Node &s1, Node &s2) {
	s1.m = Apply(s1.m, v.t);
	s1.t = Multiply(s1.t, v.t);
	s2.m = Apply(s2.m, v.t);
	s2.t = Multiply(s2.t, v.t);
	v.t.a = 0;
}

Value max(Value a, Value b) {
    if (a.val > b.val)
        return a;
    if (b.val > a.val)
        return b;
    return a.ind < b.ind ? a : b;
}

Value DoSegment(State s) {
	if (doright <= s.l || s.r <= doleft) {
        Value qq;
        qq.val = -INF;
        qq.ind = -1;
        return qq;
    }
	if (doleft <= s.l && s.r <= doright) {
		arr[s.ind].m = Apply(arr[s.ind].m, dot);
		arr[s.ind].t = Multiply(arr[s.ind].t, dot);
		return arr[s.ind].m;
	}
	MoveDown(arr[s.ind], arr[2*s.ind+1], arr[2*s.ind+2]);
	int mid = (s.l + s.r) >> 1;
	Value resl = DoSegment(State(2*s.ind+1, s.l, mid));
	Value resr = DoSegment(State(2*s.ind+2, mid, s.r));
	arr[s.ind].m = Apply(max(arr[2*s.ind+1].m, arr[2*s.ind+2].m), arr[s.ind].t);
	return Apply(max(resl, resr), arr[s.ind].t);
}

#define SETUP_SEG_OP(va) \
	doleft = l;\
	doright = r;\
	dot.a = (va);\

void rmqsegmentadd(int l, int r, int64 v) {
	SETUP_SEG_OP(v);
	DoSegment(StartState());
}

Value rmqsegmentmax(int l, int r) {
	SETUP_SEG_OP(0);
	return DoSegment(StartState());
}

//====================================================================

struct Item {
    int left, ctr, right;
};

struct Event {
    int pos;
    int type;   //1-L, 2-C
    int ind;

    inline bool operator<(const Event &e) const {
        if (pos != e.pos) return pos < e.pos;
        if (type != e.type) return type < e.type;
        return ind < e.ind;
    }
};

int n;
vector<Item> items;
vector<Event> evs;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i<SIZE; i++)
        arr[SIZE-1+i].m.ind = i;
    for (int i = SIZE-2; i>=0; i--)
        arr[i].m = max(arr[2*i+1].m, arr[2*i+2].m);

    scanf("%d", &n);
    items.resize(n);
    for (int i = 0; i<n; i++) {
        scanf("%d%d%d", &items[i].left, &items[i].ctr, &items[i].right);
        Event e;
        e.ind = i;

        e.pos = items[i].left;
        e.type = 1;
        evs.push_back(e);
        e.pos = items[i].ctr;
        e.type = 2;
        evs.push_back(e);
    }
    sort(evs.begin(), evs.end());

    int ans = -1;
    int bleft = -1, bright = -1;
    for (int i = 0; i<evs.size(); i++) {
        auto e = evs[i];
        int x = e.ind;
        if (e.type == 1) {
            rmqsegmentadd(items[x].ctr, items[x].right+1, 1);
        }
        else {
            auto mxv = rmqsegmentmax(e.pos, 310000);
            if (mxv.val > ans) {
                ans = mxv.val;
                bleft = e.pos;
                bright = mxv.ind;
            }

            rmqsegmentadd(items[x].ctr, items[x].right+1, -1);
        }
    }

    vector<int> got;
    for (int i = 0; i<n; i++)
        if (items[i].ctr >= bleft && items[i].ctr <= bright)
            if (items[i].left <= bleft && items[i].right >= bright)
                got.push_back(i);

    printf("%d\n", got.size());
    for (int i = 0; i<got.size(); i++) printf("%d ", got[i]+1);

	return 0;
}