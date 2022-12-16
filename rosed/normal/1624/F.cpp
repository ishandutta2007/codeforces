#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=998244353;
	int T,n,x,y,l,r,len;
	inline void print(int x)
	{
		cout<<"! "<<x<<endl;
	}
	inline void main()
	{
		cin>>n;
		l=1,r=n-1;
		while(l<r-1)
		{
			len=r-l+1;
			int mid=((l+r+1)/2)%n;
			int tmp=n-mid;
		//	cout<<l<<' '<<r<<' '<<"!!"<<endl;
			cout<<"+ "<<tmp<<endl;
			cin>>x;
			if(x==y) l=l+tmp,r=min(r+tmp,n*(x+1)-1);
			else l=max(l+tmp,n*x),r=r+tmp;
			y=x;
		}
	//	cout<<l<<' '<<r<<"!!"<<endl;
		if(l==r) print(l);
		else 
		{
			int tmp=n-r;
			if(tmp<0) tmp=(tmp%n+n)%n;
			cout<<"+ "<<tmp<<endl;
			fflush(stdout);
			cin>>x;
			if(x==y) print(l+tmp);
			else print(r+tmp);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

5
+10
1  15
10~19
+5
2 20
20~24
+8
2 28
28~29
+1


! 3
*/