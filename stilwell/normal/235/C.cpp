#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct SAM
{
	int trans[26],len,fa;
}sam[2000005];
int tot,root,tail;

char s[2000005],ch;

void add(int ch,int len)
{
	int p=tail,np=++tot,q,r;
	sam[np].len=len;
	for(;p&&!sam[p].trans[ch];p=sam[p].fa)sam[p].trans[ch]=np;
	tail=np;
	if(!p)sam[np].fa=root;
	else if(sam[sam[p].trans[ch]].len==sam[p].len+1)sam[np].fa=sam[p].trans[ch];
		else
		{
			q=sam[p].trans[ch];r=++tot;
			sam[r]=sam[q];
			sam[r].len=sam[p].len+1;
			sam[q].fa=sam[np].fa=r;
			for(;p&&sam[p].trans[ch]==q;p=sam[p].fa)sam[p].trans[ch]=r;
		}
}

int T,l,i,j,k;
int tmp,cnt[2000005],sum[2000005],id[2000005];
int use[2000005];
long long ans;

int main()
{
	root=tail=tot=1;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;++i)add(s[i]-'a',i);
	k=root;
	for(i=1;i<=l;++i)cnt[k=sam[k].trans[s[i]-'a']]=1;
	for(i=2;i<=tot;++i)++sum[sam[i].len];
	for(i=l;i>=1;--i)sum[i]+=sum[i+1];
	for(i=2;i<=tot;++i)id[sum[sam[i].len]--]=i;
	for(i=1;i<tot;++i)
	cnt[sam[id[i]].fa]+=cnt[id[i]];
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%s",s+1);
		l=strlen(s+1);
		for(i=1;i<=l;++i)s[i+l]=s[i];
		l+=l;k=root;ans=tmp=0;
		for(i=1;i<l;++i)
		{
			ch=s[i]-'a';
			if(sam[k].trans[ch])++tmp,k=sam[k].trans[ch];
			else
			{
				for(;k&&!sam[k].trans[ch];k=sam[k].fa);
				if(!k)tmp=0,k=root;
				else
				{
					tmp=sam[k].len+1;
					k=sam[k].trans[ch];
				}
			}
			if(tmp>=l/2)
			{
				for(;sam[sam[k].fa].len>=l/2;k=sam[k].fa);
				if(sam[k].len<tmp)tmp=sam[k].len;
				if(use[k]!=T)ans+=cnt[k],use[k]=T;
			}
		}
		printf("%I64d\n",ans);
	}
}