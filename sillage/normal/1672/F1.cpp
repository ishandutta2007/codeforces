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
int t,n,a[200005];
std::vector<int>E[200005];
int l[200005],r[200005],las,b[200005];
int main()
{
	read(t);
	while(t--)
	{
		read(n),las=0;
		for(int i=1;i<=n;i++)E[i].clear();
		for(int i=1;i<=n;i++)read(a[i]),E[a[i]].push_back(i);
		for(int i=1;i<=n;i++)
			if(E[i].size())
			{
				r[las]=i;
				l[i]=las;
				las=i;
			}
		r[las]=n+1;
		for(int tot=0;tot<n;)
		{
			int t=r[0],pl=E[t][E[t].size()-1],v=t;
			E[t].pop_back();
			if(E[t].size()==0)l[r[t]]=l[t],r[l[t]]=r[t];
			t=r[t],tot++;
			while(t!=n+1)
			{
				b[pl]=t;
				pl=E[t][E[t].size()-1],tot++;
				E[t].pop_back();
				if(E[t].size()==0)l[r[t]]=l[t],r[l[t]]=r[t];
				t=r[t];
			}
			b[pl]=v;
		}
		print(b[1]);
		for(int i=2;i<=n;i++)putchar(' '),print(b[i]);
		putchar('\n');
	}
	return 0;
}