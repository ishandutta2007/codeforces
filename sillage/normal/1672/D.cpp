#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T min(const T x,const T y){return x<y?x:y;}
template<typename T>inline T max(const T x,const T y){return x>y?x:y;}
template<typename T>inline T abs(const T x){return x<0?-x:x;}
template<typename T>inline void mind(T&x,const T y){if(x>y)x=y;}
template<typename T>inline void maxd(T&x,const T y){if(x<y)x=y;}
typedef long long ll;
template<typename T>inline void read(T&x)
{
	char cu=getchar();bool fla=0;x=0;
	while(!isdigit(cu)){if(cu=='-')fla=1;cu=getchar();}
	while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
	if(fla)x=-x;
}
template<typename T>void printe(const T x)
{
	if(x>=10)printe(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(const T x)
{
	if(x<0)putchar('-'),printe(-x);
	else printe(x);
}
int t,n,a[200005],b[200005];
int r[200005];
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=n;i++)read(a[i]),r[i]=0;
		bool fla=1;
		int l=1;
		for(int i=1;i<=n;i++)
		{
			read(b[i]);
			if(b[i]==b[i-1]&&r[b[i]])
			{
				r[b[i]]--;
				continue;
			}
			while(l<=n&&a[l]!=b[i])
			{
				r[a[l]]++;
				l++;
			}
			if(l<=n&&a[l]==b[i])
			{
				l++;
				continue;
			}
			else fla=0;
		}
		if(fla)puts("YES");
		else puts("NO");
	}
	return 0;
}