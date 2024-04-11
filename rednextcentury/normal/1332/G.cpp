#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int nextUp[1000000];
int nextDown[1000000];
int prevUp[1000000];
int prevDown[1000000];
int n,q;
void WhySoManyStacks(){
    stack<int> prevS,prevG,nextS,nextG;
    for (int i=1,j=n;i<=n;i++,j--) {
        while(!prevS.empty() && a[prevS.top()]>=a[i]) prevS.pop();
        prevDown[i] = prevS.empty()?0:prevS.top();
        prevS.push(i);
        while(!prevG.empty() && a[prevG.top()]<=a[i]) prevG.pop();
        prevUp[i] = prevG.empty()?0:prevG.top();
        prevG.push(i);
        while(!nextS.empty() && a[nextS.top()]>=a[j]) nextS.pop();
        nextDown[j] = nextS.empty()?0:nextS.top();
        nextS.push(j);
        while(!nextG.empty() && a[nextG.top()]<=a[j]) nextG.pop();
        nextUp[j] = nextG.empty()?0:nextG.top();
        nextG.push(j);
    }
}
struct SegmentTreeMax{
#define mid ((l+r)>>1)
#define L (x<<1)
#define R (L+1)
    pair<int,int> tree[1000000];
    void set(int x,int l,int r,int id,int v){
        if (id<l || id>r)return;
        if (l==r) {
            tree[x] = max(tree[x],{v,id});
            return;
        }
        set(L,l,mid,id,v);
        set(R,mid+1,r,id,v);
        tree[x]=max(tree[L],tree[R]);
    }
    pair<int,int> query(int x,int l,int r,int s,int e){
        if (s>r || e<l)return {-1,-1};
        if (l>=s && r<=e)return tree[x];
        return max(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
    }
} st3, st4, st;
void get3(){
    for (int i=1;i<=n;i++){
        int A = prevDown[prevUp[i]];
        int B = prevUp[prevDown[i]];
        st3.set(1,1,n, i , max(A,B));
    }
}
vector<int> add[1000000];
void get4(){
    for (int i=1;i<=n;i++){
        if (nextUp[i]==0 || nextDown[i]==0)continue;
        int x = max(nextUp[i],nextDown[i])+1;
        add[x].push_back(i);
    }
    for (int i=1;i<=n;i++){
        for (auto x:add[i]) st.set(1,1,n,x,x);
        int x = min(prevDown[i], prevUp[i]);
        if (x<=1)continue;
        st4.set(1,1,n,i,st.query(1,1,n,1,x-1).first);
    }
}
void go(){
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        auto best4 = st4.query(1,1,n,l,r);
        auto best3 = st3.query(1,1,n,l,r);
        if (best4.first>=l){
            int A = best4.first;
            int d = best4.second;
            if (a[A]<=a[d]){
                printf("4\n%d %d %d %d\n", A, min(nextDown[A],prevUp[d]), max(nextDown[A],prevUp[d]), d);
            } else {
                printf("4\n%d %d %d %d\n", A, min(nextUp[A],prevDown[d]), max(nextUp[A],prevDown[d]), d);
            }
        } else if (best3.first>=l) {
            int c = best3.second;
            int a,b;
            if (prevUp[prevDown[c]]>=l) b = prevDown[c], a = prevUp[b];
            else b = prevUp[c], a = prevDown[b];
            printf("3\n%d %d %d\n",a,b,c);
        } else {
            printf("0\n");
        }
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    WhySoManyStacks();
    get3();
    get4();
    go();
}