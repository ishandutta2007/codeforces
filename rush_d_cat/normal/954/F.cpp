#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
const int Mod = 1000000007;
struct Matrix
{
    int a[3][3];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
} M[8];

void init() {
    for (int mask = 0; mask < 8; mask ++) 
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++) {
                if (((mask >> j) & 1) && abs(i - j) <= 1)
                    M[mask].a[j][i] = 1;
            }

}

struct Item {
    ll x, a, t;
    Item(){}
    Item(ll x_, ll a_, ll t_) {x = x_, a = a_, t = t_;}
} items[N]; int id = 0;

bool cmp(Item A, Item B) {
    return A.x < B.x;
}

int n; ll m;
int main() {
    init();
    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; i ++) {
        ll a, l, r;
        scanf("%lld %lld %lld", &a, &l, &r);
        items[++ id] = Item(l-1, a - 1, 1);
        items[++ id] = Item(r, a - 1, -1);
    }
    items[++ id] = Item(m, 0, 0);
    sort(items + 1, items + 1 + id, cmp);

    Matrix A; A.init();
    ll cnt[3] = {0, 0, 0};
    ll last = 1;
    for (int i = 1; i <= id; i ++) 
    {
        if (items[i].x > last) 
        {
            //printf("%d %d\n", last, items[i].x);
        
            int mask = 0;
            for (int j = 0; j < 3; j ++)
                if (cnt[j] == 0) mask |= (1 << j);
            
            A = (M[mask] ^ (items[i].x - last)) * A;

            //printf("mask = %d\n", mask);
            //printf("mat\n");
            //for (int _ = 0; _ < 3; _ ++) { 
            //    for (int __ = 0; __ < 3; __ ++)
            //        printf("%d ", M[mask].a[_][__]);
            //    printf("\n");
            //}
            //printf("\n");
            last = items[i].x;
        }
        cnt[items[i].a] += items[i].t;
        last = items[i].x;
    }
    printf("%d\n", A.a[1][1]);
}