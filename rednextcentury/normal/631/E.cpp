#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
struct LiChaoTree
{
    typedef long long ftype;
    #define MX 1e18
    #define MAX_QUERY 1e6
    #define MIN_QUERY -1e6
    struct Line
    {
        ftype m,c;
        Line(ftype M,ftype C)
        {
            m=M;
            c=C;
        }
        Line() {};
    };
    ftype f(Line l,  ftype x)
    {
        return l.m*x+l.c;
    }
    struct node
    {
        Line line;
        node* L = NULL;
        node* R = NULL;
        node() {}
        node(Line l)
        {
            line = l;
        }
    };
    node *root = NULL;
    void init()
    {
        if (root!=NULL)
            clr(root);
        root=NULL;
    }
    void clr(node* &v)
    {
        if (v->L != NULL)
            clr(v->L);
        if (v->R != NULL)
            clr(v->R);
        delete(v);
    }
    void Insert(Line nw, node* &v, ftype l=MIN_QUERY, ftype r=MAX_QUERY)
    {
        if (v==NULL)
        {
            v = new node(nw);
            return;
        }
        ftype mid = l+(r-l)/2;
        bool LEFT = f(nw, l) < f(v->line, l);
        bool MID = f(nw, mid) < f(v->line, mid);
        bool RIGHT = f(nw, r) < f(v->line, r);
        if (LEFT && RIGHT)
            v->line = nw;
        if (LEFT == RIGHT)
            return;
        if(LEFT!=MID)
        {
            if (RIGHT)
                swap(v->line,nw);
            Insert(nw, v->L, l, mid);
        }
        else
        {
            if (LEFT)
                swap(v->line,nw);
            Insert(nw, v->R, mid+1, r);
        }
    }
    ftype Get(ftype x, node *v, ftype l=MIN_QUERY, ftype r=MAX_QUERY)
    {
        if (v==NULL)
            return MX;
        ftype mid = l + (r-l)/2;
        if(x <= mid)
            return min(f(v->line, x), Get(x, v->L, l, mid));
        else
            return min(f(v->line, x), Get(x, v->R, mid+1, r));
    }

    void add_line(ftype m,ftype c)
    {
        Insert(Line(m,c),root);
    }
    ftype query(ftype x)
    {
        return Get(x,root);
    }
};
ll n;
ll  a[2000005];
ll pre[2000005];
int main()
{
    LiChaoTree T;
    cin>>n;
    ll sum = 0;
    for(ll i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        pre[i]+=pre[i-1];
        pre[i]+=a[i];
        sum+=i*a[i];
    }
    ll mx = 0;
    T.add_line(-1,pre[0]);
    for(ll i=1; i<=n; i++)
    {
        ll z = pre[i-1]-i*a[i];
        ll q = -T.query(a[i]);
        if(i > 1)
            mx = max(mx,z+q);
        T.add_line(-i,pre[i-1]);
    }
    LiChaoTree T2;
    T2.add_line(-n,+pre[n]);
    for(ll i=n-1; i>=1; i--)
    {
        ll z = pre[i]-i*a[i];
        ll q = -T2.query(a[i]);
        mx = max(mx,z+q);
        T2.add_line(-i,+pre[i]);
    }

    cout<<sum+mx<<endl;
}