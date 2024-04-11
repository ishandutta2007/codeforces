 #include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define LL long long
#define pb push_back
int a[(int)1e6],w[(int)1e6];
const int maxn = 100100;
const int mod = 1e9+7;
int tree[maxn<<2],tree2[maxn<<2],tree3[maxn<<2];
int n;
inline void add(int r,int v){
    while(r<=n)tree[r]+=v,r+=r&-r;
}
inline int query(int r){
    int ans=0;
    while(r)ans+=tree[r],r&=r-1;
    return ans;
}
inline int query(int l,int r){
    return query(r)-query(l-1);
}
inline void add1(int r,int v){
    while(r<=n)(tree2[r]+=v)%=mod,r+=r&-r;
}
inline int query1(int r){
    int ans=0;
    while(r)(ans+=tree2[r])%=mod,r&=r-1;
    return ans;
}
inline int query1(int l,int r){
    return query1(r)-query1(l-1);
}
 
inline void add2(int r,int v){
    while(r<=n)(tree3[r]+=v)%=mod,r+=r&-r;
}
inline int query2(int r){
    int ans=0;
    while(r)(ans+=tree3[r])%=mod,r&=r-1;
    return ans;
}
inline int query2(int l,int r){
    return query2(r)-query2(l-1);
}
inline int move_1(int l,int r,int pos){
    int len=r-l+1;
    return pos*(query(l,r)%mod)%mod+query2(l,r)-query(l,r)*l%mod  - query1(l,r); 
}
inline int move_2(int l,int r,int pos){
    int len=r-l+1;
    return -pos*(query(l,r)%mod)%mod-query2(l,r)+query(l,r)%mod*l%mod + query1(l,r); 
}
signed main(){
    ios::sync_with_stdio(false);	
    int q;
    cin >>n >>q;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    for(int i=1;i<=n;++i){
        cin >> w[i];
        add(i,w[i]);
        add1(i,a[i]*w[i]%mod);
        add2(i,(i)*w[i]%mod);
    }
    while(q--){
        int x,y;
        cin >>x >>y;
        if(x<0){
            x=-x;
            add(x,-w[x]);
            add1(x,mod-a[x]*w[x]%mod);
            add2(x,mod-(x)*w[x]%mod);
            w[x]=y; 
            add(x,w[x]);
            add1(x,a[x]*w[x]%mod);
            add2(x,(x)*w[x]%mod);
        }else{
            int l = x, r=y;
            while(l!=r){
                int mid=l+r>>1;
                if(query(x,mid) < query(mid+1,y))l=mid+1;
                else r=mid; 
            }
            cout << ((move_1(x,r,a[r]-(r-x+1)+1)+move_2(r+1,y,a[r]+1))%mod+mod)%mod<<endl;
        }
    }
}
/**/