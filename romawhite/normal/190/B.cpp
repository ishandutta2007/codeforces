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

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
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

typedef vector<int> lnum;
const int base = 1000*1000*1000;

void print(lnum a){
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
        printf ("%09d", a[i]);
}

lnum read(string s){
    lnum a;
    for (int i=(int)s.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
    return a;
}

lnum add(lnum a,lnum b){
    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
    return a;
}

lnum wid(lnum a,lnum b){
    int carry = 0;
    for (size_t i=0; i<b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry)  a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

struct circle{
    double x;
    double y;
    double r;
};

double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUT.TXT","w",stdout);
    circle c1,c2;
    cin >> c1.x >> c1.y >> c1.r;
    cin >> c2.x >> c2.y >> c2.r;
    if (c1.r > c2.r) swap(c1,c2);
    double d = dist(c1.x,c1.y,c2.x,c2.y);
    if (d >= c1.r + c2.r){
        printf("%.20f",(d - c1.r - c2.r)/2);
        return 0;
    }
    if (c2.r >  c1.r + d){
        printf("%.20f",(-d - c1.r + c2.r)/2);
        return 0;
    }
    printf("0");
    return 0;
}