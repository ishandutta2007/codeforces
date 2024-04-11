#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))

#define MAXN 500500
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f 
#define EPS 1e-5

#define _ 0
using namespace std;

int dfn[MAXN];
int dep[MAXN];
int fa[MAXN][25];
LL minv[MAXN];
int m[MAXN];
int lst[MAXN];
bool query[MAXN];
int n,q;
int num;
int top;
int dfscnt=1;

int stak[MAXN];

struct EDGE
{
    int to,next;
}edge[MAXN<<1],edge1[MAXN<<1]; 

int head[MAXN];// 
int cnt=1;
INL void add(int x,int y)
{
    edge[cnt].next=head[x];
    edge[cnt].to=y;
    head[x]=cnt++;
}

int head1[MAXN];// 
int cnt1=1;
INL void add1(int x,int y)
{
    edge1[cnt1].next=head1[x];
    edge1[cnt1].to=y;
    head1[x]=cnt1++;
}

void dfs(int pos)
{
    int k;
    for (k=0;fa[pos][k];k++)
        fa[pos][k+1]=fa[fa[pos][k]][k];
    m[pos]=k;
    dfn[pos]=dfscnt++;
    for (int i=head[pos];i;i=edge[i].next)
    {
        REG int to=edge[i].to;
        if (!dfn[to])
        {
            dep[to]=dep[pos]+1;
            fa[to][0]=pos;
            dfs(to);
        }
    }
}
int diff[MAXN],sum[MAXN];
map<int,vector<int> > re;
int fxxk[MAXN],val[MAXN]; 
int maxd[MAXN];


bool cmpmaxd(int x,int y)
{
	return maxd[x]>maxd[y];
}
void dfs1(int pos,int lstq,int lhz) //dp
{
	//cout<<pos<<" - "<<lstq<<endl;
	if (maxd[pos]>=2)
	{
		diff[1]++;
		diff[pos]--;
	}
	if (lstq!=-1 && query[pos])
	{
		diff[1]++;
		int tmp=pos;
		for (int i=m[pos];i>=0;i--)
			if (dep[fa[tmp][i]]>dep[lstq])
				tmp=fa[tmp][i];
		//cout<<"tmp"<<tmp<<endl;
		diff[tmp]--;
		diff[pos]++;
	}
	if (lhz && query[pos])
		diff[pos]++;
	int cnt=0;
	if (query[pos])
		lstq=pos;
	else
	{
    	for (int i=head1[pos];i;i=edge1[i].next)
    	{
    		if (maxd[edge1[i].to])
    			cnt++;
		}
	}
    for (int i=head1[pos];i;i=edge1[i].next)
    {
        int to=edge1[i].to;
        if (cnt==0)
        	dfs1(edge1[i].to,lstq,lhz);
        else if (cnt==1 && maxd[edge1[i].to])
        		dfs1(edge1[i].to,lstq,lhz);
        	else if (cnt==1 && maxd[edge1[i].to]==0)
        		dfs1(edge1[i].to,lstq,1);
        else if (cnt>=2)
        	dfs1(edge1[i].to,lstq,1);
    }
}

void dfsfxxk(int pos,int f)
{
	for (int i=head1[pos];i;i=edge1[i].next)
		if (edge1[i].to!=f)
			dfsfxxk(edge1[i].to,pos);
    query[pos]=false; // 
    head1[pos]=0;
    maxd[pos]=0;
}

int lca(int x,int y) //LCA 
{
    if (dep[x]<dep[y])
        swap(x,y);
    DRPT(i,m[x],-1)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y)
        return x;
    DRPT(i,m[x],-1)
        if (fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
} 

bool cmp(int x1,int x2)
{
    return dfn[x1]<dfn[x2];
}

void dfs2(int pos)
{
	//printf("dfs2 : %d\n",pos);
    for (int i=head1[pos];i;i=edge1[i].next)
    {
        int to=edge1[i].to;
        dfs2(to);
        maxd[pos]=max(maxd[to],maxd[pos]);
    }
	if (query[pos])
		maxd[pos]++;
}

void dfs3(int pos,int f)
{
	fxxk[pos]+=diff[pos];
	for (int i=head[pos];i;i=edge[i].next)
		if (edge[i].to!=f)
		{
			diff[edge[i].to]+=diff[pos];
			dfs3(edge[i].to,pos);
		}
}

int main()
{
	dep[1]=1;
    minv[1]=LLINF;
    cin>>n;
    int x,y;
    LL v;
    for (int i=1;i<=n;i++)
    {
    	scanf("%d",&val[i]);
    	re[val[i]].push_back(i);
	}
    RPT(i,0,n-1)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1);
    int cccc=0;
    for (auto p:re)
    {
    	cccc++;
    	num=p.second.size();
    	for (int i=1;i<=num;i++)
    	{
    		lst[i]=p.second[i-1];
    		query[lst[i]]=true;
		}
		bool f=true;
		for (int i=1;i<=num;i++)
			if (lst[i]==1)
			{
				f=false;
				break;
			 } 
		if (f)
		{
			num++;
			lst[num]=1;
		}
        sort(lst+1,lst+num+1,cmp);
        stak[top=1]=lst[1];
        RPT(i,2,num+1)
        {
            int now=lst[i];
            int lc=lca(now,stak[top]);
            while (1)
                if (dep[lc]>=dep[stak[top-1]])
                {
                	
                    if (lc!=stak[top]) // 
                    {
                        add1(lc,stak[top]);
                        if (lc!=stak[top-1]) // 
                            stak[top]=lc;
                        else // 
                            top--;
                    }
                    break;
                }
                else //
                {
                    add1(stak[top-1],stak[top]);  
                    top--;
                }
            stak[++top]=now; //now 
        }
        while (--top)
            add1(stak[top],stak[top+1]); //
        //cout<<stak[1]<<endl;
        dfs2(stak[1]);
        dfs1(stak[1],-1,0);
        dfsfxxk(stak[1],stak[1]);
        //for (int i=1;i<=n;i++)
        //	cout<<i<<' '<<diff[i]<<endl;
	}
	dfs3(1,1);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		//cout<<i<<' '<<fxxk[i]<<endl;
		if (fxxk[i]==0)
			ans++;
	}
	cout<<ans<<endl;
    /*
    cin>>q;
    while (q--)
    {
        cin>>num;
        RPT(i,1,num+1)
        {
            scanf("%d",&lst[i]);
            query[lst[i]]=true;
        }
        sort(lst+1,lst+num+1,cmp);
        stak[top=1]=lst[1];
        RPT(i,2,num+1)
        {
            int now=lst[i];
            int lc=lca(now,stak[top]);
            while (1)
                if (dep[lc]>=dep[stak[top-1]])
                {
                    if (lc!=stak[top]) // 
                    {
                        add1(lc,stak[top]);
                        if (lc!=stak[top-1]) // 
                            stak[top]=lc;
                        else // 
                            top--;
                    }
                    break;
                }
                else //
                {
                    add1(stak[top-1],stak[top]);  
                    top--;
                }
            stak[++top]=now; //now 
        }
        while (--top)
            add1(stak[top],stak[top+1]); // 
        cout<<dfs1(stak[1])<<endl;
        cnt1=1;
    }
    */
    return ~~(0^_^0);
}