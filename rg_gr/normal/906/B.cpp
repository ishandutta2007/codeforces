#include <stdio.h>
#include <string.h>
#include <queue>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int read1d()
{
    int num=0;char c=getchar();
    while(c<48||c>57){c=getchar();}
    return c&1;
}
namespace subtask1{
	void solve(int n,int m)
	{
		puts("YES");
		int cnt=0;
		int **b=new int*[n];
		for(int i=0;i<n;i++)b[i]=new int[m];
		int u=n&2147483646;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cnt++;
				if((i+j+1)&1)b[i][j]=cnt;
				else
				{
					int q=i+4;
					if(q>=n)
					{
						if(n&1)
							if(q&1)q=q-n+1;
							else q=q-n-1;
						else q=q-n;
					}
					b[q][j]=cnt;
				}
			}
		}
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++)printf("%d ",b[i][j]);
		delete[] b;
	}
}
namespace subtask2{
	void solve(int n,int m)
	{
		puts("YES");
		int cnt=0;
		int **b=new int*[n];
		for(int i=0;i<n;i++)b[i]=new int[m];
		int u=m&2147483646;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cnt++;
				if((i+j+1)&1)b[i][j]=cnt;
				else
				{
					int q=j+4;
					if(q>=m)
					{
						if(m&1)
							if(q&1)q=q-m+1;
							else q=q-m-1;
						else q=q-m;
					}
					b[i][q]=cnt;
				}
			}
		}
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++)printf("%d ",b[i][j]);
		delete[] b;
	}
}
#define p(a,b) else if(n==a&&m==b)
namespace subtask3{
	void fill(int*a,int n,int d)
	{
		int cnt=1;
		for(int i=(n+1)>>1;i>0;i--)a[i-1]=d+cnt,cnt+=2;
		cnt=n;
		for(int i=2;i<=n;i+=2)a[--cnt]=d+i;
	}
	void filll(int*a,int m,int d,int n)
	{
		//a a+d a+dd a+ddd a+dddd 
		//a+dddd a+dd a a+ddd a+d
	//	printf("filling %d %d %d %d\n",a,m,d,n);
		int cnt=0;
		for(int i=(n+1)>>1;i>0;i--)a[i-1]=d+cnt,cnt+=m+m;
		cnt=n;
		for(int i=2;i<=n;i+=2)a[--cnt]=d+(i-1)*m;
		for(int i=0;i<n;i++)printf("%d ",a[i]);puts("");
	}
	void solve(int n,int m)
	{
		if(n==1&&m==1)puts("YES\n1");
		else if(n==1&&m==2)puts("NO");
		else if(n==2&&m==1)puts("NO");
		else if(n==2&&m==2)puts("NO");
		else if(n==2&&m==3)puts("NO");
		else if(n==3&&m==2)puts("NO");
		else if(n+m==4)puts("NO");
		else if(n==3&&m==3)puts("YES\n5 1 6\n3 9 4\n7 2 8");
		else
		{
			puts("YES");
			if(n==1&&m==4)puts("3 1 4 2");
			p(2,4)puts("1 3 5 7\n6 8 2 4");
			p(3,4)puts("3 1 7 2\n8 6 4 5\n11 9 12 10");
			//p(4,4)puts("11 2 9 4\n5 16 7 14\n3 10 1 12\n13 8 15 6");
			p(1,5)puts("1 3 5 2 4");
			p(2,5)puts("5 3 1 4 6\n9 7 10 2 8");
			p(3,5)puts("9 3 1 4 6\n13 5 11 14 8\n15 7 10 2 12");
			//p(4,5)puts("7 1 5 12 10\n11 3 15 16 14\n13 9 2 4 18\n13 19 6 8 20");
			//p(5,5)puts("13 3 1 4 8\n15 5 7 10 12\n19 9 11 14 16\n23 17 20 2 22\n25 21 24 6 18");
			p(6,1)puts("1\n3\n5\n2\n4\n6\n");
			p(6,2)puts("1 4\n5 8\n9 12\n2 3\n6 7\n10 11\n");
			p(6,3)puts("1 3 5\n7 9 11\n13 15 17\n2 4 6\n8 10 12\n14 16 18");
			//p(6,4)puts("2 4 5 7\n10 12 13 15\n18 20 21 23\n1 3 6 8\n9 11 14 16\n17 19 22 24");
			//p(6,5)puts("1 3 5 7 9\n11 13 15 17 19\n21 23 25 27 29\n2 4 6 8 10\n12 14 16 18 20\n22 24 26 28 30");
			//p(6,6)puts("")
			p(7,1)puts("7 5 3 1 6 4 2");
			p(7,2)puts("1 5 9 13 4 8 12\n3 7 11 2 6 10 14");
			p(7,3)puts("19 11 3 1 6 4 12\n15 13 5 9 14 8 16\n21 17 7 20 2 10 18");
			p(4,1)puts("3\n1\n4\n2");
			p(4,2)puts("1 6\n4 7\n5 2\n8 3");
			p(4,3)puts("1 3 5\n7 9 11\n6 4 2\n8 10 12");
			p(5,1)puts("1\n3\n5\n2\n4");
			p(5,2)puts("1 6\n4 7\n5 10\n8 3\n9 2");
			p(5,3)puts("1 3 5\n7 9 11\n13 15 2\n4 6 8\n10 12 14");
			p(1,6)puts("1 3 5 2 4 6");
			p(2,6)puts("1 3 5 2 4 6\n11 9 7 12 10 8");
			p(3,6)puts("1 3 5 2 4 6\n11 9 7 12 10 8\n13 15 17 14 16 18");
			p(7,1)puts("1\n3\n5\n7\n2\n4\n6");
			p(7,2)puts("1 14\n4 7\n5 10\n8 11\n9 6\n12 3\n13 2");
			p(7,3)puts("1 3 5\n7 9 11\n13 15 17\n19 21 2\n4 6 8\n10 12 14\n16 18 20");
			else
			{
				int **b=new int*[n];//
				int cnt=0;
				if(n<m)goto charm1;
				for(int i=0;i<n;i++)b[i]=new int[m];
				for(int i=n/2+1;i<=n;i++)fill(b[i-1],m,cnt*m),cnt+=2;
				cnt=1;
				for(int i=1;i<=n/2;i++)fill(b[i-1],m,cnt*m),cnt+=2;
				for(int i=0;i<n;i++,puts(""))
					for(int j=0;j<m;j++)printf("%d ",b[i][j]);
				delete[] b;
				return;
				charm1:;delete[] b;
				if(m>5)
				{
					b=new int*[m];
					for(int i=0;i<m;i++)b[i]=new int[n];
					int cnt=2;
					for(int i=m/2+1;i<=m;i++)filll(b[i-1],m,cnt,n),cnt+=2;
					cnt=1;
					for(int i=1;i<=m/2;i++)filll(b[i-1],m,cnt,n),cnt+=2;
					for(int j=0;j<n;j++,puts(""))
						for(int i=0;i<m;i++)printf("%d ",b[i][j]);
					delete[] b;
				}
			}
		}
	}
}
int main()
{
	//freopen("op.out","w",stdout);
	int n=read(),m=read();
	if(n>7)subtask1::solve(n,m);
	else if(m>7)subtask2::solve(n,m);
	else /*iaaf(n<4&&m<4)*/subtask3::solve(n,m);
	
	return 0;
}