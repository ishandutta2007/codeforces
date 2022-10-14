#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 4010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> greyOrder;
int k,n;
void getGreyOrder(int L,int R,int rev)
{
	if (L==R)
	{
		greyOrder.push_back(L);
		return ;
	}
	if (rev)
	{
		getGreyOrder((L+R)/2+1,R,rev^1);
		getGreyOrder(L,(L+R)/2,rev);
	}
	else
	{
		getGreyOrder(L,(L+R)/2,rev);
		getGreyOrder((L+R)/2+1,R,rev^1);
	}
}

int reverseBit(int x)
{
	int ans=0;
	for (int i=0;i<k;i++)
		ans|=((x>>i)&1)<<(k-1-i);
	return ans;
}
int root=1;
int rev[MAXN];
#define LS (rev[pos] ? (pos<<1|1):(pos<<1))
#define RS (rev[pos] ? (pos<<1):(pos<<1|1))
int L[MAXN],R[MAXN],ans[MAXN],cnt[MAXN],len[MAXN];
void pushup(int pos)
{
	cnt[pos]=cnt[LS]+cnt[RS];
	if (cnt[LS])
		L[pos]=L[LS];
	else
		L[pos]=L[RS]+(len[pos]/2);
	if (cnt[RS])
		R[pos]=R[RS];
	else
		R[pos]=R[LS]+(len[pos]/2);
	if (cnt[pos]==0)
		L[pos]=R[pos]=len[pos]-1;
	ans[pos]=min(ans[LS],ans[RS]);
	if (cnt[LS] && cnt[RS])
		ans[pos]=min(ans[pos],R[LS]+L[RS]+1);
	if (cnt[pos]<2)
		ans[pos]=INF;
	//	return 0;
}

void insert(int x)
{
	int pos=x+(1<<k);
	cnt[pos]++;
	while (pos)
	{
		pos/=2;
		pushup(pos);
	}
}

void init()
{

}
//1 - 1
//2 - 3
//4 - 7
void flip(int b)
{
	//cout<<endl<<"B"<<b<<endl;
	for (int i=(1<<(k-b))-1;i>=(1<<(k-b-1));i--)
		rev[i]^=1;
	for (int i=(1<<(k-b))-1;i;i--)
		pushup(i);
}

int res[MAXN];
void work()
{
	memset(ans,INF,sizeof(ans));
	int x;
	cin>>n>>k;
	getGreyOrder(0,(1<<k)-1,0);
	len[1]=(1<<k);
	for (int i=2;i<MAXN;i++)
		len[i]=len[i/2]/2;
	for (auto &p:greyOrder)
		p=reverseBit(p);
	for (auto p:greyOrder)
	{
		//for (int i=k-1;i>=0;i--)
		//	putchar('0'+((p>>i)&1));
		//putchar('\n');
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}	
	res[greyOrder[0]]=ans[root];
	for (int i=1;i<(1<<k);i++)
	{
		for (int j=0;j<k;j++)
			if (((greyOrder[i-1]>>j)&1)!=((greyOrder[i]>>j)&1))
				flip(j);
		res[greyOrder[i]]=ans[root];
	}
	for (int i=0;i<(1<<k);i++)
		printf("%d ",res[i]);

}


int main()
{
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}