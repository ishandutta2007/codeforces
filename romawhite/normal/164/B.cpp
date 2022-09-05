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
const int N = 10000005;
int c[1000005];
ll d[2000005];
int main() {
    memset(c,-1,sizeof(c));
    memset(d,-1,sizeof(d));
    int l1,l2;
    cin >> l1 >> l2;
    vector<int> a(2*l1);
    vector<int> b(l2);
    FOR(i,0,l1){
        scanf("%d",&a[i]);
        c[a[i]] = i;
    }
    FOR(i,0,l2){
        scanf("%d",&b[i]);
        if (c[b[i]]!=-1){
            d[c[b[i]]]=i;
            d[c[b[i]]+l1]=i;
        }
    }
    FOR(i,0,l1)
        a[l1+i] = a[i];

    FOR(i,1,2*l1)
        if(d[i]!=-1 && d[i]<d[i-1])
            d[i] += ((d[i-1]-d[i])/l2 + 1) * ll(l2);

    int res  = 1;
    int l = 0, r = 0;
    while (l<2*l1 && d[l] == -1) {l++; r++;}
    if (l == 2*l1) { cout << 0; return 0;}
    FOR(i,r+1,2*l1){
        if (d[i] == -1){
            l = i+1;
        }else{
            while (d[i]-d[l]>l2) l++;
            res = max(res,i-l+1);
        }
        //cout << l << ' ' << i << endl;
    }

    if (res>l1) res = l1;
    cout << res;
    return 0;
}