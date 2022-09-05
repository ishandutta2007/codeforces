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
    int n;
    vector <pair<int,int>> a;
    cin >> n;
    int k;
    FOR(i,0,n){
        cin >> k;
        a.PB(MP(k,i+1));
    }
    sort(ALL(a));
    if (n%2 == 1){
    cout << n/2+1 << endl;
    for(int i=0;i<n;i+=2)
        cout << a[i].Y << ' ';
    cout << endl << n/2 << endl;
    for(int i=1;i<n;i+=2)
        cout << a[i].Y << ' ';
    }
    else{
    cout << n/2 << endl;
    for(int i=0;i<n;i+=2)
        cout << a[i].Y << ' ';
    cout << endl << n/2 << endl;
    for(int i=1;i<n;i+=2)
        cout << a[i].Y << ' ';
    }
    //system("pause");
    return 0;
}