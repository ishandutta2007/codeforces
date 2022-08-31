#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int M = 21;

int n;

int nck(int n, int k) { 
    LL r = 1; 
    if (k > n - k) 
        k = n - k; 
    for (int i = 0; i < k; ++i) { 
        r *= (n - i); 
        r /= (i + 1); 
    } 
    return r; 
} 
 
LL solve() {
    if (n==2) return 1;
    if (n==4) return 3;
    int n2 = n / 2;
    LL r = nck(n - 1, n2 - 1);
    LL rr = 1;
    for (int i = 2; i < n2; i++)
        rr *= i;
    return r * rr * rr;
}

int main() {
    setIO();
    cin>>n;
    cout<<solve()<<"\n";    
    return 0;
}