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
    int n;
    cin>>n;
    vector<int> a(n);
    FOR(i,0,n)
        cin>>a[i];
    sort(a.begin(),a.end());
    int res=0;
    int st=0;
    int t=0;
    FOR(i,0,n)
    {
        t+=a[i];
        if (t>710) break;
        res++;
        if (t>350) st+=t-350;
    }
    cout<<res<<' '<<st;
    //system("pause");
    return 0;
}