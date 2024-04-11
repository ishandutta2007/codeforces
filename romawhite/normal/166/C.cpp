//#pragma comment (linker, "/STACK:500000000")
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
const int N=100000000;
typedef vector<int> lnum;
const int base = 10;
lnum read(string s){
    lnum a;
    for (int i=(int)s.length(); i>0; i-=1)
        if (i < 1)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-1, 1).c_str()));
    return a;
}

lnum add(lnum a,lnum b){
    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry) a[i] -= base;
    }
    return a;
}

lnum mul(lnum a,int b){
    int carry = 0;
    for (size_t i=0; i<a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

int main() {
    bool q=0;
    int n;
    int x;
    cin>> n>> x;
    vector<int> a;
    FOR(i,0,n){
        int k;
        cin >> k;
        if (k==x) q=1;
        a.PB(k);
    }
    int res=0;
    if (!q) {a.PB(x); res = 1;}
    sort(ALL(a));
    int m = INF;
    int y = (a.size()-1)/2;
    FOR(i,0,a.size())
        if (a[i] == x){
            m = i;
            break;
        }
        int M=m;
        while (M+1<a.size() && a[M+1] == x) M++;
        if (M>=y && m<=y) {cout<< res; return 0;}
        if (m>y){
            int nn = a.size();
            while (1){
                nn++;
                y = (nn-1)/2;
                res++;
                if (m == y){
                    cout<< res;
                    return 0;
                }
            }
        }
        if (M<y){
            int nn = a.size();
            while (1){
                nn++;
                M++;
                y = (nn-1)/2;
                res++;
                if (M == y){
                    cout<< res;
                    return 0;
                }
            }
        }
        return 0;
}