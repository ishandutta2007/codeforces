#pragma comment(linker, "/STACK:32000000")
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(LL(i)=(a);i<b;i++)
#define RFOR(i,a,b) for(int(i)=(a-1);i>=b;i--)
#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define next htrhtrhtrh
#define ALL(A) A.begin(),A.end()
#define SZ(A) A.size()
#define FILL(a,b) memset(a,b,sizeof(a))
#define CLEAR(a) memset(a,0,sizeof(a))

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 200000;
const int INF = 100000000;
const int MOD = 1000000007;
const double EPS = 1E-7;
const int IT = 10024;

bool used[100007];
map<int,int> M;

int main()
{
    //freopen("in.txt","r",stdin);
    int n,k;
    cin >> n >> k;
    if (k == 1){
        cout << n << endl;
        return 0;
    }
    vector<int> a(n);
    FOR(i,0,n)
        scanf("%d" , &a[i]);
    sort(ALL(a));
    reverse(ALL(a));
    FOR(i,0,a.size())
        M[a[i]] = i;
    int res = 0;
    FOR(i,0,n)
        if (!used[i]){
            int t = a[i];
            int l = 1;
            while (t % k == 0 && M.count(t / k)){
                t /= k;
                ++l;
                used[M[t]] = 1;
            }
            res += l / 2 + l % 2;

    }
    
        cout << res << endl;

}