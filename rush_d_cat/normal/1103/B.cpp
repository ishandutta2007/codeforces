#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000+10;

bool query(int x,int y){
    printf("? %d %d\n", x,y); fflush(stdout);
    char s[2]; scanf("%s",s);
    if(s[0]=='x') return 1; 
    return 0;
}
void solve(){

    char s[10]; scanf("%s",s);
    if(s[0]=='e') exit(0);

    if(query(0,1) == 1) {
        printf("! %d\n", 1); fflush(stdout); return;
    }

    int now=1;
    while(query(now,now*2)==0){
        now*=2;
    }
    int lef=now,rig=now*2,x=now;
    while(rig-lef>1){
        int mid=(lef+rig)>>1;
        if(query(x,mid))
            rig=mid;
        else
            lef=mid;
    }
    printf("! %d\n", rig); fflush(stdout);
}

int main(){
    while(true) {
        solve();
    }
}

/*

*/