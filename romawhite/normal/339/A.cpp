//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
 
typedef long double LD;
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
 
const double pi=3.141592653589793;
const int INF=1000000000;
const int MOD=1000000007;


int main(){
    vector<int> a;
    string s;
    cin >> s;
    FOR(i,0,s.size())
                     if (s[i] != '+')
                        a.PB(s[i] - '0');
    sort(ALL(a));
    cout << a[0];
    FOR(i,1,a.size())
    cout << '+' << a[i];
    
    
   //system("pause");
   return 0;
}