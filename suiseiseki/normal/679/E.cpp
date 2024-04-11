#include <cstdio>
#include <cassert>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
const ll Maxv=100000000000000ll;
ll pow_42[100];
int pow_len;
int find_val(ll x){
    for(int i=0;i<=pow_len;i++){
        if(pow_42[i]>=x){
            return i;
        }
    }
    assert(0);
    return pow_len+1;
}
int n,q;
int a[Maxn+5];
struct Segment_Node{
    ll val;
    int lazy_all_id;
    ll lazy_add,lazy_all_del;
}seg[Maxn<<2|5];
void push_up(int root){
    seg[root].val=std::min(seg[root<<1].val,seg[root<<1|1].val);
}
void update_tag_all(int root,int t_id,ll t_del){
    seg[root].lazy_add=0;
    seg[root].lazy_all_id=t_id;
    seg[root].lazy_all_del=t_del;
    seg[root].val=t_del;
}
void update_tag_add(int root,ll t_add){
    if(seg[root].lazy_all_id){
        seg[root].lazy_all_del-=t_add;
        while(seg[root].lazy_all_del<0){
            seg[root].lazy_all_del+=pow_42[seg[root].lazy_all_id+1]-pow_42[seg[root].lazy_all_id];
            seg[root].lazy_all_id++;
        }
        seg[root].val=seg[root].lazy_all_del;
    }
    else{
        seg[root].val-=t_add;
        seg[root].lazy_add+=t_add;
    }
}
void push_down(int root){
    if(seg[root].lazy_all_del!=0){
        update_tag_all(root<<1,seg[root].lazy_all_id,seg[root].lazy_all_del);
        update_tag_all(root<<1|1,seg[root].lazy_all_id,seg[root].lazy_all_del);
        seg[root].lazy_all_id=seg[root].lazy_all_del=0;
    }
    if(seg[root].lazy_add!=0){
        update_tag_add(root<<1,seg[root].lazy_add);
        update_tag_add(root<<1|1,seg[root].lazy_add);
        seg[root].lazy_add=0;
    }
}
ll update_add(int l,int r,ll a,int root=1,int left=1,int right=n){
    if(l>right||r<left){
        return Maxv;
    }
    if(l<=left&&r>=right&&(seg[root].val>=a||seg[root].lazy_all_id)){
        update_tag_add(root,a);
        return seg[root].val;
    }
    push_down(root);
    int mid=(left+right)>>1;
    update_add(l,r,a,root<<1,left,mid);
    update_add(l,r,a,root<<1|1,mid+1,right);
    push_up(root);
    return seg[root].val;
}
void update_all(int l,int r,int t_id,ll t_add,int root=1,int left=1,int right=n){
    if(l>right||r<left){
        return;
    }
    if(l<=left&&r>=right){
        update_tag_all(root,t_id,t_add);
        return;
    }
    push_down(root);
    int mid=(left+right)>>1;
    update_all(l,r,t_id,t_add,root<<1,left,mid);
    update_all(l,r,t_id,t_add,root<<1|1,mid+1,right);
    push_up(root);
}
ll query(int x,int root=1,int left=1,int right=n){
    if(left==right){
        return pow_42[seg[root].lazy_all_id]-seg[root].lazy_all_del;
    }
    push_down(root);
    int mid=(left+right)>>1;
    if(x<=mid){
        return query(x,root<<1,left,mid);
    }
    else{
        return query(x,root<<1|1,mid+1,right);
    }
}
int main(){
    pow_42[0]=1;
    for(pow_len=1;(pow_42[pow_len]=pow_42[pow_len-1]*42)<=Maxv;pow_len++);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int id_42=find_val(a[i]);
        update_all(i,i,id_42,pow_42[id_42]-a[i]);
    }
    for(int i=1;i<=q;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            printf("%lld\n",query(x));
        }
        else if(op==2){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            int t_id=find_val(x);
            ll t_add=pow_42[t_id]-x;
            update_all(l,r,t_id,t_add);
        }
        else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            while(update_add(l,r,x)==0);
        }
    }
    return 0;
}