#include <bits/stdc++.h>
using namespace std;

//Start
typedef long long ll;
typedef double db;
#define mp(a,b) make_pair((a),(b))
#define x first
#define y second
#define bg begin()
#define ed end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define R(i,a,b) for(int i=(a),i##E=(b);i<i##E;i++)
#define L(i,a,b) for(int i=(b)-1,i##E=(a)-1;i>i##E;i--)
const int iinf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

//FhqTreap
struct fhqTreap{
    int n,rt;
    vector<int> ls,rs,p,fa,tag,val;
    fhqTreap(int n):n(n){
        rt=-1,ls.assign(n,-1),rs.assign(n,-1);
        fa.assign(n,-1),tag.assign(n,0),val.resize(n);
        R(i,0,n) p.pb(rand()^114514);
    }
    void pushup(int u){
        if(~ls[u]) fa[ls[u]]=u;
        if(~rs[u]) fa[rs[u]]=u;
    }
    void pushtag(int u,int v){val[u]+=v,tag[u]+=v;}
    void pushdown(int u){
        if(tag[u]){
            if(~ls[u]) pushtag(ls[u],tag[u]);
            if(~rs[u]) pushtag(rs[u],tag[u]);
            tag[u]=0;
        }
    }
    int merge(int u,int v){
        if(!~u||!~v) return u+v-(-1);
        if(p[u]<p[v]) return pushdown(u),rs[u]=merge(rs[u],v),pushup(u),u;
        else return pushdown(v),ls[v]=merge(u,ls[v]),pushup(v),v;
    }
    void split(int o,int k,int&u,int&v){
        if(!~o) return u=v=-1,void();
        pushdown(o);
        if(k<=val[o]) v=o,split(ls[o],k,u,ls[o]),fa[u]=-1;
        else u=o,split(rs[o],k,rs[o],v),fa[v]=-1;
        pushup(o);
    }
    void refresh(int u){
        // cout<<u<<'\n';
        if(~fa[u]) refresh(fa[u]);pushdown(u);
    }
    void print(int u){
        if(!~u) return;
        pushdown(u);
        print(ls[u]);
        cout<<u<<":"<<val[u]<<" "<<fa[u]<<'\n';
        print(rs[u]);
    }
};

//Main
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    int n; string s; cin>>n>>s;
    vector<int> a[26],b[26];
    R(i,0,n) a[s[i]-'a'].pb(i),b[s[i]-'a'].pb(n-1-i);
    R(c,0,26) reverse(b[c].bg,b[c].ed);
    fhqTreap bst(n); int l,m,r;
    R(c,0,26)R(i,0,sz(a[c])) bst.val[b[c][i]]=a[c][i];
    // R(i,0,n) cout<<bst.val[i]<<" ";cout<<'\n';
    R(i,0,n){
        bst.split(bst.rt,bst.val[i],l,r);
        bst.rt=bst.merge(bst.merge(l,i),r);
        // bst.print(bst.rt);
        // cout<<'\n';
    }
    // cout<<"okyet\n";
    ll ans=0;
    L(i,0,n){
        // cout<<"zkyzdw\n";
        bst.refresh(i); int t=bst.val[i];
        // cout<<"i="<<i<<" t="<<t<<'\n';
        if(t==i) continue; ans+=i-t;
        // cout<<"zky\n";
        bst.split(bst.rt,t+1,l,r),bst.split(l,t,l,m);
        // cout<<"fuck?fuck.\n";
        bst.val[i]=i,bst.rt=bst.merge(l,r);
        // cout<<"(\n";
        bst.split(bst.rt,i+1,l,r),bst.split(l,t+1,l,m);
        if(~m) bst.pushtag(m,-1);
        bst.rt=bst.merge(bst.merge(l,bst.merge(m,i)),r);  
        // cout<<"^\n";
        // cout<<bst.rt<<'\n';
        // cout<<"zkyakioi\n";
    }
    cout<<ans<<'\n';
    exit(0);
}