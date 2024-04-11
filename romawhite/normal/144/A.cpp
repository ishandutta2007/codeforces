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
    int l,r,n,k,m1,m2;
    cin>>n;
    l=0;r=10000;
    FOR(i,0,n){
        cin>>k;
        if (k>l) {l=k;m1=i;}
        if (k<=r) {r=k;m2=i;}
    }
    int res=m1+(n-1)-m2;
    if (m1>m2) res--;
    cout<<res;
    return 0;
}