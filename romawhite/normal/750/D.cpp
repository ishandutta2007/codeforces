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
#include <assert.h>
#include <time.h>


#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;


bool A[300][300];

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
    
int main()
{
    //freopen("in.txt" , "r" , stdin);
    
    vector<pair<PII, int> > B;
    B.push_back(MP(MP(150,150) , 0));
    
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        int t;
        cin >> t;
        vector<pair<PII, int> > C;
        FOR(j,0,SZ(B))
        {
            int x = B[j].first.first;
            int y = B[j].first.second;
            FOR(tt,0,t)
            {
                x += dx[B[j].second];
                y += dy[B[j].second];
                A[x][y] = 1;
            }
            C.push_back(MP(MP(x , y) , (B[j].second + 1) % 8));
            C.push_back(MP(MP(x , y) , (B[j].second + 7) % 8));
        }
        sort(ALL(C));
        C.resize(unique(ALL(C)) - C.begin());
        B = C;
    }
    
    int res = 0;
    FOR(i,0,300)
        FOR(j,0,300)
            res += A[i][j];
    
    cout << res << endl;
    
    return 0;
}