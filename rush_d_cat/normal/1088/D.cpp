#include <iostream>
using namespace std;
int a,b;
int pa,pb;
int laji;
int ask(int c,int d) {
    printf("? %d %d\n", c,d); fflush(stdout);
    int ans; scanf("%d",&ans); if(ans==0)ans=1;
    return ans;
}

void solve(int bit) {
    int r1 = ask(pa+(1<<bit), pb+(1<<bit));
    
    int r2;
    if(laji == +1) r2 = ask(pa+0, pb+(1<<bit));
    if(laji == -1) r2 = ask(pa+(1<<bit), pb+0);
    
    if(laji == r1) {
        // 00, 11
        if (r2 == laji) {
            pa += 1<<bit;
            pb += 1<<bit;
        } else {

        }
        laji = r1;
    }
    if(laji != r1) {
        // 01, 10
        if(laji == -1) {
            pb += 1<<bit;
            laji = r2;
        } else {
            pa += 1<<bit;
            laji = r2;
        }
    }
}

int main() {
    pa=0,pb=0;
    laji = ask(0,0);
    for(int i=29;i>=0;i--) {
        solve(i);
    }
    printf("! %d %d\n", pa,pb); fflush(stdout);
}