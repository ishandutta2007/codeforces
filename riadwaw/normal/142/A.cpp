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
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
li mx=0;
li mn=1LL<<55;
void z(li a,li b,li c){
    li g=(a+1)*(b+2)*(c+2);
    mx=max(mx,g);
    mn=min(mn,g);
}
void a(int x,int y){
    for(int b=1;b*b<=x;++b){
        if(x%b==0){
            z(y,b,x/b);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            a(i,n/i);
            a(n/i,i);
        }
    }

    cout<<mn-n<<' '<<mx-n;
}