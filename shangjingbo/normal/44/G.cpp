#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
//=============================================================================================

#define maxn 100005
#define maxm 100005

struct Treap
{
    int y,id,min;
    int miny,maxy;
    int aux;
    Treap *left,*right;
};
typedef Treap *Tnode;

Tnode nilpoint;

inline void renew(Tnode &root)
{
    root->min=min(root->left->min,root->right->min);
    root->min=min(root->min,root->id);
    root->miny=min(root->left->miny,root->y);
    root->maxy=max(root->right->maxy,root->y);
}

inline void LeftRotate(Tnode &root)
{
    Tnode t=root->left;
    root->left=t->right;
    t->right=root;
    renew(root);
    renew(t);
    root=t;
}

inline void RightRotate(Tnode &root)
{
    Tnode t=root->right;
    root->right=t->left;
    t->left=root;
    renew(root);
    renew(t);
    root=t;
}

Treap bakTreap[2000000];
int tot=0;

inline void Insert(Tnode &root,int y,int id)
{
    if (root==nilpoint)
    {
        root=&bakTreap[tot++];
        root->left=root->right=nilpoint;
        root->aux=((rand()<<15)+rand())%1000000000;
        root->id=root->min=id;
        root->y=y;
        root->miny=root->maxy=y;
        return;
    }
    
    if (y<root->y || y==root->y && id<root->id)
    {
        Insert(root->left,y,id);
        if (root->left->aux<root->aux) LeftRotate(root);
    }else
    {
        Insert(root->right,y,id);
        if (root->right->aux<root->aux) RightRotate(root);
    }
    
    renew(root);
}

inline void Delete(Tnode &root,int y,int id)
{
    if (root->y==y && root->id==id)
    {
        if (root->left==nilpoint && root->right==nilpoint)
        {
            root=nilpoint;
            return;
        }
        
        if (root->left->aux<root->right->aux)
        {
            LeftRotate(root);
            Delete(root->right,y,id);
        }else
        {
            RightRotate(root);
            Delete(root->left,y,id);
        }
        renew(root);
        return;
    }
    if (y<root->y || y==root->y && id<root->id) Delete(root->left,y,id);
    else Delete(root->right,y,id);
    renew(root);
}

inline int Query(Tnode &root,int yl,int yr)
{
    if (root==nilpoint || root->miny>yr || root->maxy<yl) return -1;
    if (yl<=root->miny && root->maxy<=yr) return root->min;
    if (yr<root->y) return Query(root->left,yl,yr);
    if (yl>root->y) return Query(root->right,yl,yr);
    int t=-1;
    if (yl<=root->y && root->y<=yr) t=root->id;
    int t1=Query(root->left,yl,yr);
    if (t1!=-1 && (t==-1 || t>t1)) t=t1;
    t1=Query(root->right,yl,yr);
    if (t1!=-1 && (t==-1 || t>t1)) t=t1;
    return t;
}

struct node
{
    int xl,xr,yl,yr,z,id;
    inline void read()
    {
        scanf("%d%d%d%d%d",&xl,&xr,&yl,&yr,&z);
    }
}rec[maxn];

struct Tshoot
{
    int x,y;
}shoot[maxm];

#define maxN (maxn*2+maxm)

Tnode Tree[maxN*4];

inline void Build(int num,int l,int r)
{
    Tree[num]=nilpoint;
    if (l==r) return;
    int mid=(l+r)/2;
    Build(num*2,l,mid);
    Build(num*2+1,mid+1,r);
}

inline void Insert(int num,int l,int r,int x,int y,int id)
{
    //printf("  %d %d %d-->%d\n",l,r,y,id);
    Insert(Tree[num],y,id);
    if (l==r) return;
    int mid=(l+r)/2;
    if (x<=mid) Insert(num*2,l,mid,x,y,id);
    else Insert(num*2+1,mid+1,r,x,y,id);
}

inline void Delete(int num,int l,int r,int x,int y,int id)
{
    Delete(Tree[num],y,id);
    if (l==r) return;
    int mid=(l+r)/2;
    if (x<=mid) Delete(num*2,l,mid,x,y,id);
    else Delete(num*2+1,mid+1,r,x,y,id);
}

inline int Query(int num,int l,int r,int ll,int rr,int yl,int yr)
{
    if (l==ll && r==rr)
    {
        //printf("ing: %d %d %d %d\n",l,r,yl,yr);
        //printf("hu: %d\n",Query(Tree[num],yl,yr));
        return Query(Tree[num],yl,yr);
    }
    int mid=(l+r)/2;
    if (rr<=mid) return Query(num*2,l,mid,ll,rr,yl,yr);
    if (ll>mid) return Query(num*2+1,mid+1,r,ll,rr,yl,yr);
    int t1=Query(num*2,l,mid,ll,mid,yl,yr);
    int t2=Query(num*2+1,mid+1,r,mid+1,rr,yl,yr);
    if (t1==-1) return t2;
    if (t2==-1) return t1;
    return min(t1,t2);
}

int n,bak[maxN],m,Ans[maxm];

inline bool cmpz(const node &a,const node &b)
{
    return a.z<b.z;
}

int main()
{
    nilpoint=new Treap;
    nilpoint->left=nilpoint->right=nilpoint;
    nilpoint->aux=nilpoint->id=nilpoint->min=1000000000;
    nilpoint->miny=1000000000;
    nilpoint->maxy=-1000000000;
    
    scanf("%d",&n);
    int N=0;
    for (int i=0;i<n;++i)
    {
        rec[i].read();
        rec[i].id=i;
        bak[N++]=rec[i].xl;
        bak[N++]=rec[i].xr;
    }
    
    scanf("%d",&m);
    for (int i=0;i<m;++i)
    {
        scanf("%d%d",&shoot[i].x,&shoot[i].y);
        bak[N++]=shoot[i].x;
    }
    
    sort(bak,bak+N);
    N=unique(bak,bak+N)-bak;
    
    Build(1,0,N-1);
    
    for (int i=0;i<m;++i)
    {
        Insert(1,0,N-1,lower_bound(bak,bak+N,shoot[i].x)-bak,shoot[i].y,i);
        //printf("Insert: %d %d-->%d\n",lower_bound(bak,bak+N,shoot[i].x)-bak,shoot[i].y,i);
    }
    
    sort(rec,rec+n,cmpz);
    
    memset(Ans,0,sizeof(Ans));
    for (int i=0;i<n;++i)
    {
        int x=Query(1,0,N-1,lower_bound(bak,bak+N,rec[i].xl)-bak,lower_bound(bak,bak+N,rec[i].xr)-bak,rec[i].yl,rec[i].yr);
        //printf("Query: %d %d %d %d\n",lower_bound(bak,bak+N,rec[i].xl)-bak,lower_bound(bak,bak+N,rec[i].xr)-bak,rec[i].yl,rec[i].yr);
        if (x!=-1)
        {
            Ans[x]=rec[i].id+1;
            Delete(1,0,N-1,lower_bound(bak,bak+N,shoot[x].x)-bak,shoot[x].y,x);
        }
    }
    
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    
    for (int i=0;i<m;++i)
        printf("%d\n",Ans[i]);  
    
    return 0;
}