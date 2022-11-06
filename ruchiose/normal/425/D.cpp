#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;
 
const int MAXN = 100010;
 
struct point
{
    int x, y, to_check, wkf;
    inline int s() {return x + y;}
    inline int d() {return x - y;}
};
 
bool cmp_pdx(point a, point b) 
{
    return (a.x == b.x) ? (a.y > b.y) : (a.x < b.x);
}
bool cmp_pdy(point a, point b) 
{
    return (a.y == b.y) ? (a.x > b.x) : (a.y < b.y);
}
bool cmp_pdd(point a, point b)
{
    return (a.d() == b.d()) ? (a.s() > b.s()) : (a.d() < b.d());
}
 
int N, i, j;
point P[MAXN];
int Count;
 
const int Field = 2333333;
#define pii pair<int,int>
#define mp make_pair
#define _x first
#define _y second
 
struct unordered_set
{
    pii alloc[Field];
    int Indices[Field], size;
    bool occu[Field];
    void Init()
    {
        size = 0;
    }
    void Release()
    {
        while (size) occu[Indices[size--]] = false;
    }
    int Hash(pii pnt)
    {
        int ret = (pnt.first * 19970530ll + pnt.second) % Field;
        return (ret < 0) ? (ret + Field) : ret;
    }
    int getindex(pii &pnt)
    {
        int h = Hash(pnt);
        while ((occu[h]) && (alloc[h] != pnt))
            h = (h * 233 + 23333) % Field;
        return h;
    }
    void insert(pii pnt)
    {
        int h = getindex(pnt);
        if (occu[h]) return;
        occu[h] = true;
        alloc[h] = pnt;
        Indices[++size] = h;
    }
    bool has_key(pii pnt)
    {
        return occu[getindex(pnt)];
    }
};
 
unordered_set apt;
 
pii queue[MAXN];
 
i64 ANS = 0;
 
int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d%d", &P[i].x, &P[i].y);
    P[0].x = 12345678; P[0].y = 87654321;
    sort(P + 1, P + N + 1, cmp_pdx);
    fortodo(i, 1, N)
        {
            if (P[i].x != P[i - 1].x) Count = 0;
            P[i].to_check = 0; P[i].wkf = Count;
            Count++;
        }
    sort(P + 1, P + N + 1, cmp_pdd);
    fortodo(i, 1, N)
        {
            if (P[i].d() != P[i - 1].d()) Count = 0;
            if (Count < P[i].wkf)
                {
                    P[i].to_check = 1;
                    P[i].wkf = Count;
                }
            Count++;
        }
    sort(P + 1, P + N + 1, cmp_pdy);
    fortodo(i, 1, N)
        {
            if (P[i].y != P[i - 1].y) Count = 0;
            if (Count < P[i].wkf)
                {
                    P[i].to_check =  2;
                    P[i].wkf = Count;
                }
            Count++;
        }
    apt.Init();
    fortodo(i, 1, N) apt.insert(mp(P[i].x, P[i].y));
    ANS = 0;
    sort(P + 1, P + N + 1, cmp_pdx);
    fortodo(i, 1, N)
        {
            if (P[i].x != P[i - 1].x) Count = 0;
            if (P[i].to_check == 0)
                fortodo(j, 1, Count)
                    {
                        int a = queue[j]._y - P[i].y;
                        if ((apt.has_key(mp(P[i].x + a, P[i].y))) && (apt.has_key(mp(P[i].x + a, P[i].y + a))))
                            ANS++;
                    }
            queue[++Count] = mp(P[i].x, P[i].y);
        }
    sort(P + 1, P + N + 1, cmp_pdd);
    fortodo(i, 1, N)
        {
            if (P[i].d() != P[i - 1].d()) Count = 0;
            if (P[i].to_check == 1)
                fortodo(j, 1, Count)
                    {
                        int a = queue[j]._x - P[i].x;
                        if ((apt.has_key(mp(P[i].x + a, P[i].y))) && (apt.has_key(mp(P[i].x, P[i].y + a))))
                            ANS++;
                    }
            queue[++Count] = mp(P[i].x, P[i].y);
        }
    sort(P + 1, P + N + 1, cmp_pdy);
    fortodo(i, 1, N)
        {
            if (P[i].y != P[i - 1].y) Count = 0;
            if (P[i].to_check == 2)
                fortodo(j, 1, Count)
                    {
                        int a = queue[j]._x - P[i].x;
                        if ((apt.has_key(mp(P[i].x, P[i].y + a))) && (apt.has_key(mp(P[i].x + a, P[i].y + a))))
                            ANS++;
                    }
            queue[++Count] = mp(P[i].x, P[i].y);
        }
    printf("%I64d\n", ANS);
}