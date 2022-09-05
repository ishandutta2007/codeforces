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
    int a[20];
    int k;
    cin >> k;
    if (k==0) {cout << 0;return 0;}
    int l=0;
    FOR(i,0,12)
        cin >> a[i];
    sort(a,a+12);
    for(int i=11;i>=0;--i){
        l+=a[i];
        if (l>=k) {cout << 12-i;return 0;}
    }
    cout << "-1";
    //system("pause");
    return 0;
}