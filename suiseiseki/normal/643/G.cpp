#include <cstdio>
const int Maxn=150000;
const int Maxk=5;
int n,m,p;
struct Value{
    int num,lazy;
    int a[Maxk],b[Maxk];
    Value operator =(Value t){
        num=t.num,lazy=0;
        for(int i=0;i<num;i++){
            a[i]=t.a[i],b[i]=t.b[i];
        }
        return (*this);
    }
    friend Value operator +(Value a,Value b){
        Value ans=b;
        for(int i=0;i<a.num;i++){
            bool flag=0;
            for(int j=0;j<ans.num&&!flag;j++){
                if(a.a[i]==ans.a[j]){
                    ans.b[j]+=a.b[i];
                    flag=1;
                }
            }
            if(flag){
                continue;
            }
            if(ans.num<p){
                ans.a[ans.num]=a.a[i];
                ans.b[ans.num]=a.b[i];
                ans.num++;
                continue;
            }
            int k=0;
            for(int j=1;j<ans.num;j++){
                if(ans.b[j]<ans.b[k]){
                    k=j;
                }
            }
            if(a.b[i]<ans.b[k]){
                for(int j=0;j<ans.num;j++){
                    ans.b[j]-=a.b[i];
                }
            }
            else{
                int tmp=ans.b[k];
                ans.a[k]=a.a[i],ans.b[k]=a.b[i];
                for(int j=0;j<ans.num;j++){
                    ans.b[j]-=tmp;
                }
            }
        }
        return ans;
    }
}seg[Maxn<<2|5];
void push_up(int root){
    seg[root]=seg[root<<1]+seg[root<<1|1];
}
void update_tag(int root,int len,int val){
    seg[root].num=1;
    seg[root].lazy=seg[root].a[0]=val;
    seg[root].b[0]=len;
}
void push_down(int root,int left,int right){
    if(seg[root].lazy){
        int mid=(left+right)>>1;
        update_tag(root<<1,mid-left+1,seg[root].lazy);
        update_tag(root<<1|1,right-mid,seg[root].lazy);
        seg[root].lazy=0;
    }
}
int a[Maxn+5];
void build(int root=1,int left=1,int right=n){
    if(left==right){
        seg[root].num=1;
        seg[root].a[0]=a[left];
        seg[root].b[0]=1;
        return;
    }
    int mid=(left+right)>>1;
    build(root<<1,left,mid);
    build(root<<1|1,mid+1,right);
    push_up(root);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
    if(r<left||l>right){
        return;
    }
    if(l<=left&&r>=right){
        update_tag(root,right-left+1,a);
        return;
    }
    push_down(root,left,right);
    int mid=(left+right)>>1;
    update(l,r,a,root<<1,left,mid);
    update(l,r,a,root<<1|1,mid+1,right);
    push_up(root);
}
Value query(int l,int r,int root=1,int left=1,int right=n){
    if(l<=left&&r>=right){
        return seg[root];
    }
    push_down(root,left,right);
    int mid=(left+right)>>1;
    if(r<=mid){
        return query(l,r,root<<1,left,mid);
    }
    if(l>mid){
        return query(l,r,root<<1|1,mid+1,right);
    }
    return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
}
int main(){
    scanf("%d%d%d",&n,&m,&p);
    p=100/p;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build();
    for(int t=1;t<=m;t++){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            int v;
            scanf("%d",&v);
            update(l,r,v);
        }
        else{
            Value ans=query(l,r);
            printf("%d ",ans.num);
            for(int i=0;i<ans.num;i++){
                printf("%d ",ans.a[i]);
            }
            puts("");
        }
    }
    return 0;
}