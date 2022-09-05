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

const double pi=3.141592653589793;

int main(){
    int n,k=0,l;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>l;
        if (l%2) k++;
    }
    if (k%2) cout<<k; else cout<<n-k;
    //system("pause");
    return 0;
}