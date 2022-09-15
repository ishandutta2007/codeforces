#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
int shift = 1<<18;
struct segtree{
    
    int a[1<<19];
    segtree(){
        memset(a,0,sizeof(a));
    }
    void setr(int l,int r){
        if(l>r)
            return;
        if(l%2){
            a[l]++;
            setr(l+1,r);
            return;
        }
        if(r%2==0){
            a[r]++;
            setr(l,r-1);
            return;
        }
        setr(l/2,r/2);
    }
    void set(int l,int r){
        //cout<<l<<' '<<r<<endl;
        setr(l+shift, r+shift-1);
    }
    
    li getr(int l){
        if(!l)
            return 0;
        return a[l]+getr(l/2);
    }
    li get(int l){
        return getr(l+shift);
    }
};

li a[101010];

li ans[101010];
void solve(){
    li n,l, v1, v2;
    cin>>n>>l>>v1>>v2;
    double LEN = (v1+v2);
    vi b;
    b.pb(0);
    b.pb(2*l*(v1+v2));
    for(int i=0;i<n;++i){
        cin>>a[i];
        b.pb(a[i]*(v1+v2));
        b.pb((a[i]*(v1+v2)-l*v2 + 2*l*(v1+v2))%(2*l*(v1+v2)));
    }
    sort(b.begin(), b.end());
    
    b.erase(unique(b.begin(),b.end()),b.end());
    segtree st;
    for(int i=0;i<n;++i){
        //cin>>a[i];
        li rr=a[i]*(v1+v2);
        li ll=(a[i]*(v1+v2)-l*v2);
    //  cout<<"x"<<ll/LEN << ' '<<rr/LEN<<endl;
        if(ll<0){
            st.set(0,lower_bound(b.begin(),b.end(),rr)-b.begin());
            st.set(lower_bound(b.begin(),b.end(),ll+2*l*(v1+v2))-b.begin(),b.size());
        }
        else{
            st.set(lower_bound(b.begin(),b.end(),ll)-b.begin(),lower_bound(b.begin(),b.end(),rr)-b.begin());
        }
    }
    
    for(int i=0;i<(int)(b.size()-1);++i){
        ans[st.get(i)] += b[i+1]-b[i];
    }
    li sum = 0;
    for(int i=0;i<=n;++i){
        sum+= ans[i];
        //cout<<ans[i] / LEN<<endl;
    }
    
    for(int i=0;i<=n;++i){
        printf("%.15lf\n",ans[i] /double(sum));
    }
}