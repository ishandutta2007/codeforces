#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
struct node{
    int a[26];
};
node tree[400005];
int lazy[400005];
void lzy(int x,int l,int r)
{
    if (!lazy[x])return;
    if (l!=r)lazy[L]=lazy[R]=lazy[x];
    for (int i=0;i<26;i++)tree[x].a[i]=0;
    tree[x].a[lazy[x]-1]=r-l+1;
    lazy[x]=0;
}
string s;
node emp;
void build(int x,int l,int r)
{
    if (l==r)tree[x].a[s[l]-'a']=1;
    else {
        build(L,l,mid);build(R,mid+1,r);
        for (int i=0;i<26;i++)tree[x].a[i]=tree[L].a[i]+tree[R].a[i];
    }
}
void upd(int x,int l,int r,int s,int e,int v){
    lzy(x,l,r);
    if (l>e || r<s)return;
    if (l>=s && r<=e){
        lazy[x]=v;
        lzy(x,l,r);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    for (int i=0;i<26;i++)tree[x].a[i]=tree[L].a[i]+tree[R].a[i];
}
node query(int x,int l,int r,int s,int e)
{
    lzy(x,l,r);
    if (l>e || r<s)return emp;
    if (l>=s && r<=e)return tree[x];
    node p1 = query(L,l,mid,s,e);
    node p2 = query(R,mid+1,r,s,e);
    for (int i=0;i<26;i++)p1.a[i]+=p2.a[i];
    return p1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    cin>>s;
    s="."+s;
    build(1,1,n);
    for (int i=0;i<q;i++) {
        int l,r,k;
        cin>>l>>r>>k;
        node p = query(1,1,n,l,r);
        if (k==1){
            for(int j=0;j<26;j++){
                if (p.a[j]==0)continue;
                upd(1,1,n,l,l+p.a[j]-1,j+1);
                l+=p.a[j];
            }
        } else {
            for(int j=25;j>=0;j--){
                if (p.a[j]==0)continue;
                upd(1,1,n,l,l+p.a[j]-1,j+1);
                l+=p.a[j];
            }
        }

    }
    for (int i=1;i<=n;i++) {
        node p = query(1,1,n,i,i);
        int j=0;
        while(p.a[j]==0)j++;
        cout<<char('a'+j);
    }
    cout<<endl;
}