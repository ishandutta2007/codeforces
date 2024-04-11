#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,save[25];
bool used[MAXN];
struct node
{  
    int next[2];  
    int v; 
    void init()
    {  
        v=INF;
        memset(next,-1,sizeof(next));  
    }  
};  
struct node L[101][MAXN];  
int tot[101];  
  
void add(int num,int x)
{  
	int t=0,tt=x;
	while(t<17)
	{
		save[t]=x&1;
		x=x>>1;
		t++;
	}
    int now=0;
    L[num][now].v=min(L[num][now].v,tt);
    for(int i=16;i>=0;i--)
    {  
        int tmp=save[i];  
        int next=L[num][now].next[tmp];  
        if(next==-1)
        {  
            next=++tot[num];    
            L[num][next].init();
            L[num][next].v=tt;
            L[num][now].next[tmp]=next;  
        }  
        else L[num][next].v=min(L[num][next].v,tt); 
        now=next;  
        //printf("%d %d\n",now,L[num][now].v);
    }  
}  
  
int query(int num,int x,int ub)
{  
	int t=0,tt=x;
	while(t<17)
	{
		save[t]=x&1;
		x=x>>1;
		t++;
	}
    int now=0,ans=0;  
    for(int i=16;i>=0;i--)
    {  
    	//printf("%d\n",i);
        int tmp=save[i];  
        int next=-1;
        bool f1=false,f2=false;  
        if(L[num][now].next[1-tmp]!=-1)
        {
        	int pp=L[num][now].next[1-tmp];
        	//printf("it%d\n",pp);
        	//printf("%d %d\n",pp,L[num][pp].v);
        	if(L[num][pp].v<=ub) {ans+=(1<<i); next=pp;}
        }
        if(next==-1&&L[num][now].next[tmp]!=-1)
        {
        	int pp=L[num][now].next[tmp];
        	//printf("it%d\n",pp);
        	//printf("%d %d\n",pp,L[num][pp].v);
        	if(L[num][pp].v<=ub) next=pp; 
        }
        if(next==-1) return -1;
        now=next;  
    }  
    return ans; 
}  
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=100;i++)
			L[i][0].init();
	memset(used,false,sizeof(used));
	while(q--)
	{
		int type,x,k,s;
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d",&x);
			used[x]=true;
			for(int i=1;i<=100;i++)
				if(x%i==0) add(i,x);
		}
		else
		{
			scanf("%d%d%d",&x,&k,&s);
			if(x%k!=0) {puts("-1"); continue;}
			int ans=-1;
			if(k>100)
			{
				for(int i=0;i<=s-x;i+=k)
					if(used[i]) ans=max(ans,x^i);
				if(ans==-1) puts("-1"); else printf("%d\n",ans^x);
			}
			else 
				{
					if(query(k,x,s-x)==-1) puts("-1"); else printf("%d\n",query(k,x,s-x)^x);
				}
		}
	}
return 0;
}