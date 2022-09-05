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

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const long double pi=3.14159265358979323846264338327950288419716939937510;
const int INF=2000000000;


int main(){
    int n,k,l,x1,x2,y1,y2;
    vector<int> x,y,r;
    cin>>x1>>y1>>x2>>y2;
    cin>>k;
    int a,b,c;
    FOR(i,0,k){
        cin>>a>>b>>c;
        x.PB(a);y.PB(b);r.PB(c);
    }
    int res=0;
    FOR(i,min(y1,y2),max(y1,y2)+1){
        bool q=1;
        FOR(j,0,k)
            if ((x[j]-x1)*(x[j]-x1)+(y[j]-i)*(y[j]-i)<=r[j]*r[j])
                q=0;
        if (q) res++;
    }
    FOR(i,min(y1,y2),max(y1,y2)+1){
        bool q=1;
        FOR(j,0,k)
            if ((x[j]-x2)*(x[j]-x2)+(y[j]-i)*(y[j]-i)<=r[j]*r[j])
                q=0;
        if (q) res++;
    }
    FOR(i,min(x1,x2)+1,max(x1,x2)){
        bool q=1;
        FOR(j,0,k)
            if ((x[j]-i)*(x[j]-i)+(y[j]-y1)*(y[j]-y1)<=r[j]*r[j])
                q=0;
        if (q) res++;
    }
    FOR(i,min(x1,x2)+1,max(x1,x2)){
        bool q=1;
        FOR(j,0,k)
            if ((x[j]-i)*(x[j]-i)+(y[j]-y2)*(y[j]-y2)<=r[j]*r[j])
                q=0;
        if (q) res++;
    }
    cout<<res;
    return 0;
}