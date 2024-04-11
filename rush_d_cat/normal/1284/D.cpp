#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
vector<int> v;
int id(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

struct Nod {
    int mn, cnt, lz;
    Nod(){
        mn=0,cnt=0,lz=0;
    }
    Nod operator+(const Nod&o)const{
        Nod ans=Nod();
        ans.mn=min(mn,o.mn);
        if(ans.mn==mn)ans.cnt+=cnt;
        if(ans.mn==o.mn)ans.cnt+=o.cnt;
        return ans;
    }
    void print() {
        //printf("mn=%d,cnt=%d,lz=%d\n", mn,cnt,lz);
    }
} nod[3][N<<2];

struct Item {
    int sa, ea, sb, eb;
    void read() {
        scanf("%d%d%d%d", &sa, &ea, &sb, &eb);
    }
} it[N], it1[N], it2[N];

void pushdown(int id, int rt) {
    if(nod[id][rt].lz) {
        nod[id][rt<<1].lz += nod[id][rt].lz;
        nod[id][rt<<1].mn += nod[id][rt].lz;
        nod[id][rt<<1|1].lz += nod[id][rt].lz;
        nod[id][rt<<1|1].mn += nod[id][rt].lz;
        nod[id][rt].lz=0;
    }
}
void build(int l,int r,int rt){
    for(int i=0;i<3;i++) {
        nod[i][rt] = Nod();
    }
    if(l==r){
        for(int i=0;i<3;i++) {
            nod[i][rt].cnt=1;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    for(int i=0;i<3;i++) {
        nod[i][rt] = nod[i][rt<<1] + nod[i][rt<<1|1];
    }
}
void update(int id,int l,int r,int rt,int L,int R,int x){
    //printf("id=%d,l=%d,r=%d,rt=%d\n", id,l,r,rt);
    if(L<=l && r<=R) {
        nod[id][rt].mn += x; 
        nod[id][rt].lz += x;
        return;
    }
    int mid=(l+r)>>1; pushdown(id,rt);
    if(L<=mid) update(id,l,mid,rt<<1,L,R,x);
    if(R >mid) update(id,mid+1,r,rt<<1|1,L,R,x);
    nod[id][rt]=nod[id][rt<<1]+nod[id][rt<<1|1];
}
Nod query(int id,int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return nod[id][rt];
    int mid=(l+r)>>1; pushdown(id,rt);
    if(R<=mid) return query(id,l,mid,rt<<1,L,R);
    if(L >mid) return query(id,mid+1,r,rt<<1|1,L,R);
    return query(id,l,mid,rt<<1,L,R) + query(id,mid+1,r,rt<<1|1,L,R);
}
int Unoin(int id) {
    int ans = v.size();
    Nod nod = query(id,1,v.size(),1,1,v.size());
    nod.print();
    if(nod.mn == 0) {
        ans = ans - nod.cnt;
    }
    //printf("ans = %d\n", ans);
    return ans;
}
bool cmp1(Item A, Item B) {
    return A.ea < B.ea;
}
bool cmp2(Item A, Item B) {
    return A.sa < B.sa;
}
int n;

bool chk() {
    v.clear();

    for(int i=1;i<=n;i++){
        v.push_back(it[i].sb);
        v.push_back(it[i].eb);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
   // printf("# %d\n", v.size());
    
    for(int i=1;i<=n;i++) {
        it1[i]=it[i]; 
        it1[i].sb = id(it1[i].sb);
        it1[i].eb = id(it1[i].eb);
    }
    sort(it1+1,it1+1+n,cmp1);
    for(int i=1;i<=n;i++) {
        it2[i]=it[i]; 
        it2[i].sb = id(it2[i].sb);
        it2[i].eb = id(it2[i].eb);
    }
    sort(it2+1,it2+1+n,cmp2);
    
    for(int i=0;i<N<<2;i++)for(int j=0;j<3;j++)nod[j][i]=Nod();
    build(1,v.size(),1);
    for(int i=1;i<=n;i++){
        //printf("$ upd (0,2) %d %d %d\n", it2[i].sb, it2[i].eb, 1);
        update(0,1,v.size(),1,it2[i].sb,it2[i].eb,1);
        update(2,1,v.size(),1,it2[i].sb,it2[i].eb,1);
    }
    for(int i=1,j=1;i<=n;i++){
        //printf("## i = %d, j = %d [%d,%d]\n", i, j, it1[i].sa, it1[i].ea);
        while(j<=n && it2[j].sa <= it1[i].ea) {
            //printf("# upd (0,2) %d %d %d\n", it2[j].sb, it2[j].eb, -1);
            //printf("Del [%d, %d]\n", it2[j].sa, it2[j].ea);
            update(0,1,v.size(),1,it2[j].sb,it2[j].eb,-1);
            update(2,1,v.size(),1,it2[j].sb,it2[j].eb,-1);
            j++;
            //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            //Unoin(2);
        }
       // printf("upd (0,1) %d %d %d\n", it1[i].sb, it1[i].eb, 1);
        update(0,1,v.size(),1,it1[i].sb,it1[i].eb,1);
        update(1,1,v.size(),1,it1[i].sb,it1[i].eb,1);
      //  printf("%d %d %d\n", Unoin(0), Unoin(1), Unoin(2));
        if (Unoin(0) != Unoin(1) + Unoin(2)) return 0;
    }
    //printf("Win!!\n");
    return 1;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        it[i].read();
    }
    bool ok = 1;
    ok &= chk();
    //printf("!------------------\n");
    for(int i=1;i<=n;i++){
        swap(it[i].sa, it[i].sb);
        swap(it[i].ea, it[i].eb);
    }
    ok &= chk();
    printf("%s\n", ok ?"YES":"NO");
}