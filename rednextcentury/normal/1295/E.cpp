#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
int p[1000000];
int loc[1000000];
int a[1000000];
ll s1[3000000];
ll s2[3000000];
ll S[3000000];
ll c[3000000];
ll lazy[3000000];
void lzy(int x,int l,int r){
    S[x]+=lazy[x];
    if (l!=r){
        lazy[L]+=lazy[x];
        lazy[R]+=lazy[x];
    }
    lazy[x]=0;
}
void Build(int x,int l,int r){
    if (l==r)S[x]=c[l];
    else {
        Build(L,l,mid);
        Build(R,mid+1,r);
        S[x]=min(S[L],S[R]);
    }
}
void upd(int x,int l,int r,int s,int e,int val){
    lzy(x,l,r);
    if (s>r || e<l)return;
    if (l>=s && r<=e){
        lazy[x]+=val;
        lzy(x,l,r);
        return;
    }
    else{
        upd(L,l,mid,s,e,val);
        upd(R,mid+1,r,s,e,val);
        S[x]=min(S[L],S[R]);
    }
}
ll Q(int x,int l,int r,int s,int e){
    lzy(x,l,r);
    if (s>r || e<l)return 0;
    if (l>=s && r<=e){
        return S[x];
    }
    else{
        return min(Q(L,l,mid,s,e),Q(R,mid+1,r,s,e));
    }
}
void build(int x,int l,int r){
    if (l==r)s1[x]=a[l];
    else {
        build(L,l,mid);
        build(R,mid+1,r);
        s1[x]=s1[L]+s1[R];
    }
}
void upd1(int x,int l,int r,int v,int val){
    if (v<l || v>r)return;
    if (l==r)s1[x]=val;
    else{
        upd1(L,l,mid,v,val);
        upd1(R,mid+1,r,v,val);
        s1[x]=s1[L]+s1[R];
    }
}
void upd2(int x,int l,int r,int v,int val){
    if (v<l || v>r)return;
    if (l==r)s2[x]=val;
    else{
        upd2(L,l,mid,v,val);
        upd2(R,mid+1,r,v,val);
        s2[x]=s2[L]+s2[R];
    }
}
ll query1(int x,int l,int r,int s,int e){
    if (s>e)return 0;
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return s1[x];
    return query1(L,l,mid,s,e)+query1(R,mid+1,r,s,e);
}
ll query2(int x,int l,int r,int s,int e){
    if (s>e)return 0;
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return s2[x];
    return query2(L,l,mid,s,e)+query2(R,mid+1,r,s,e);
}
int n;
ll calc(int pos){
    if (pos==n)return 1e18;
    return query1(1,1,n,1,pos)+query2(1,1,n,pos+1,n);
}


int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&p[i]), loc[p[i]]=i;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    for (int i=1;i<n;i++)c[i]=calc(i);
    Build(1,1,n-1);
    ll ret=Q(1,1,n-1,1,n-1);
    for (int i=1;i<=n;i++) {
        ll v = a[loc[i]];
        upd(1,1,n-1,loc[i],n-1,-v);
        upd(1,1,n-1,1,loc[i]-1,v);
        ret = min(ret, Q(1,1,n-1,1,n-1));
    }
    cout<<ret<<endl;

}