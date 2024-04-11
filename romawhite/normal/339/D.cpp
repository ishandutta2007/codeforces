//#pragma comment(linker, "/STACK:32777216")
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
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
 
const double pi=3.141592653589793;
const int INF=1000000000;
const int MOD=1000000007;

int t[1000000];
int a[200000];

void build(int v,int l,int r,bool st){
     if (l == r){
        t[v] = a[l];
        return;      
     }     
     int m = (l + r) / 2;
     build(2 * v + 1 , l , m , st ^ 1);
     build(2 * v + 2 , m + 1 , r, st ^ 1);
     if (st)
        t[v] = t[2 * v + 1] | t[2 * v + 2];
     else t[v] = t[2 * v + 1] ^ t[2 * v + 2];
}

void update(int v,int l,int r,int pos,int val,bool st){
     if (l == r){
        t[v] = val;
        return;      
     }     
     int m = (l + r) / 2;
     if (pos <= m)
        update(2 * v + 1, l , m , pos, val, !st);
     else     update(2 * v + 2 , m + 1 , r, pos,val, !st);
     if (st)
        t[v] = t[2 * v + 1] | t[2 * v + 2];
     else t[v] = t[2 * v + 1] ^ t[2 * v + 2];
}

int main(){
    int n,m;
    cin >> n >> m;
    FOR(i,0,1 << n)
              cin >> a[i];
    build(0,0,(1<<n) - 1,(n) % 2);
  
    FOR(i,0,m){
               int p,b;
               cin >> p>> b;
               --p;
               update(0,0,(1 << n) - 1,p,b,(n) % 2);
               cout << t[0] << endl;         
    }

    
   //system("pause");
   return 0;
}