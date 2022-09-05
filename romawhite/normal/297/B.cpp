//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#define _CRT_SECURE_NO_DEPRECATE
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (2000000000)
#define FILL                    CLEAR

void rrr(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
}

int main()
{
    rrr();
    
    set<int> s;
    map<int,int> M1 , M2;
    int n,m , k;
    cin >> n >> m >> k;
    FOR(i,0,n){
        int a;
        scanf("%d" , &a);
        M1[a]++;
        s.insert(a);
    }
    FOR(i,0,m){
        int a;
        scanf("%d" , &a);
        M2[a]++;
        s.insert(a);
    }

    vector<int> A , B;

    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
        A.PB(M1[*it]) , B.PB(M2[*it]);

    int k1 = 0, k2 = 0;
    RFOR(i , A.size() , 0){
        k1 += A[i];
        k2 += B[i];
        if (k1 > k2){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
};