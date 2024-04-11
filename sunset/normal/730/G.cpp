#include<bits/stdc++.h>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline void repr(T &a,T b){if(a<b)a=b;}
template<typename T> inline void repl(T &a,T b){if(a>b)a=b;}
#define mp(a,b) std::make_pair(a,b)

std::list<std::pair<int,int>> s;

int main()
{
	int n;
	scanf("%d",&n);
	s.push_back(mp(0,0));
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		b+=a-1;
		bool flag=1;
		for(auto i=s.begin();i!=s.end();i++)
			if((i->xx<=b&&i->xx>=a)||(i->yy<=b&&i->yy>=a)||(i->xx<=a&&i->yy>=b))
				flag=0;
		if(flag)
		{
			for(auto i=s.begin();i!=s.end();i++)
			{
				auto k=i;k++;
				if(k==s.end()||k->xx>b)
				{
					s.insert(k,mp(a,b));
					break;
				}
			}
			printf("%d %d\n",a,b);
		}
		else
		{
			for(auto i=s.begin();i!=s.end();i++)
			{
				auto k=i;k++;
				if(k==s.end()||(k->xx-i->yy>=b-a+2))
				{
					printf("%d %d\n",i->yy+1,i->yy+b-a+1);
					i->yy+=b-a+1;
					break;
				}
			}
		}
		//printf("\n%d\n",flag);
		//for(auto i=s.begin();i!=s.end();i++)
		//	printf("%d %d\n",i->xx,i->yy);
		//printf("\n");
	}
}