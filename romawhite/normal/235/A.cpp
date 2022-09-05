#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod=1000000007;

LL gcd(LL a,LL b){
   if (!b) return a;
   return gcd(b,a % b);          
}

int main(){
    LL n;
    cin >> n;
    
    if (n == 1){
       cout << 1 << endl;
       return 0;      
    }
    
    if (n == 2){
       cout <<2 << endl;
       return 0;      
    }
    
    if (n & 1){
       cout << n * (n - 1) * (n - 2) << endl;
       //system("pause");
       return 0;      
    }
    
    LL res1 = n * (n - 1);
    LL r3 = n - 2;
    while (r3 != 1 && (gcd(n , r3) != 1 || gcd(n - 1 , r3) != 1)) --r3;
    
    res1 *= r3;
    
    LL res2 = (n - 1) * (n - 2) * (n - 3);
    cout << max(res1 , res2) << endl;
    
    //system("pause");
    return 0;
}