#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 16e6 + 11;


map<string,int> mt;
int l1[N],r1[N],s1[N],root1[N],kk1,root1_;
int l2[N],r2[N],aa[N],root2[N],kk2,root2_;


void update1(int i, int ii, int l, int r, int d, int x)
{
    if (l==r) {s1[ii]+=s1[i]+x;  return;}
    int mid=(l+r)/2;
    if (d<=mid)
    {
        if (!l1[i])
        {
            kk1++;
            l1[i]=kk1;
        }
        kk1++;
        l1[ii]=kk1;
        r1[ii]=r1[i];
        update1(l1[i],kk1,l,mid,d,x);
        s1[ii]=s1[l1[ii]]+s1[r1[ii]];
    } else
    {
        if (!r1[i])
        {
            kk1++;
            r1[i]=kk1;
        }
        kk1++;
        l1[ii]=l1[i];
        r1[ii]=kk1;
        update1(r1[i],kk1,mid+1,r,d,x);
        s1[ii]=s1[l1[ii]]+s1[r1[ii]];
    }
}

int sum(int i, int l, int r, int tl, int tr)
{
    if (tl>r||l>tr) return 0;
    if (tl<=l&&r<=tr) return s1[i];
    int mid=(l+r)/2;
    int ss=0;
    if (l1[i]) ss+=sum(l1[i],l,mid,tl,tr);
    if (r1[i]) ss+=sum(r1[i],mid+1,r,tl,tr);
    return ss;
}



void update2(int i, int ii, int l, int r, int d, int x)
{
    if (l==r) { aa[ii]=x; return;}
    int mid=(l+r)/2;
    if (d<=mid)
    {
        kk2++;
        l2[ii]=kk2;
        r2[ii]=r2[i];
        update2(l2[i],kk2,l,mid,d,x);
    } else
    {
        kk2++;
        l2[ii]=l2[i];
        r2[ii]=kk2;
        update2(r2[i],kk2,mid+1,r,d,x);
    }
}

int get(int i, int l, int r, int x)
{
    if (l==r) {return aa[i];}
    int mid=(l+r)/2;
    if (x<=mid) return get(l2[i],l,mid,x); else
        return get(r2[i],mid+1,r,x);
}
/**
100
query moygtdgjk
remove kshxum
undo 0
query mpsif
undo 1
undo 0
query mpsif
undo 0
set moygtdgjk 557168916
remove mpsif
undo 0
query moygtdgjk
**/
int q,dd,xx,kol;

void set_(string s, int r)
{
    int num=mt[s];
    if (num==0) {kol++; mt[s]=kol; num=kol;}
    int d=get(root2_,1,q,num);
    kk1++;
    int x=kk1;
    update1(root1_,x,0,xx,d,-1);
    kk1++;
    int y=kk1;
    update1(x,kk1,0,xx,r,1);
    root1[dd]=y;
    root1_=y;
    kk2++;
    x=kk2;
    update2(root2_,x,1,q,num,r);
    root2_=x;
    root2[dd]=x;
}
void remove_(string s)
{
    int num=mt[s];
    if (num==0) {root2[dd]=root2_; root1[dd]=root1_; return;}
    int d=get(root2_,1,q,num);
    kk1++;
    int x=kk1;
    update1(root1_,x,0,xx,d,-1);
    root1[dd]=x;
    root1_=x;
    kk2++;
    x=kk2;

    update2(root2_,x,1,q,num,0);
    root2_=x;
    root2[dd]=x;
}
int query(string s)
{
    root1[dd]=root1_;
    root2[dd]=root2_;

    int num=mt[s];
    if (num==0) return -1;
    int x=get(root2_,1,q,num);
    if (x==0) return -1;
    return sum(root1_,0,xx,1,x-1);
}
void undo(int l)
{
    //cout<<dd-l-1<<" "<<root1[dd-l-1]<<endl;
    root1_=root1[dd-l-1];
    root2_=root2[dd-l-1];
    root1[dd]=root1_;
    root2[dd]=root2_;
}
void build2(int i, int l, int r)
{
    if (l==r) return;
    kk2++;
    l2[i]=kk1;
    int mid=(l+r)/2;
    build2(kk2,l,mid);
    kk2++;
    r2[i]=kk2;
    build2(kk2,mid+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>q;
    xx=1e9;
    root1_=1;
    root2_=1;
    root1[0]=1;
    kk1=1;
    kk2=1;
    root2[0]=1;
    build2(1,1,q);
    for (int i=1; i<=q; i++)
    {
        string s;
        cin>>s;
        dd=i;
        if (s=="set")
        {
            string a;
            int b;
            cin>>a>>b;
            set_(a,b);
        } else
        if (s=="remove")
        {
            string a;
            cin>>a;
            remove_(a);
        } else
        if (s=="query")
        {
            string s;
            cin>>s;
            cout<<query(s)<<endl;
        } else
        {
            int l;
            cin>>l;
            undo(l);
        }
        //cout<<"! "<<root1_<<" "<<root2_<<" "<<root1[dd]<<" "<<root2[dd]<<endl;
    }
}