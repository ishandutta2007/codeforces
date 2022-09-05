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
    /*fstream in("input.txt");
    ofstream out("output2.txt");*/
    int a1,c1;
    ll b1;
    vector<int> a,b,c;
    cin >> a1 >> c1;
    while (a1){
        a.PB(a1%3);
        a1/=3;
    }
    while (c1){
        c.PB(c1%3);
        c1/=3;
    }
    int kk = int(a.size())-int(c.size());
    FOR(i,0,kk)
        c.PB(0);
    FOR(i,0,-kk)
        a.PB(0);
    FOR(i,0,a.size())
        b.PB((3+c[i]-a[i])%3);
    b1 = 0;
    for (int i=b.size()-1;i>=0;--i)
        b1=3*b1+ll(b[i]);
    cout << b1;
    //system("pause");
    return 0;
}