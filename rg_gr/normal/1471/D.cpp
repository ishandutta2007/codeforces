int a[170]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
#include <stdio.h>
#include <string.h>
#include <map>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
std::map<int,int> m;
void addedge(int u)
{
	int cnt=u;
	for(int i=0;i<=167;i++)
	{
		if(cnt<a[i])break;
		while(u%(a[i]*a[i])==0)u/=a[i]*a[i];
		while(cnt%a[i]==0)cnt/=a[i];
	}
	m[u]++;
}
signed main()
{
	int T=read();
	while(T--)
	{
		m.clear();
		int n=read();
		for(int i=0;i<n;i++)addedge(read());
		int ans1=0,ans2=0;
		for(std::map<int,int>::iterator it=m.begin();it!=m.end();it++)
		{
			int u=(*it).first,v=(*it).second;
			ans1=ans1>v?ans1:v;
			if(u==1||((v&1)==0))
			{
				ans2+=v;
			}
		}
		ans2=ans2>ans1?ans2:ans1;
		int q=read();
		while(q--)
		{
			int x=read();
			if(x)printf("%lld\n",ans2);
			else printf("%lld\n",ans1);
		}
	}
}