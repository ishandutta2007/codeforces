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
    string s;
    cin >> s;
    if (s[0] == 'f'){
        FOR(i,0,3){
            cout << s[0];
            s.erase(s.begin());
        }
    }
    else{
        FOR(i,0,4){
            cout << s[0];
            s.erase(s.begin());
        }
    }

    cout << "://";

    FOR(i,1,s.size())
        if (s[i] == 'r' && s[i + 1] == 'u'){
            FOR(j,0,i)
                cout << s[j];
            cout << '.';
            cout << "ru";
            if (i + 2 != s.size()){
                cout << '/';
                FOR(j,i + 2,s.size())
                    cout << s[j];
            }
        cout << endl;
        return 0;
    }

    return 0;
}