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
    int n,k;
    int a[310][310];
    int g[310];
    cin>>n;
    FOR(i,1,n+1)
        FOR(j,1,n+1)
            cin>>a[i][j];
    FOR(i,1,n+1)
    {
        cin>>k;
        g[k]=i;
    }
    FOR(i,1,n+1)
    {
        FOR(j,1,n+1)
            if (a[i][j]!=i)
            {
                bool q=1;
                FOR(t,1,a[i][j])
                    if (t!=i && g[a[i][j]]>g[t]) q=0;
                if (q) {cout<<a[i][j]<<' ';break;}
            }
    }
    //system("pause");
    return 0;
}