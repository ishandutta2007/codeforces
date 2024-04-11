//#pragma comment(linker,"/STACK:16777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;

int main() {
    string ss1,s2;
    cin >> ss1 >> s2;
    string s1="";
    FOR(i,0,2100)
        s1+='#';
    s1+=ss1;
    FOR(i,0,2100)
        s1+='#';
    int res = 0;
    FOR(i,0,s1.size()-s2.size()+1){
        int k = 0;
        FOR(j,0,s2.size())
            if (s1[i+j] == s2[j]) ++k;
        res = max(res,k);
    }
    cout << s2.size()-res;
    return 0;
}