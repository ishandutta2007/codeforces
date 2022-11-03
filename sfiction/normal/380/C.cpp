/*
ID: Sfiction
OJ: CF
PROB: 380C
*/
#include <cstdio>

struct node{
    int left,right,ans;
};

const int MAXN=1000000+5;

char s[MAXN];
int len;

node f[MAXN<<2];

void Up(node &a,node &b,node &c){
    int t;
    if (b.left<c.right)
        t=b.left;
    else
        t=c.right;
    a.left=b.left+c.left-t;
    a.right=b.right+c.right-t;
    a.ans=b.ans+c.ans+t;
}

void Build(int l,int r,int now){
    if (l==r){
        if (s[l-1]=='(')
            f[now].left=1;
        else
            f[now].right=1;
        return;
    }
    int mid=(l+r)>>1;
    if (l<=mid)
        Build(l,mid,now<<1);
    if (mid<r)
        Build(mid+1,r,now<<1|1);
    Up(f[now],f[now<<1],f[now<<1|1]);
}

node Sum(int a,int b,int l,int r,int now){
    if (a<=l && r<=b)
        return f[now];
    int mid=(l+r)>>1;
    node tempb,tempc;
    node tempa;
    tempb.left=tempb.right=tempb.ans=0;
    tempc.left=tempc.right=tempc.ans=0;
    if (a<=mid)
        tempb=Sum(a,b,l,mid,now<<1);
    if (mid<b)
        tempc=Sum(a,b,mid+1,r,now<<1|1);
    Up(tempa,tempb,tempc);
    return tempa;
}

int main(){
    int m,a,b;
    node t;
    scanf("%s",s);
    for (len=0;s[len];++len);
    Build(1,len,1);
    scanf("%d",&m);
    for (;m;--m){
        scanf("%d%d",&a,&b);
        t=Sum(a,b,1,len,1);
        printf("%d\n",t.ans<<1);
    }
    return 0;
}