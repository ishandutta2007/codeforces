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
    vector <int> x(n);
    vector<int> y(n);
    FOR(i,0,n)
        cin >> x[i] >> y[i];
    bool q[230][4];
    memset(q,0,sizeof(q));
    FOR(i,0,n-1)
        FOR(j,i+1,n){
            if (y[i] == y[j] && x[i]>x[j]){
                q[i][0]=1;
                q[j][1]=1;
            }
            if (y[i] == y[j] && x[i]<x[j]){
                q[i][1]=1;
                q[j][0]=1;
            }
            if (y[i] > y[j] && x[i]==x[j]){
                q[i][2]=1;
                q[j][3]=1;
            }
            if (y[i] < y[j] && x[i]==x[j]){
                q[i][3]=1;
                q[j][2]=1;
            }

    }
    int res=0;
    FOR(i,0,n){
        if (q[i][0] && q[i][1] && q[i][2] && q[i][3])
            res++;
    }
    cout << res << endl;
    return 0;
}