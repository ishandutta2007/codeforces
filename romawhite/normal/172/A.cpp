#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

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
    int n;
    cin >> n;
    vector<string> s(n);
    FOR(i,0,n)
        cin >> s[i];
    int l = s[0].size();
    FOR(i,0,l){
        bool q = 1;
        FOR(j,0,s.size())
            if (s[j][i]!=s[0][i])
                q = 0;
        if (q==0) {
            cout << i;
            return 0;
        }
    }
    return 0;
}