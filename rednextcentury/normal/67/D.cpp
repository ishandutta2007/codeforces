#include<bits/stdc++.h>
using namespace std;
#define ll long long
int loc[1000000];
int a[1000000];
int b[1000000];
int arr[1000000];
int tree[5000000];
void upd(int x,int l,int r,int v,int val){
    if (l==r)tree[x]=val;
    else {
        if (v<=(l+r)/2)upd(x*2, l, (l+r)/2, v,val);
        else upd(x*2+1,(l+r)/2+1,r,v,val);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
int Q(int x,int l,int r,int s,int e){
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    else {
        return max(Q(x*2,l,(l+r)/2,s,e), Q(x*2+1,(l+r)/2+1,r,s,e));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
        loc[b[i]]=i;
    }
    int mx = 1e6+2;
    int ret=0;
    for (int i=1;i<=n;i++)arr[i]=loc[a[i]];
    for (int i=1;i<=n;i++) {
        int val = Q(1,0,mx,arr[i]+1,mx) + 1;
        upd(1,0,mx,arr[i],val);
        ret=max(ret,val);
    }
    cout<<ret<<endl;
}