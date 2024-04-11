#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

template<typename T>
class SegmentTreeBeats{
    int n;
    static const T idm=numeric_limits<T>::min();
    static const T idM=numeric_limits<T>::max(),idl=idM;
    struct Node{
        T Max,Max_second,Min,Min_second,sum,laz_add,laz_val;
        int Max_count,Min_count,len;
        Node():Max(idm),Max_second(idm),Min(idM),Min_second(idM)
            ,laz_add(0),laz_val(idl),len(1){}
    };
    vector<Node> Nodes;
    inline void calc(int k){
        Node &p=Nodes[k];
        Node l=Nodes[(k<<1)+1],r=Nodes[(k<<1)+2];
        p.sum=l.sum+r.sum;
        if (l.Max<r.Max){
            p.Max=r.Max;
            p.Max_count=r.Max_count;
            p.Max_second=max(l.Max,r.Max_second);
        } else if (r.Max<l.Max){
            p.Max=l.Max;
            p.Max_count=l.Max_count;
            p.Max_second=max(l.Max_second,r.Max);
        } else {
            p.Max=l.Max;
            p.Max_count=l.Max_count+r.Max_count;
            p.Max_second=max(l.Max_second,r.Max_second);
        }
        if (l.Min<r.Min){
            p.Min=l.Min;
            p.Min_count=l.Min_count;
            p.Min_second=min(l.Min_second,r.Min);
        } else if (r.Min<l.Min){
            p.Min=r.Min;
            p.Min_count=r.Min_count;
            p.Min_second=min(l.Min,r.Min_second);
        } else {
            p.Min=l.Min;
            p.Min_count=l.Min_count+r.Min_count;
            p.Min_second=min(l.Min_second,r.Min_second);
        }
    }
    inline void update_node_min(int k,T x){
        Node &node=Nodes[k];
        node.sum+=(x-node.Max)*node.Max_count;
        if (node.Max==node.Min) node.Max=node.Min=x;
        else if (node.Max==node.Min_second) node.Max=node.Min_second=x;
        else node.Max=x;
        if (node.laz_val!=idl&&node.laz_val<x) node.laz_val=x;
    }
    inline void update_node_max(int k,T x){
        Node &node=Nodes[k];
        node.sum+=(x-node.Min)*node.Min_count;
        if (node.Min==node.Max) node.Min=node.Max=x;
        else if (node.Min==node.Max_second) node.Min=node.Max_second=x;
        else node.Min=x;
        if (node.laz_val!=idl&&x<node.laz_val) node.laz_val=x;
    }
    inline void update_node_add(int k,T x){
        Node &node=Nodes[k];
        node.Max+=x;
        if (node.Max_second!=idm) node.Max_second+=x;
        node.Min+=x;
        if (node.Min_second!=idM) node.Min_second+=x;
        node.sum+=x*node.len;
        (node.laz_val!=idl?node.laz_val:node.laz_add)+=x;
    }
    inline void update_node_val(int k,T x){
        Node &node=Nodes[k];
        node.Max=x; node.Max_second=idm;
        node.Min=x; node.Min_second=idM;
        node.Max_count=node.Min_count=node.len;
        node.sum=x*node.len;
        node.laz_val=x; node.laz_add=0;
    }
    inline void propagate(int k){
        if (k>=n-1) return;
        Node &node=Nodes[k];
        if (node.laz_val!=idl){
            update_node_val((k<<1)+1,node.laz_val);
            update_node_val((k<<1)+2,node.laz_val);
            node.laz_val=idl; return;
        }
        if (node.laz_add!=0){
            update_node_add((k<<1)+1,node.laz_add);
            update_node_add((k<<1)+2,node.laz_add);
            node.laz_add=0;
        }
        if (node.Max<Nodes[(k<<1)+1].Max) update_node_min((k<<1)+1,node.Max);
        if (node.Max<Nodes[(k<<1)+2].Max) update_node_min((k<<1)+2,node.Max);
        if (Nodes[(k<<1)+1].Min<node.Min) update_node_max((k<<1)+1,node.Min);
        if (Nodes[(k<<1)+2].Min<node.Min) update_node_max((k<<1)+2,node.Min);
    }
    inline void update_min(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a||Nodes[k].Max<=x) return;
        if (a<=l&&r<=b&&Nodes[k].Max_second<x){
            update_node_min(k,x); return;
        }
        propagate(k);
        update_min(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_min(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_max(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a||x<=Nodes[k].Min) return;
        if (a<=l&&r<=b&&x<Nodes[k].Min_second){
            update_node_max(k,x); return;
        }
        propagate(k);
        update_max(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_max(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_add(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a) return;
        if (a<=l&&r<=b){
            update_node_add(k,x); return;
        }
        propagate(k);
        update_add(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_add(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_val(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a) return;
        if (a<=l&&r<=b){
            update_node_val(k,x); return;
        }
        propagate(k);
        update_val(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_val(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline T query_min(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return idM;
        if (a<=l&&r<=b) return Nodes[k].Min;
        propagate(k);
        T vl=query_min(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_min(a,b,(k<<1)+2,(l+r)>>1,r);
        return min(vl,vr);
    }
    inline T query_max(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return idm;
        if (a<=l&&r<=b) return Nodes[k].Max;
        propagate(k);
        T vl=query_max(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_max(a,b,(k<<1)+2,(l+r)>>1,r);
        return max(vl,vr);
    }
    inline T query_sum(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return 0;
        if (a<=l&&r<=b) return Nodes[k].sum;
        propagate(k);
        T vl=query_sum(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_sum(a,b,(k<<1)+2,(l+r)>>1,r);
        return vl+vr;
    }
    public:
    SegmentTreeBeats(int n_){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        Nodes.resize(n<<1);
    }
    void build(const vector<T> &v){
        for (int i=0;i<v.size();++i){
            Nodes[i+n-1].Max=Nodes[i+n-1].Min=Nodes[i+n-1].sum=v[i];
            Nodes[i+n-1].Max_count=Nodes[i+n-1].Min_count=Nodes[i+n-1].len=1;
        }
        for (int i=n-2;i>=0;--i){
            calc(i);
            Nodes[i].len=Nodes[(i<<1)+1].len+Nodes[(i<<1)+2].len;
        }
    }
    void update_min(int a,int b,T x){update_min(a,b,x,0,0,n);}
    void update_max(int a,int b,T x){update_max(a,b,x,0,0,n);}
    void update_add(int a,int b,T x){update_add(a,b,x,0,0,n);}
    void update_val(int a,int b,T x){update_val(a,b,x,0,0,n);}
    T query_min(int a,int b){return query_min(a,b,0,0,n);}
    T query_max(int a,int b){return query_max(a,b,0,0,n);}
    T query_sum(int a,int b){return query_sum(a,b,0,0,n);}
    T operator[](int i){return query_sum(i,i+1);}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;

    SegmentTreeBeats<int> seg(n);
    seg.build(a);
    int q; cin >> q;
    for (;q--;){
        int t,p,x; cin >> t;
        if (t==1){
            cin >> p >> x; --p;
            seg.update_val(p,p+1,x);
        } else {
            cin >> x;
            seg.update_max(0,n,x);
        }
    }

    for (int i=0;i<n;++i) cout << seg[i] << (i+1==n?'\n':' ');
}