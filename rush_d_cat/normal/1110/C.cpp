#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
map<int,int> mp;

const int N = 200000 + 10;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

int solve(int a) {
    int ans=0;
    for(int i=1;i<a;i++){
        ans=max(ans,gcd(i^a,i&a));
    }
    return ans;
}

int cac(int x) {
    if(mp[x]) return mp[x];
    for(int i=2;i*i<=x;i++){
        if(x%i==0) {
            return mp[x] = x/i;
        }
    }
    return mp[x] = 1;
}

int main() {

    int q; scanf("%d", &q);
    while(q--){
        int x;scanf("%d",&x);
        int t=1;
        while(t<=x) t*=2;
        t --;
        if (t == x) {
            printf("%d\n", cac(x));
        } else {
            printf("%d\n", t);
        }
    } 

}