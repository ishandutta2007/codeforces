
#include<bits/stdc++.h>
#define S_IT set<Node>::iterator
#define int long long
#define mp make_pair
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;
int pow(int a,int b,int Mod)
{
    int ret=1;
    int tmp=a%Mod;
    while (b)
    {
        if (b&1) ret=ret*tmp%Mod;
        tmp=tmp*tmp%Mod;
        b>>=1;
    }
    return ret;
}
struct Node
{
    int l,r;
    mutable int num;
    Node (int L,int R=-1,int NUM=0):l(L),r(R),num(NUM){}//make_pair
    bool operator<(const Node& o) const 
    {
        return l<o.l;
    }
};
set<Node> s;
S_IT split(int pos)
{
    S_IT it=s.lower_bound(Node(pos));
    if (it!=s.end() && it->l==pos) return it;
    --it;
    int L=it->l;
    int R=it->r;
    int NUM=it->num;
    s.erase(it);
    s.insert(Node(L,pos-1,NUM));
    return s.insert(Node(pos,R,NUM)).first;
}
void assign(int l,int r,int val)
{
    S_IT itl=split(l);
    S_IT itr=split(r+1);
    s.erase(itl,itr);
    s.insert(Node(l,r,val));
}
void add(int l,int r,int val)
{
    S_IT itl=split(l);
    S_IT itr=split(r+1);
    for (;itl!=itr;++itl) itl->num +=val;
}
int kth(int l,int r,int k)
{
    vector<pair<int,int> > vec;
    //
    S_IT itl=split(l);
    S_IT itr=split(r+1);
    vec.clear();
    for (;itl!=itr;++itl) vec.push_back(mp(itl->num,itl->r -itl->l +1));
    sort(vec.begin(),vec.end());
    for (vector<pair<int,int> >::iterator it=vec.begin();it!=vec.end();it++)
    {
        k -= it->second;
        if (k<=0) return it->first;
    }
    return -1LL;
}
int sum(int l,int r,int ex,int Mod)
{
    S_IT itl=split(l);
    S_IT itr=split(r+1);
    int ret=0;
    for (;itl!=itr;++itl)
    	ret=(ret+(itl->r - itl->l +1)*pow(itl->num,ex,Mod))%Mod;
    return ret;
}
int n,m,seed,vmax;
int a[N];
int rnd()
{
    int ret=seed;
    seed=(seed*7+13)%mod;
    return ret;
}

signed main()
{
    cin>>n>>m>>seed>>vmax;
    for (int i=1;i<=n;i++)
    {
        a[i]=(rnd()%vmax)+1;
        s.insert(Node(i,i,a[i]));
    }
    s.insert(Node(n+1,n+1,0));
    int lines=0;
    for (int i=1;i<=m;i++)
    {
        int op=rnd()%4+1;
        int l=rnd()%n+1;
        int r=rnd()%n+1;
        if (l>r) swap(l,r);
        int x,y;
        if (op==3) x=rnd()%(r-l+1)+1;
        else x=rnd()%vmax+1;
        if (op==4) y=rnd()%vmax+1;
        if (op==1) add(l,r,x);
        if (op==2) assign(l,r,x);
        if (op==3) cout<<kth(l,r,x)<<endl;
        if (op==4) cout<<sum(l,r,x,y)<<endl;
    }
}