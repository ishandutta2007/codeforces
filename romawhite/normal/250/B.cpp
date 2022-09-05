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
#include <sstream>
#include <fstream>

 
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
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod = 1000000007;



int main() {
    int q;
    cin >> q;
    FOR(qq,0,q){
    string s;
    cin >> s;
    vector<string> S;
    string tmp = "";
    FOR(i,0,s.size()){
        if (s[i] == ':'){
            S.PB(tmp);
            tmp = "";
        }
        else tmp += s[i];
    }
    if (tmp.size())
        S.PB(tmp);
    string res = "";
    int id = -1;
    FOR(i,0,S.size())
        if (S[i].size() == 0) id = i;
    FOR(i,0,S.size()){
        string t = "";
        FOR(j,0,4 - S[i].size())
            t += '0';
        t += S[i];
        S[i] = t;
    }

    FOR(i,0,S.size()){
        if (i == id){
            FOR(j,0,8 - S.size() + 1)
                res += S[i] + ':';
        }
        else res += S[i] + ':';
    }

    FOR(i,0,res.size() - 1)
        cout << res[i];
    cout << endl;
    }
    return 0;
}