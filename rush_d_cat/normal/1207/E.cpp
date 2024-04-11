#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N=500000+10;
const int B=707;
typedef long long LL;

int ask(vector<int> v) {
    printf("?");
    for(auto x: v) printf(" %d", x);
    printf("\n"); fflush(stdout);
    int x; scanf("%d",&x); return x;
}

int main() {
    vector<int> v;
    for(int i=0;i<100;i++) v.push_back(i); int A=ask(v);
    v.clear(); for(int i=0;i<100;i++) v.push_back((i+1)<<7); int B=ask(v);
    int ans=0;
    for(int i=0;i<7;i++) if(B>>i&1) ans|=1<<i;
    for(int i=7;i<14;i++) if(A>>i&1) ans|=1<<i;
    printf("! %d\n", ans); fflush(stdout);
}