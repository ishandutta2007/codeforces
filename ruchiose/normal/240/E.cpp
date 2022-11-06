// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

struct Info
{
    int sig;
    int cost, used;
    Info *compn[2];
    Info() {}
    Info(int cost)
    {
        sig = 0; compn[0] = compn[1] = NULL;
        this->cost = cost; used = 0;
    }
    Info(bool isBothPosi, Info* compn0, Info* compn1)
    {
        sig = (isBothPosi) ? 1 : -1;
        compn[0] = compn0;
        compn[1] = compn1;
        cost = compn[0]->cost + sig * compn[1]->cost;
        used = 0;
    }
    void pick()
    {
        used++;
    }
    void inhr()
    {
        if (sig)
            {
                compn[0]->used += used;
                compn[1]->used += sig * used;
                used = 0;
            }
    }
};

Info emptyInfo(0);

vector<Info*> derived;

Info* Add(Info* a, Info* b)
{
    if (a == &emptyInfo) return b;
    if (b == &emptyInfo) return a;
    Info* nxt = new Info(true, a, b);
    derived.push_back(nxt);
    return nxt;
}

Info* Sub(Info* a, Info* b)
{
    if (b == &emptyInfo) return a;
    Info* nxt = new Info(false, a, b);
    derived.push_back(nxt);
    return nxt;
}

struct Leftist
{
    Leftist* s[2];
    pair<Info*,int> val;
    Info *Mask;
    int Dist;
    Leftist(pair<Info*,int> nval = std::pair<Info*,int>(&emptyInfo, 0))
    {
        s[0] = s[1] = NULL;
        Dist = 1;
        val = nval; Mask = &emptyInfo;
    }
    int Key()
    {
        return val.first->cost;
    }
};

int dist(Leftist* cur)
{
    return (cur) ? cur->Dist : 0;
}

void Push(Leftist* cur)
{
    if (cur->s[0]) cur->s[0]->Mask = Add(cur->s[0]->Mask, cur->Mask);
    if (cur->s[1]) cur->s[1]->Mask = Add(cur->s[1]->Mask, cur->Mask);
    cur->val.first = Sub(cur->val.first, cur->Mask);
    cur->Mask = &emptyInfo;
}

Leftist* Merge(Leftist* l, Leftist* r)
{
    if (l == NULL) return r;
    if (r == NULL) return l;
    Push(l); Push(r);
    if (l->Key() > r->Key())
        swap(l, r);
    l->s[1] = Merge(l->s[1], r);
    if (dist(l->s[0]) < dist(l->s[1]))
        swap(l->s[0], l->s[1]);
    l->Dist = dist(l->s[1]) + 1;
    return l;
}

pair<Info*,int> Extract(Leftist* &cur)
{
    Push(cur);
    pair<Info*,int> ret = cur->val;
    cur = Merge(cur->s[0], cur->s[1]);
    return ret;
}

const int MAXN = 100010;
const int MAXM = 100010;

int N, M;
Leftist* heap[MAXN];

struct UFS
{
    int F[MAXN];
    void Init()
    {
        int i;
        fortodo(i, 1, N) F[i] = i;
    }
    int Find(int x)
    {
        return (F[x] == x) ? x : Find(F[x]);
    }
    void Union(int x, int y)
    {
        F[Find(y)] = Find(x);
    }
    bool Cnx(int x, int y)
    {
        return Find(x) == Find(y);
    }
};

UFS weak, strong;
set<int> activeStrong;

void Join(int u, int v) // u & v are Strong C. , u is Root Strong C. of its Weak C.
{
    strong.Union(u, v);
    heap[u] = Merge(heap[u], heap[v]);
    heap[v] = NULL;
    activeStrong.insert(u);
}

Info baseInfo[MAXM], *prevCost[MAXN];
int prev[MAXN], Ans;

bool Connected()
{
    int i;
    fortodo(i, 1, N)
        if (!weak.Cnx(1, i))
            return false;
    return true;
}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt","w",stdout);
    int i;
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) heap[i] = NULL;
    fortodo(i, 1, M)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            baseInfo[i] = Info(w);
            if (v == 1) continue;
            heap[v] = Merge(heap[v], new Leftist(make_pair(&baseInfo[i], u)));
        }
    activeStrong.clear();
    fortodo(i, 2, N)
        activeStrong.insert(i);
    weak.Init();
    strong.Init();
    Ans = 0;
    while (activeStrong.size())
        {
            int s0 = *activeStrong.begin();
            if (heap[s0] == NULL)
                {
                    activeStrong.erase(s0);
                    continue;
                }
            pair<Info*,int> pdi = Extract(heap[s0]);
            int S = strong.Find(pdi.second);
            if (S == s0) continue; // Discard
            if (!weak.Cnx(pdi.second, s0))
                {
                    // Simply Connect It
                    prev[s0] = pdi.second;
                    prevCost[s0] = pdi.first;
                    Ans += pdi.first->cost;
                    pdi.first->pick();
                    weak.Union(pdi.second, s0);
                    // s0 is no longer a root strong C. of its weak C.
                    activeStrong.erase(s0);
                    continue;
                }
            vector<int> LIZ;
            LIZ.clear();
            LIZ.push_back(strong.Find(pdi.second));
            while (LIZ.back() != s0)
                LIZ.push_back(strong.Find(prev[LIZ.back()]));
            Ans += pdi.first->cost;
            pdi.first->pick();
            if (heap[s0]) heap[s0]->Mask = Add(heap[s0]->Mask, pdi.first);
            int SZ = LIZ.size();
            fortodo(i, 0, SZ - 2)
                if (heap[LIZ[i]])
                    heap[LIZ[i]]->Mask = Add(heap[LIZ[i]]->Mask, prevCost[LIZ[i]]);
            fortodo(i, 0, SZ - 2)
                Join(s0, LIZ[i]);
        }
    if (!Connected())
        {
            printf("-1\n");
            return 0;
        }
    printf("%d\n", Ans);
    vector<int> VI;
    VI.clear();
    for (vector<Info*>::reverse_iterator rit = derived.rbegin(); rit != derived.rend(); rit++)
        (*rit)->inhr();
    fortodo(i, 1, M)
        if ((baseInfo[i].used) && (baseInfo[i].cost))
            VI.push_back(i);
    fortodo(i, 0, Ans - 1)
        printf("%d%s", VI[i], (i == Ans - 1) ? "\n" : " ");
    if (Ans == 0) printf("\n");
}