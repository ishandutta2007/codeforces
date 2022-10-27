#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N=600000+10;
typedef long long LL;

int n,p[N],s[N];

bool insert(LL x) {
    for (int i = 62; i >= 0; i --) if ((x >> i) & 1) {
        if ( p[i] ) {
            x ^= p[i];
        } else {
            p[i] = x; 
            return true;
        }
    }
    return false;
} 
vector<int> v;

bool check(int x) {
    memset(p, 0, sizeof(p));
    v.clear();
    for(int i=1;i<=n;i++) {
        if(s[i]<(1<<x)) {
            if (insert(s[i])) {
                v.push_back(s[i]);
            }
        }
    }
    if (v.size() == x) {
        printf("%d\n", x);
        int pre = 0;
        printf("0");
        for(int i=1;i<=(1<<x)-1;i++) {
            for(int j=0;j<x;j++){
                if(i>>j&1) {
                    pre ^= v[j];
                    printf(" %d", pre);
                    break;
                }
            }
        }
        exit(0);
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &s[i]);
    }
    for(int i=20;i>=0;i--){
        check(i);
    }
}