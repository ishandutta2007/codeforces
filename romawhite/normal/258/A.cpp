#pragma comment(linker, "/STACK:32777216")
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

#define y1 rsfds
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
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod=1000000007;

int main(){
    string s;
    cin >> s;
    int j = s.size()-1;
    FOR(i,0,s.size())
                     if (s[i] == '0'){
                        j = i;
                        break;         
                     }
    FOR(i,0,s.size())
                     if (j != i)
                     cout << s[i];
    cout << endl;
    cin.get();cin.get();
    return 0;
}