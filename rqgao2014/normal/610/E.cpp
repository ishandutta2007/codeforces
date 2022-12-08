#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct tree
{char c,tag;
 int w,s,flag;
};
struct tree t[800010];

int n,m,k,x,y,z,ans;
int b[1010];
char a[200010],c[11],c1[2];

void build(int p,int l,int r)
{if(l==r)
 {  t[p].c=a[l];
    if(l<n) 
    {   t[p].w=(a[l]-96)*27+a[l+1]-96;
        b[t[p].w]++;
        t[p].s=1;
    }
    return;
 }
 build(p*2,l,(l+r)/2);
 build(p*2+1,(l+r)/2+1,r);
 t[p].s=t[p*2].s+t[p*2+1].s;
}

void push_down(int p)
{if(t[p].tag>=97 && t[p].tag<=122)
 {  t[p*2].tag=t[p].tag;
    t[p*2].c=t[p].tag;
    t[p*2+1].tag=t[p].tag;
    t[p*2+1].c=t[p].tag;
    t[p].tag='0';
 }
 if(t[p].flag)
 {  t[p].flag=0;
    t[p*2].flag=1;
    t[p*2].s=0;
    t[p*2].w=0;
    t[p*2+1].flag=1;
    t[p*2+1].s=0;
    t[p*2+1].w=0;
 }
}

void change_c(int p,int l,int r)
{if(l>y || r<x) return;
 if(l>=x && r<=y)
 {  t[p].tag=c[0];
    t[p].c=c[0];
    return;
 }
 push_down(p);
 change_c(p*2,l,(l+r)/2);
 change_c(p*2+1,(l+r)/2+1,r);
 //update(p);
 t[p].s=t[p*2].s+t[p*2+1].s;
}

void work(int p,int l,int r)
{//cout<<p<<" "<<l<<" "<<r<<endl;
 if(t[p].flag || t[p].s==0) return;
 if(l==r)
 {  b[t[p].w]--;
    t[p].s=0;
    t[p].w=0;
    t[p].flag=1;
    return;
 }
 push_down(p);
 work(p*2,l,(l+r)/2);
 work(p*2+1,(l+r)/2+1,r);
 t[p].flag=1;
 t[p].s=0;
 t[p].w=0;
}

void change_t(int p,int l,int r)
{if(l>y || r<x) return;
 if(l>=x && r<=y)
 {  //t[p].flag=1;
    //t[p].s=0;
    //cout<<p<<" "<<l<<" "<<r<<" "<<t[p].flag<<" "<<t[p].s<<endl;
    work(p,l,r);
    t[p].flag=1;
    t[p].s=0;
    return;
 }
 push_down(p);
 change_t(p*2,l,(l+r)/2);
 change_t(p*2+1,(l+r)/2+1,r);
 //update(p);
 t[p].s=t[p*2].s+t[p*2+1].s;
}

void change_p(int p,int l,int r)
{if(l==r)
 {  t[p].s=1;
    t[p].flag=0;
    t[p].w=z;
    return;
 }
 push_down(p);
 if(x<=(l+r)/2)
    change_p(p*2,l,(l+r)/2);
 else
    change_p(p*2+1,(l+r)/2+1,r);
 t[p].s=t[p*2].s+t[p*2+1].s;    
}

char query(int p,int l,int r)
{if(l==r) return t[p].c;
 push_down(p);
 if(x<=(l+r)/2)
    return query(p*2,l,(l+r)/2);
 else
    return query(p*2+1,(l+r)/2+1,r);
}

int main()
{int i,j,j1,t1,opt;
 
 scanf("%d%d%d",&n,&m,&k);
 scanf("%s",a+1);
 build(1,1,n);
 for(i=1;i<=m;i++)
 {  scanf("%d",&opt);
    if(opt==1)
    {   scanf("%d%d%s",&x,&y,c);
        //cout<<"*&"<<endl;
        change_c(1,1,n);
        //cout<<"$$"<<endl;
        x--;
        change_t(1,1,n);
        x++;
        t1=x;
        x=t1-1;
        c1[0]=query(1,1,n);
        b[(c1[0]-96)*27+c[0]-96]++;
        z=(c1[0]-96)*27+c[0]-96;
        change_p(1,1,n);
        x=y+1;
        c1[0]=query(1,1,n);
        b[(c[0]-96)*27+c1[0]-96]++;
        z=(c[0]-96)*27+c1[0]-96;
        x=y;
        change_p(1,1,n);
    }
    else
    {   scanf("%s",c+1);
        ans=n;
        for(j=1;j<=k;j++)
            for(j1=j+1;j1<=k;j1++)
                if(b[(c[j]-96)*27+c[j1]-96]>0)
                    ans-=b[(c[j]-96)*27+c[j1]-96];
        printf("%d\n",ans);
    }
 }
 return 0;
}