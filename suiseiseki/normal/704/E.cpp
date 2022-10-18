#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000,Maxq=100000,Maxs=3200000;
struct Frac{
    ll x,y;
    Frac(ll _x=0,ll _y=1){
        x=_x,y=_y;
        if(y<0){
            x=-x;
            y=-y;
        }
    }
    friend bool operator <(Frac a,Frac b){
        return a.x*b.y<a.y*b.x;
    }
    friend bool operator >(Frac a,Frac b){
        return a.x*b.y>a.y*b.x;
    }
    friend bool operator ==(Frac a,Frac b){
        return a.x*b.y==a.y*b.x;
    }
    friend Frac operator *(Frac a,Frac b){
        return Frac(a.x*b.x,a.y*b.y);
    }
    friend Frac operator +(Frac a,Frac b){
        if(a.y==b.y){
            return Frac(a.x+b.x,a.y);
        }
        return Frac(a.x*b.y+a.y*b.x,a.y*b.y);
    }
};
int n,q;
int q_u[Maxq+5],q_v[Maxq+5],q_t[Maxq+5],q_c[Maxq+5];
std::vector<int> g[Maxn+5];
int fa[Maxn+5],dep[Maxn+5],sz[Maxn+5],son[Maxn+5],top[Maxn+5];
void init_dfs_1(int u){
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for(int i=0;i<(int)g[u].size();i++){
        int v=g[u][i];
        if(v==fa[u]){
            continue;
        }
        fa[v]=u;
        init_dfs_1(v);
        sz[u]+=sz[v];
        if(son[u]==0||sz[son[u]]<sz[v]){
            son[u]=v;
        }
    }
}
void init_dfs_2(int u,int tp){
    top[u]=tp;
    if(son[u]){
        init_dfs_2(son[u],tp);
    }
    for(int i=0;i<(int)g[u].size();i++){
        int v=g[u][i];
        if(v==fa[u]||v==son[u]){
            continue;
        }
        init_dfs_2(v,v);
    }
}
Frac q_l[Maxs+5],q_r[Maxs+5];
int q_k[Maxs+5],q_b[Maxs+5],cnt;
std::vector<int> V[Maxn+5];
int find_dis(int u,int v){
    int ans=dep[u]+dep[v];
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            std::swap(u,v);
        }
        u=fa[top[u]];
    }
    return ans-(std::min(dep[u],dep[v])<<1);
}
void add(int u,int v,int t,int c){
    int dis=find_dis(u,v),d_u=0,d_v=dis;
    t*=c;
    while(top[u]!=top[v]){
        cnt++;
        if(dep[top[u]]>dep[top[v]]){
            q_l[cnt]=Frac(t+d_u,c);
            d_u+=dep[u]-dep[top[u]]+1;
            q_r[cnt]=Frac(t+d_u,c);
            q_k[cnt]=-c;
            q_b[cnt]=d_u+t;
            V[top[u]].push_back(-cnt);
            V[top[u]].push_back(cnt);
            u=fa[top[u]];
        }
        else{
            q_r[cnt]=Frac(t+d_v,c);
            d_v-=dep[v]-dep[top[v]]+1;
            q_l[cnt]=Frac(t+d_v,c);
            q_k[cnt]=c;
            q_b[cnt]=-(d_v+t);
            V[top[v]].push_back(-cnt);
            V[top[v]].push_back(cnt);
            v=fa[top[v]];
        }
    }
    cnt++;
    q_l[cnt]=Frac(t+d_u,c);
    q_r[cnt]=Frac(t+d_v,c);
    if(dep[u]<dep[v]){
        q_k[cnt]=c;
        q_b[cnt]=dep[u]-dep[top[u]]+1-d_u-t;
    }
    else{
        q_k[cnt]=-c;
        q_b[cnt]=dep[u]-dep[top[u]]+1+d_u+t;
    }
    V[top[u]].push_back(-cnt);
    V[top[u]].push_back(cnt);
}
double ans;
Frac tmp;
struct Cmp{
    bool operator ()(int x,int y){
        Frac tmp_x=q_k[x]*tmp+q_b[x],tmp_y=q_k[y]*tmp+q_b[y];
        if(tmp_x==tmp_y){
            return x<y;
        }
        return tmp_x<tmp_y;
    }
};
std::set<int,Cmp> st;
bool cmp(int x,int y){
    Frac tmp_x=x<0?q_l[-x]:q_r[x],tmp_y=y<0?q_l[-y]:q_r[y];
    if(tmp_x==tmp_y){
        return x<y;
    }
    return tmp_x<tmp_y;
}
void check(int x,int y,int &pos,Frac &now){
    Frac val_l=std::max(q_l[x],q_l[y]),val_r=std::min(q_r[x],q_r[y]);
    if(q_k[x]==q_k[y]){
        if(q_b[x]!=q_b[y]){
            return;
        }
        if(pos==0){
            pos=1;
            now=val_l;
        }
        else{
            now=std::min(now,val_l);
        }
    }
    else{
        Frac now_ans=Frac(q_b[x]-q_b[y],q_k[y]-q_k[x]);
        if(now_ans<val_l||val_r<now_ans){
            return;
        }
        if(pos==0){
            pos=1;
            now=now_ans;
        }
        else{
            now=std::min(now,now_ans);
        }
    }
}
void solve(int u){
    std::sort(V[u].begin(),V[u].end(),cmp);
    st.clear();
    int pos=0;
    Frac now;
    for(int i=0;i<(int)V[u].size();i++){
        int id=V[u][i];
        tmp=id<0?q_l[-id]:q_r[id];
        if(pos>0&&!(tmp<now)){
            break;
        }
        if(id<0){
            id=-id;
            std::set<int>::iterator it=st.insert(id).first;
            std::set<int>::iterator lst=it,nxt=it;
            if(lst==st.begin()){
                lst=st.end();
            }
            else{
                lst--;
            }
            nxt++;
            if(lst!=st.end()){
                check(id,*lst,pos,now);
            }
            if(nxt!=st.end()){
                check(id,*nxt,pos,now);
            }
        }
        else{
            st.erase(st.lower_bound(id));
            std::set<int>::iterator it=st.lower_bound(id);
            if(it==st.end()||it==st.begin()){
                continue;
            }
            std::set<int>::iterator it_2;
            it_2=it;
            it_2--;
            check(*it,*it_2,pos,now);
        }
    }
    if(pos){
        ans=std::min(ans,now.x/(double)now.y);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    ans=1e99;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init_dfs_1(1);
    init_dfs_2(1,1);
    for(int i=1;i<=q;i++){
        scanf("%d%d%d%d",&q_t[i],&q_c[i],&q_u[i],&q_v[i]);
        add(q_u[i],q_v[i],q_t[i],q_c[i]);
    }
    for(int i=1;i<=n;i++){
        if(i==top[i]){
            solve(i);
        }
    }
    if(ans>1e98){
        puts("-1");
    }
    else{
        printf("%.10lf\n",ans);
    }
    return 0;
}