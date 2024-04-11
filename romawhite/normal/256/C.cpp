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
#include <time.h>
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
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const int INF=1000000000;
const LL mod= 1000000007;

LL sqrt4(LL a){
    LL b = sqrt(sqrt(1.0 * a));
    while (b * b * b * b < a) ++b;
    return b;
}

LL sqrt2(LL a){
    LL b = sqrt(1.0 * a);
    while ((b + 1) * (b + 1) <= a) ++b;
    while (b * b > a) --b;
    return b;
}

/*4 1
16 2
82 0
6724 3
50626 1*/

int l[7] = {1, 4 , 16 , 82 , 6724, 50626 , 900000};

bool us[5];

int main(){
    int n;
    cin >> n;
    int Xor = 0;
    FOR(i,0,n){
        CLEAR(us);
        LL a;
        cin >> a;
        if (a < 4) continue;
        LL L = sqrt4(a);
        LL R = sqrt2(a);
        if (L < l[1] && R >= l[0]) us[0] = 1;
        if (L < l[2] && R >= l[1]) us[1] = 1;
        if (L < l[3] && R >= l[2]) us[2] = 1;
        if (L < l[4] && R >= l[3]) us[0] = 1;
        if (L < l[5] && R >= l[4]) us[3] = 1;
        if (L < l[6] && R >= l[5]) us[1] = 1;
        int j = 0;
        while (us[j]) ++j;
        Xor ^= j;
    }

    if (Xor) cout << "Furlo\n";
    else cout << "Rublo\n";

    return 0;
}