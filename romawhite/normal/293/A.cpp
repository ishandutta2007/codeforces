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
#include <time.h>
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

char a[2000007];
char b[2000007];

int main()
{
    rrr();
    int n;
    cin >> n;
    scanf("%s%s" , a , b);

    int c1 = 0 , c2 = 0 , c3 = 0;
    FOR(i,0,2 * n){
        if (a[i] == '1' && b[i] == '1')
            ++c1;
        if (a[i] == '1' && b[i] == '0')
            ++c2;
        if (a[i] == '0' && b[i] == '1')
            ++c3;
    }


    int A = (c1 + 1) / 2;
    int B = c1 / 2 ;

    if (c1 & 1){
        if (c3){
            ++B;
            --c3;
        }
        else{
            if (c2){
                --c2;
            }
        }

    }

    if (c2 > c3){
        A += (c2 - c3 + 1) / 2;
    }
    else B += (c3 - c2) / 2;



    if (A > B) cout << "First" << endl;
    if (A < B) cout << "Second" << endl;
    if (A ==  B) cout << "Draw" << endl;

    return 0;
};