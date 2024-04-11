#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 2110000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int q[MAXN];
int cnt=0;
char s[MAXN];
char t[MAXN];
char p[MAXN];
int manachar() 
{
    t[0]='$';
    t[1]='#';
    int cnt=2;
    int len=strlen(s);
    for (int i=0;i<len;++i)
    {
    	t[cnt++]=s[i];
    	t[cnt++]='#';
    }
    t[cnt++]=0;
    int rl=0,rc=0,ansLen=0,ansCenter=0; 
    for(int i=1;i<len*2+2;++i) 
    {
    	q[i]=rl>i?min(q[2*rc-i],rl-i):1;
    	while(t[i+q[i]]==t[i-q[i]]) ++q[i]; 
    	if(rl<i+q[i]) 
    	{
        	rl=i+q[i];
        	rc=i;
    	}
    	//cout<<i<<' '<<q[i]<<' '<<rc<<endl;
    	if(ansLen<q[i] && q[i]==i) 
    	{
        	ansLen=q[i];
        	ansCenter=i;
      	}
    }
    return ansLen-1;
}


int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>p;
		int len=strlen(p);
		for (int i=0;i<len+1;i++)
			s[i]=0;
		int l1,l2;
		int m=-1;
		for (int i=0;i<len-i-1;i++)
			if (p[i]!=p[len-1-i])
				break;
			else
				m=i;
		//WRT(m);
		for (int i=m+1;i<len-m-1;i++)
			s[i-m-1]=p[i];
		//WRT(s);
		
		l1=manachar();
		//WRT(l1);
		for (int i=m+1;i<len-m-1;i++)
			s[len-m-i-2]=p[i];
		//WRT(s);
		l2=manachar();
		//WRT(l2);
		for (int i=0;i<=m;i++)
			putchar(p[i]);
		if (l1>l2)
		{
			int beg=m+1;
			for (int i=0;i<l1;i++)
				putchar(p[beg+i]);
		}
		else
		{
			int beg=len-m-2;
			for (int i=0;i<l2;i++)
				putchar(p[beg-i]);
		}
		for (int i=m;i>=0;i--)
			putchar(p[i]);
		putchar('\n');
	}
	return ~~(0^_^0);
}