#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
namespace BIT {
    const int M = 300000 + 100;
    int Time[N],bit[N],CLOCK;
    void rebirth() {
        CLOCK ++;
    }
    void add(int pos,int x) {
        //printf("add %d %d\n", pos,x);
        while(pos<M) {
            if(Time[pos]!=CLOCK) Time[pos]=CLOCK, bit[pos]=0;
            bit[pos] += x; pos += pos&-pos;
        }
    }
    int sum(int pos) {
        //printf("sum %d\n", pos);
        int ans=0;
        while(pos) {
            if(Time[pos]!=CLOCK) Time[pos]=CLOCK, bit[pos]=0;
            ans += bit[pos], pos -= pos&-pos;
        } return ans;
    }
};
int n,k;
struct Nod {
    int tp,x,y, id;
} nod[N]; int tot=0;
bool cmp(Nod A, Nod B) {
    if (A.x==B.x) return A.tp < B.tp;
    return A.x < B.x;
}

vector<int> v;
int id(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
struct Robot {
    int x,r,q;
    bool operator < (const Robot & o) const {
        return r > o.r;
    }
    void read() {
        scanf("%d%d%d",&x,&r,&q); v.push_back(q); v.push_back(q-k); v.push_back(q+k);
    }
} robot[N];

LL ans = 0;
void cdq(int l,int r) {
    if(l==r) return;
    int mid = (l+r)>>1;
    vector<Nod> vL, vR;
    for(int i=l;i<=r;i++) {
        if(i<=mid) vL.push_back(nod[i]);
        else vR.push_back(nod[i]);
    }
    sort(vL.begin(),vL.end(),cmp);
    sort(vR.begin(),vR.end(),cmp);
    /*
    printf("solve %d %d\n", l, r);
    printf("L:\n");
    for(auto p: vL) printf("%d %d %d\n", p.tp,p.x,p.y);
    printf("R:\n");
    for(auto p: vR) printf("%d %d %d\n", p.tp,p.x,p.y);
    */
    BIT::rebirth();
    for(int r=0,l=0;r<vR.size();r++) {
        while(l<vL.size() && vL[l].x <= vR[r].x) {
            if(vL[l].tp == 2) BIT::add(vL[l].y, 1); l ++;
        }
        if(vR[r].tp != 2) {
            ans = ans + vR[r].tp * BIT::sum(vR[r].y);
            //printf("ans[%d] += %d\n", vR[r].id, vR[r].tp * BIT::sum(vR[r].y));
        }
    }
    cdq(l,mid); cdq(mid+1,r);
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        robot[i].read();
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    sort(robot+1,robot+1+n);
    for(int i=1;i<=n;i++) {
        int x1=robot[i].x-robot[i].r, y1=id(robot[i].q-k);
        int x2=robot[i].x+robot[i].r, y2=id(robot[i].q+k);
        nod[++tot] = (Nod){+1, x1-1, y1-1, i};
        nod[++tot] = (Nod){-1, x2, y1-1, i};
        nod[++tot] = (Nod){-1, x1-1, y2, i};
        nod[++tot] = (Nod){+1, x2, y2, i};
        nod[++tot] = (Nod){2, robot[i].x, id(robot[i].q), i};
    }   
    for(int i=1;i<=tot;i++) {
        //printf("%d %d %d\n", nod[i].tp, nod[i].x, nod[i].y);
    }
    cdq(1,tot);
    cout << ans << endl;
}