//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include <time.h>
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
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

const int MOD = 1000000007;



bool f(int X, int Y,int a,int b){
    if (1ll * a * X >= 0 && 1ll * b * Y >= 0 && ((X == 0 && a == 0) || (X && a % X == 0)) && ((Y == 0 && b == 0) || (Y && b % Y == 0)) && (X==0 || Y==0 || a/X == b/Y)){
        return 1;
    }
    else return 0;
}

int main()
{
    //freopen("fraction.in" , "r" , stdin);freopen("fraction.out" , "w" , stdout);
    int a , b;
    cin >> a >> b;
    string s;
    cin >> s;
    int X = 0;
    int Y = 0;
    FOR(i,0,s.size()){
        if (s[i] == 'L')
            --X;
        if (s[i] == 'R')
            ++X;
        if (s[i] == 'U')
            ++Y;
        if (s[i] == 'D')
            --Y;
    }

    int x = 0;
    int y = 0;
    if (f(X,Y,a,b)){
        cout << "Yes\n";
        return 0;
    }
    FOR(i,0,s.size()){
        if (s[i] == 'L')
            --x;
        if (s[i] == 'R')
            ++x;
        if (s[i] == 'U')
            ++y;
        if (s[i] == 'D')
            --y;
        if (f(X,Y,a-x,b-y)){
            cout << "Yes\n";
            return 0;
        }
    }
    
    cout << "No\n";
    return 0;
};