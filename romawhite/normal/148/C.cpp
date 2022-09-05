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
typedef long double ld;

const double pi=3.141592653589793;
const int INF=2000000000;

int m=0;


int main(){
    int a,b,n;
    cin >> n >> a >> b;
    if (a==0 && b==0){
        FOR(i,0,n)
            cout << 500-i << ' ';
        return 0;
    }
    
    if (b!=0){
    FOR(i,0,b)
        cout << (1<<i) << ' ';
    cout << 49999-2*a << ' ';
    FOR(j,0,a)
        cout << 49999-2*a+j+1 << ' ';
    FOR(i,0,n-a-b-1)
        cout << 49999-2*a-i-5 << ' ';
    return 0;
    }
    if (b==0 && a==n-1) {cout <<"-1";return 0;}
    cout<<"40000 39999 ";
    FOR(i,0,a)
        cout << 49999-2*a+i << ' ';
    FOR(i,0,n-a-2)
        cout << 49999-2*a-i-5 << ' ';
    return 0;
}