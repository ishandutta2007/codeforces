#include <cstdio>
#include <algorithm>
typedef long long ll;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
const int Maxn=100000;
ll k,w[Maxn+5],g[Maxn+5],pre[Maxn+5],suf[Maxn+5];
int n,nxt[Maxn+5],ans;
struct Segment_Node{
    ll a_min,b_min;
    ll ans;
    ll lazy;
}seg[Maxn<<2|5];
void update_tag(int root,ll x){
    seg[root].b_min+=x;
    seg[root].ans-=x;
    seg[root].lazy+=x;
}
void push_down(int root){
    if(seg[root].lazy){
        update_tag(root<<1,seg[root].lazy);
        update_tag(root<<1|1,seg[root].lazy);
        seg[root].lazy=0;
    }
}
ll calc_ans(ll p,int root,int left,int right){
    if(left==right){
        return seg[root].a_min-p;
    }
    push_down(root);
    int mid=(left+right)>>1;
    if(seg[root<<1].b_min<p){
        return std::min(calc_ans(p,root<<1,left,mid),seg[root].ans);
    }
    else{
        return std::min(seg[root<<1].a_min-p,calc_ans(p,root<<1|1,mid+1,right));
    }
}
void build(int root=1,int left=1,int right=n){
    if(left==right){
        seg[root].a_min=seg[root].b_min=suf[left];
        return;
    }
    int mid=(left+right)>>1;
    build(root<<1,left,mid);
    build(root<<1|1,mid+1,right);
    seg[root].a_min=std::min(seg[root<<1].a_min,seg[root<<1|1].a_min);
    seg[root].b_min=std::min(seg[root<<1].b_min,seg[root<<1|1].b_min);
    seg[root].ans=calc_ans(seg[root<<1].b_min,root<<1|1,mid+1,right);
}
void update(int l,int r,ll x,int root=1,int left=1,int right=n){
    if(l>right||r<left){
        return;
    }
    if(l<=left&&r>=right){
        update_tag(root,x);
        return;
    }
    push_down(root);
    int mid=(left+right)>>1;
    update(l,r,x,root<<1,left,mid);
    update(l,r,x,root<<1|1,mid+1,right);
    seg[root].b_min=std::min(seg[root<<1].b_min,seg[root<<1|1].b_min);
    seg[root].ans=calc_ans(seg[root<<1].b_min,root<<1|1,mid+1,right);
}
int query_2(ll v,int root,int left,int right){
    if(left==right){
        return left;
    }
    int mid=(left+right)>>1;
    if(seg[root<<1|1].a_min<=v){
        return query_2(v,root<<1|1,mid+1,right);
    }
    else{
        return query_2(v,root<<1,left,mid);
    }
}
int query_1(ll &p,int root=1,int left=1,int right=n){
    if(left==right){
        int ans=seg[root].a_min-p<=k?left:0;
        p=std::min(p,seg[root].b_min);
        return ans;
    }
    push_down(root);
    int mid=(left+right)>>1;
    if(seg[root<<1].b_min<p){
        if(seg[root].ans<=k){
            p=seg[root<<1].b_min;
            return query_1(p,root<<1|1,mid+1,right);
        }
        else{
            int ans=query_1(p,root<<1,left,mid);
            p=std::min(p,seg[root].b_min);
            return ans;
        }
    }
    else{
        int ans=(seg[root<<1].a_min<=k+p?query_2(k+p,root<<1,left,mid):0);
        return std::max(ans,query_1(p,root<<1|1,mid+1,right));
    }
}
int head[Maxn+5],arrive[Maxn+5],_nxt[Maxn+5],tot;
void add_edge(int from,int to){
    arrive[++tot]=to;
    _nxt[tot]=head[from];
    head[from]=tot;
}
void init_dfs(int u){
    static int st[Maxn+5],top=0;
    st[++top]=u;
    if(nxt[u]<=n){
        update(nxt[u]-1,n,pre[u]-pre[nxt[u]]);
    }
    if(u<=n){
        int left=1,right=top-1;
        while(left<right){
            int mid=(left+right+1)>>1;
            if(pre[st[mid]]-pre[u]>k){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        int r_max=st[left]-1;
        ll tmp=Inf;
        if(u>1){
            update(1,u-1,Inf);
        }
        update(r_max,n,-Inf);
        int pos=query_1(tmp);
        update(r_max,n,Inf);
        if(u>1){
            update(1,u-1,-Inf);
        }
        ans=std::max(ans,pos-u+1);
    }
    for(int i=head[u];i;i=_nxt[i]){
        int v=arrive[i];
        init_dfs(v);
    }
    if(nxt[u]<=n){
        update(nxt[u]-1,n,pre[nxt[u]]-pre[u]);
    }
    top--;
}
int main(){
    static int st[Maxn+5],top=0;
    scanf("%d%lld",&n,&k);
    ans=1;
    for(int i=1;i<n;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&g[i]);
    }
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1]-g[i-1]+w[i-1];
        suf[i]=suf[i-1]-g[i]+w[i-1];
    }
    pre[n+1]=Inf,nxt[n+1]=n+1;
    st[++top]=n+1;
    for(int i=n;i>0;i--){
        while(pre[st[top]]<=pre[i]){
            top--;
        }
        nxt[i]=st[top];
        st[++top]=i;
        add_edge(nxt[i],i);
    }
    build();
    init_dfs(n+1);
    printf("%d\n",ans);
    return 0;
}