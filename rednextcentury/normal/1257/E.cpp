#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
int tree[1000000];
void upd(int x,int l,int r,int id,int val){
    if (l==r)tree[x]=val;
    else {
        if (id<=mid)upd(L,l,mid,id,val);
        else upd(R,mid+1,r,id,val);
        tree[x]=max(tree[L],tree[R]);
    }
}
int query(int x,int l,int r,int s,int e) {
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    return max(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int n = n1+n2+n3 , ret=0;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n1);
    sort(a+n1,a+n1+n2);
    sort(a+n1+n2,a+n);
    for (int i=0;i<n;i++) {
        int cur = query(1,0,n,0,a[i])+1;
        ret=max(ret,cur);
        upd(1,0,n,a[i],cur);
    }
    cout<<n-ret<<endl;
}