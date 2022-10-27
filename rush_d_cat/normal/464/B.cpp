#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
int a[9][3];

vector<LL> v;
LL sqr(LL x) {return x*x;}
bool chk() {
    v.clear();
    for(int i=1;i<=8;i++){
        for(int j=i+1;j<=8;j++){
            LL t = sqr(a[i][0]-a[j][0])+sqr(a[i][1]-a[j][1])+sqr(a[i][2]-a[j][2]); v.push_back(t);
        }
    }
    sort(v.begin(),v.end());
    if(v[0]!=v[11]) return 0; // [0,12)   1
    if(v[12]!=v[23])return 0; // [12,24)  2
    if(v[24]!=v[27])return 0; // [24,28)  3
    if(2*v[0]!=v[12]||3*v[0]!=v[24]) return 0;
    if(v[0]==0) return 0;
    return 1;
}

void dfs(int dep){
    if(dep==9) {
        if(chk()) {
            printf("YES\n");
            for(int i=1;i<=8;i++) {
                for(int j=0;j<3;j++) printf("%d ", a[i][j]); printf("\n");
            }
            exit(0);
        }
        return;
    }
    do {
        dfs(dep+1);
    } while(next_permutation(a[dep],a[dep]+3) && dep!=1);
}

int main(){
    for(int i=1;i<=8;i++) {
        for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
        sort(a[i],a[i]+3);
    }
    dfs(1);
    printf("NO\n");
}