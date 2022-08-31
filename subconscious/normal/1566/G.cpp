#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef pair<int,pair<int,int>> fk;
typedef vector<int> vi;
const int N=1e5+5,mod=1e9+7;
const ll inf=1e18;
int n,m,q;

struct Node{
    int p, size; fk v;
    Node *L, *R;
    Node(fk v, int p) :p(p), size(1), v(v), L(nullptr), R(nullptr){
    }
    Node(Node* h){
        *this = *h;
    }
    Node* update(){
        size = 1;
        if(L) size += L->size;
        if(R) size += R->size;
        return this;
    }
    int Lsize(){
        return L ? L->size : 0;
    }
};
fk mus(fk v){return mp(v.st,mp(v.nd.st,v.nd.nd-1));}

mt19937 rnd;

struct Treap{
    Node *root, *L, *M, *R;
    Treap(int seed = 0) : root(nullptr){
        rnd.seed(seed);
    }
    virtual void split(Node* p, fk v, Node*& L, Node*& R){
        if(not p) return L = R = nullptr, void();
        if(p->v <= v) L = p, split(p->R, v, p->R, R);
        else R = p, split(p->L, v, L, p->L);
        p->update();
    }
    virtual Node* merge(Node* L, Node* R){
        if(not L) return R;
        if(not R) return L;
        if(L->p < R->p) return L->R = merge(L->R, R), L->update();
        return R->L = merge(L, R->L), R->update();
    }
    Node* insert(Node* p, fk v){
        split(p, v, L, R);
        return merge(merge(L, new Node(v, rand())), R);
    }
    void insert(fk v){
        root = insert(root, v);
    }
    Node* remove(Node* p, fk v){
        split(p, v, L, R);
        split(L, mus(v), L, M);
        return merge(merge(L, M ? merge(M->L, M->R) : M), R);
    }
    void remove(fk v){
        root = remove(root, v);
    }
    int rank(Node* p, fk v){
        if(not p) return 1;
        if(p->v >= v) return rank(p->L, v);
        return 1 + p->Lsize() + rank(p->R, v);
    }
    int rank(fk v){
        return rank(root, v);
    }
    Node* kth(Node* p, int k){
        if(not p or k > p->size) return nullptr;
        if(k <= p->Lsize()) return kth(p->L, k);
        if(k == p->Lsize() + 1) return p;
        return kth(p->R, k - p->Lsize() - 1);
    }
    Node* kth(int k){
        return kth(root, k);
    }
    Node* pedecessor(Node* p, fk v){
        if(not p) return p;
        if(p->v >= v) return pedecessor(p->L, v);
        R = pedecessor(p->R, v);
        return R ? R : p;
    }
    Node* pedecessor(fk v){
        return pedecessor(root, v);
    }
    Node* successor(Node* p, fk v){
        if(not p) return p;
        if(p->v <= v) return successor(p->R, v);
        L = successor(p->L, v);
        return L ? L : p;
    }
    Node* successor(fk v){
        return successor(root, v);
    }
    int size(){return root->size;}
}T[N],ALL;
map<pair<int,int>,int>dic;

ll sol(){
    ll ans=inf;
    fk mi=ALL.kth(1)->v;
    //printf("v:%d\n",mi.st);
    int u=mi.nd.st,v=mi.nd.nd;
    //claw
    if(T[u].size()>=3){
        ans=min(ans,(ll)T[u].kth(1)->v.st+T[u].kth(2)->v.st+T[u].kth(3)->v.st);
        //printf("%d %d %d\n",T[u].kth(1)->v.st,T[u].kth(2)->v.st,T[u].kth(3)->v.st);
    }
    if(T[v].size()>=3){
        ans=min(ans,(ll)T[v].kth(1)->v.st+T[v].kth(2)->v.st+T[v].kth(3)->v.st);
        
        //printf("%d %d\n",T[v].kth(2)->v.nd.st,T[v].kth(2)->v.nd.nd);
        //printf("%d %d\n",T[v].kth(3)->v.nd.st,T[v].kth(3)->v.nd.nd);
    }
    //printf("ans:%lld\n",ans);
    //parallel
    if(T[u].size()>=2&&T[v].size()>=2){
        fk fw=T[u].kth(2)->v,fx=T[v].kth(2)->v;
        if(fw.nd.nd==fx.nd.nd){
            if(T[u].size()>=3){
                ans=min(ans,(ll)T[u].kth(3)->v.st+fx.st);
            }
            if(T[v].size()>=3){
                ans=min(ans,(ll)fw.st+T[v].kth(3)->v.st);
            }
        }else
            ans=min(ans,(ll)fw.st+fx.st);
    }
    //printf("ans:%lld\n",ans);
    //min
    {
        int l=0,r=ALL.size()+1;
        while(l+1<r){
            int mid=(l+r)/2;
            fk ky=mp(ALL.kth(mid)->v.st,mp(mod,mod));
            int cnt=(ALL.rank(ky)-1)-(T[u].rank(ky)-1)-(T[v].rank(ky)-1)+1;
            if(cnt>0)r=mid;else l=mid;
        }
        if(r<=ALL.size())
            ans=min(ans,(ll)mi.st+ALL.kth(r)->v.st);

    }
    return ans;
}
void add(fk v){
    ALL.insert(v);
    dic[v.nd]=v.st;
    T[v.nd.st].insert(v);

    swap(v.nd.st,v.nd.nd);
    T[v.nd.st].insert(v);
}
void del(fk v){
    ALL.remove(v);
    dic.erase(v.nd);
    T[v.nd.st].remove(v);
    
    swap(v.nd.st,v.nd.nd);
    T[v.nd.st].remove(v);
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,m){
        fk v;scanf("%d%d%d",&v.nd.st,&v.nd.nd,&v.st);
        if(v.nd.st>v.nd.nd)swap(v.nd.st,v.nd.nd);
        add(v);
    }
    scanf("%d",&q);
    printf("%lld\n",sol());
    rep(i,q){
        int opt;fk v;
        scanf("%d",&opt);
        if(opt==0){
            scanf("%d%d",&v.nd.st,&v.nd.nd);
            if(v.nd.st>v.nd.nd)swap(v.nd.st,v.nd.nd);
            v.st=dic[v.nd];
            del(v);
        }else{
            scanf("%d%d%d",&v.nd.st,&v.nd.nd,&v.st);
            if(v.nd.st>v.nd.nd)swap(v.nd.st,v.nd.nd);
            add(v);
        }
        printf("%lld\n",sol());
    }
    return 0;
}
/*
2 5 2
1 3 6
2 6 4
2 4 2
5 4 3
1 6 3
*/