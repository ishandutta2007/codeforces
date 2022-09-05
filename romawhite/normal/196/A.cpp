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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=1000000007;

bool comp(pair<char,int> p1, pair<char,int> p2){
    if (p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second)) return 1;
    return 0;
}

int main(){
    vector<pair<char,int> > a;
    string s;
    cin >> s;
    int n = s.size();
    FOR(i,0,n){
        a.PB(MP(s[i],i));
    }
    sort(a.begin(),a.end(),comp);
    int k = -1;
    string res = "";
    FOR(i,0,n)
        if (a[i].second > k){
            k = a[i].second;
            res.PB(a[i].first);
        }
    cout << res;
    return 0;
}