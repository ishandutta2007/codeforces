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
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;

string s[55];

map<string , int> M;
int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int n;
    cin >> n;

    FOR(i,0,n)
        cin >> s[i];
    FOR(i,0,n){
        FOR(j,0,s[i].size()){
            string temp = "";
            temp += s[i][j];
            M[temp] = 1;
            if (j < s[i].size() - 1)
                temp += s[i][j + 1];
            M[temp] = 1;
        }
    }
    
    FOR(i,0,26){
        string t = "";
        t += 'a' + i;
        if (M[t] == 0){
            cout << t << endl;
            return 0;
        }
    }

    FOR(i,0,26)
        FOR(j,0,26){
            string t = "";
            t += 'a' + i;
            t += 'a' + j;
            if (M[t] == 0){
                cout << t << endl;
                return 0;
            }
    }

    return 0;
}