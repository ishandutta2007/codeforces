#include <iostream>
#include <map>
using namespace std;
const int N = 500000+10;
const int B = 500000;
pair<int,int> nod[N<<2];
map< pair<int,int>, int > mp;
void update(int l,int r,int rt,int pos,int x) {
    if(l==r) {
        nod[rt]=max(make_pair(x,pos),nod[rt]); return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    nod[rt]=max(nod[rt<<1],nod[rt<<1|1]);
} 
pair<int,int> query(int l,int r,int rt,int L,int R) {
    if(L<=l&&r<=R) return nod[rt];
    int mid=(l+r)>>1;
    if(L> mid) return query(mid+1,r,rt<<1|1,L,R);
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    return max(query(l,mid,rt<<1,L,R), query(mid+1,r,rt<<1|1,L,R));
}
int n,m,l[N],r[N];
int nex[N][20];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]); l[i]++,r[i]++;
        update(1,B,1,l[i],r[i]);
        mp[make_pair(l[i],r[i])] = i;
    }
    for(int i=1;i<=n;i++){
        pair<int,int> tmp=query(1,B,1,l[i],r[i]);
        nex[ mp[make_pair(l[i],r[i])] ][0] = mp[make_pair(tmp.second,tmp.first)];
        //printf("%d->%d\n", mp[make_pair(l[i],r[i])], mp[make_pair(tmp.second,tmp.first)]);
    }
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            nex[j][i] = nex[nex[j][i-1]][i-1];
            //printf("nex %d %d = %d\n", j,i,nex[j][i]);
        }
    }
    for(int i=1;i<=m;i++) {
        int x,y; scanf("%d%d",&x,&y);x++,y++;
        pair<int,int> tmp=query(1,B,1,1,x);
        int now=mp[make_pair(tmp.second,tmp.first)];
        //printf("$ now = %d\n", now);
        int ans=0;
        for(int i=19;i>=0;i--) {
            if(r[ nex[now][i] ] < y) {
                now = nex[now][i]; ans |= 1<<i;
            }
        }
        if(r[ nex[now][0] ] < y) {
            printf("-1\n"); continue;
        }
        if(r[now] < y) ans ++;
        printf("%d\n", ans+1);
    }
}