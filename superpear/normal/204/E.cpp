#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn=200002;
const int base=3214567;
const int maxlongint=2147483647;

typedef pair<pair<int,int>,int> PIII;
int n,k,lst,nowdiff;
int hash[maxn+3],powc[maxn+3],mark[maxn+3],who[maxn+3],where[maxn+3],data[maxn+3],
	height[maxn+3],lou2[maxn+3],qiu2[maxn+3],minlen[maxn+3],numtab[maxn+3],maxev[maxn+3];
long long ans[maxn+3];
string s[maxn+3],stc;
int st[maxn+3][20];

bool equal(int x1,int y1,int len)
{
	int c1=hash[x1+len-1]-hash[x1-1]*powc[len];
	int c2=hash[y1+len-1]-hash[y1-1]*powc[len];
	return c1==c2;
}

void makesa()
{
	int jvhash[300],ecg,e;
	PIII q[maxn];
	memset(jvhash,0,sizeof(jvhash));
	for (int i=0;i<lst;i++) jvhash[stc[i]]=1;
	for (int i=1;i<=290;i++) jvhash[i]=jvhash[i-1]+jvhash[i];
	for (int i=1;i<=lst;i++) mark[i]=jvhash[stc[i-1]];
	e=1;
	q[0]=make_pair(make_pair(-1,-1),-1);
	while (e<=lst)
	{
		for (int i=1;i<=lst-e;i++) q[i]=make_pair(make_pair(mark[i],mark[i+e]),i);
		for (int i=lst-e+1;i<=lst;i++) q[i]=make_pair(make_pair(mark[i],0),i);
		sort(q+1,q+lst+1);
		mark[0]=0;
		for (int i=1;i<=lst;i++)
			if (q[i].first!=q[i-1].first) mark[q[i].second]=mark[q[i-1].second]+1; 
			                         else mark[q[i].second]=mark[q[i-1].second];
		if (mark[lst]==lst) break;
		e*=2;
	}
	for (int i=1;i<=lst;i++) who[mark[i]]=i;
}

void calcheight()
{
	int left,right,mid;
	for (int i=1;i<lst;i++)
	{
		left=1;right=min(lst-who[i]+1,lst-who[i+1]+1);
		while (left<=right)
		{
			mid=(left+right)/2;
			if (equal(who[i],who[i+1],mid)) left=mid+1; else right=mid-1;
		}
		height[i]=right;
	}
}

void makermq()
{
	memset(st,127,sizeof(st));
	int e,o;
	for (int i=lst-1;i>=1;i--)
	{
		st[i][0]=height[i];
		e=1;o=1;
		while (i+e<lst)
		{
			st[i][o]=min(st[i][o-1],st[i+e][o-1]);
			e*=2;++o;
		}
	}
	memset(lou2,0,sizeof(lou2));
	lou2[1]=1;
	for (int i=2;i<maxn;i++) lou2[i]=lou2[i/2]*2;
	memset(qiu2,0,sizeof(qiu2));
	qiu2[1]=0;
	for (int i=1;i<=17;i++) qiu2[1<<i]=i;
}

int getmin(int l,int r)
{
	int c=lou2[r-l+1];
	if (l>r) return maxlongint;
	return min(st[l][qiu2[c]],st[r-c+1][qiu2[c]]);
}

bool isok(int t,int len)
{
	int left,right,mid,ll,rr;
	left=1;right=t;
	while (left<=right)
	{
		mid=(left+right)/2;
		if (getmin(mid,t-1)>=len) right=mid-1; else left=mid+1;
	}
	ll=left;
	left=t;right=lst;
	while (left<=right)
	{
		mid=(left+right)/2;
		if (getmin(t,mid-1)>=len) left=mid+1; else right=mid-1;
	}
	rr=right;
	if (rr>=minlen[ll]) return true; else return false;	
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>s[i];
	stc="";
	memset(where,0,sizeof(where));
	memset(maxev,0,sizeof(maxev));
	for (int i=1;i<=n;i++)
	{
		stc+=s[i];
		int eci=stc.size()-s[i].size()+1,ecj=stc.size();
		for (int j=eci;j<=ecj;j++) where[j]=i;
		maxev[i]=stc.size();
		stc+="#";
	}
	lst=stc.size();
	hash[0]=0;
	for (int i=1;i<=lst;i++) hash[i]=hash[i-1]*base+stc[i-1];
	powc[0]=1;
	for (int i=1;i<maxn;i++) powc[i]=powc[i-1]*base;
	makesa();
	calcheight();
	makermq();
	for (int i=1;i<=lst;i++) data[i]=where[who[i]];
	memset(minlen,0,sizeof(minlen));
	nowdiff=0;
	memset(numtab,0,sizeof(numtab));
	for (int i=1;i<=lst;i++)
	{
		minlen[i]=minlen[i-1];
		while (nowdiff<k)
		{
			++minlen[i];
			++numtab[data[minlen[i]]];
			if (data[minlen[i]]!=0)
				if (numtab[data[minlen[i]]]==1) ++nowdiff;
		}
		--numtab[data[i]];
		if (data[i]!=0)
			if (numtab[data[i]]==0) --nowdiff;
	}
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=lst;i++)
	{
		if (stc[who[i]-1]=='#') continue;
		int left=1,right=maxev[where[who[i]]]-who[i]+1,mid;
		while (left<=right)
		{
			mid=(left+right)/2;
			if (isok(i,mid)) left=mid+1; else right=mid-1;
		}
		ans[where[who[i]]]+=(long long)right;
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
		
	return 0;
}