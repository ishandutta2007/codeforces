#include<cstdio>
#include<set>

using namespace std;

set<int>W,H;
multiset<int>w1,h1;

long long w,h;
int n,x,first,second;

int main()
{
	scanf("%I64d%I64d%d",&w,&h,&n);
	W.insert(0);
	W.insert(w);
	w1.insert(w);
	H.insert(0);
	H.insert(h);
	h1.insert(h);
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while(ch!='H'&&ch!='V')ch=getchar();
		scanf("%d",&x);
		if(ch=='H')
		{
			first=*(--H.lower_bound(x));
			second=*(H.upper_bound(x));
			H.insert(x);
			h1.erase(h1.find(second-first));
			h1.insert(x-first);
			h1.insert(second-x);
		}
		else
		{
			first=*(--W.lower_bound(x));
			second=*(W.upper_bound(x));
			W.insert(x);
			w1.erase(w1.find(second-first));
			w1.insert(x-first);
			w1.insert(second-x);			
		}
		int o=(*(--h1.end()));
		o=(*(--w1.end()));
		printf("%I64d\n",1ll*(*(--w1.end()))*(*(--h1.end())));
	}
}