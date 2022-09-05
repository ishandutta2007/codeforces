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
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979


typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int BASE = 1000;
const double EPS = 1e-7;
const int MAX = 17;
const int INF = 1000000000;


bool inside(int mx1, int Mx1 , int my1, int My1, int x , int y)
{
    return x >= mx1 && x <= Mx1 && y >= my1 && y <= My1;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n , m;
    cin >> n >> m;
    vector<PII> A , B;
    set<int> res;
    
    FOR(i,0, n)
    {
        int x , y;
        cin >> x >> y;
        if (x > y) swap(x , y);
        A.push_back(MP(x , y));
    }
    
    FOR(i,0, m)
    {
        int x , y;
        cin >> x >> y;
        if (x > y) swap(x , y);
        B.push_back(MP(x , y));
    }
    bool OK = true;
    
    FOR(i,0,SZ(A))
    {
        
        set<int> C;
        
        FOR(j,0,SZ(B))
        {
            if (A[i] == B[j]) continue;
            int x = -1;
            if (A[i].first == B[j].first || A[i].first == B[j].second)
                x = A[i].first;
            if (A[i].second == B[j].first || A[i].second == B[j].second)
                x = A[i].second;
            
            if (x == -1) continue;
            
            res.insert(x);
            C.insert(x);
            
        }
        
        if (SZ(C) == 2)
        {
            OK = false;
        }
        
    }
    
    
    FOR(j,0,SZ(B))
    {
        
        set<int> C;
        
        FOR(i,0,SZ(A))
        {
            if (A[i] == B[j]) continue;
            int x = -1;
            if (A[i].first == B[j].first || A[i].first == B[j].second)
                x = A[i].first;
            if (A[i].second == B[j].first || A[i].second == B[j].second)
                x = A[i].second;
            
            if (x == -1) continue;
            res.insert(x);
            C.insert(x);
            
        }
        
        if (SZ(C) == 2)
        {
            OK = false;
        }
        
    }
    
    
    if (SZ(res) == 1)
    {
        cout << *res.begin() << endl;
        return 0;
    }
    
    if (OK)
    {
        cout << 0 << endl;
        return 0;
    }
    
    cout << -1 << endl;
    
    
    
    
    return 0;
}