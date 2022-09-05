#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000;
const LL LINF = INF * (LL) INF;


const int MAX = 500007;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int MOD = 998244353;

map<int,int> M;
VI A[MAX];
int V[MAX];
int ID[MAX];

int get_mappping(int x)
{
    if (M.count(x)) return M[x];
    int sz = SZ(M);
    M[x] = sz;
    return sz;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    //    ios::sync_with_stdio(false); cin.tie(0);
    
    int q;
    cin >> q;
    
    FOR(i,0,MAX)
    {
        A[i].push_back(i);
        ID[i] = i;
    }
    
    int last = 0;
    
    FOR(qq,0,q)
    {
        int t;
        scanf("%d", &t);
        
        if (t == 1)
        {
            int l , r, x;
            scanf("%d%d%d" , &l, &r, &x);
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) swap(l, r);
            
            ++ r;
            
            l = get_mappping(l);
            r = get_mappping(r);
            
            if (ID[l] == ID[r])
            {
                continue;
            }
            
            int idl = ID[l];
            int idr = ID[r];
            
            if (SZ(A[idl]) < SZ(A[idr]))
            {
                swap(idl, idr);
                swap(l, r);
            }
            
            int xv = (V[l] ^ V[r] ^ x);
            
            
            FOR(i,0, SZ(A[idr]))
            {
                int x = A[idr][i];
                
                A[idl].push_back(x);
                ID[x] = idl;
                V[x] ^= xv;
                
            }
            
            
            {
                VI temp;
                temp.swap(A[idr]);
            }
        
            

        }
        else
        {
            int l , r;
            scanf("%d%d" , &l, &r);
            l ^= last;
            r ^= last;
            if (l > r) swap(l, r);
            ++ r;
            
            l = get_mappping(l);
            r = get_mappping(r);
            
            
            if (ID[l] == ID[r])
            {
                int res = (V[l] ^ V[r]);
                last = res;
                printf("%d\n" , res);
            }
            else
            {
                last = 1;
                printf("-1\n");
            }
            
        }
        
    }
    
    
    
    
    
    
    return 0;
}