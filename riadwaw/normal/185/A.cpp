#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <unordered_map>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
const li mod = 1000000007;
struct matrix{
    li a[2][2];
    matrix(){
        a[0][0] = 1;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
    }
    
    matrix operator * (const matrix& x){
        matrix t;
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                t.a[i][j] = 0;
                for(int k =0;k<2;++k){
                    t.a[i][j] += (a[i][k] * x.a[k][j]) % mod;
                    t.a[i][j] %= mod;
                }
            }
        }
        return t;
    }
};

matrix pow(matrix a, li b){
    if(!b)
        return matrix();
    if(b%2)
        return a * pow(a, b-1);
    
    return pow(a*a, b/2);
}
void solve(){
    li n;
    cin>>n;
    
    
    matrix m;
    m.a[0][0] = m.a[1][1] = 3;
    m.a[0][1] = m.a[1][0] = 1;
    
    matrix p = pow(m ,n);
    cout<<p.a[0][0];
}