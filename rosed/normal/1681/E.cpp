#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define y1 UFO
	const int N=1e5+10,inf=2e9;
	int n,m,cnt;
	int a[N];
	struct node
	{
		int x,y;
	}d[N][2];
	signed f[N][317][2][2];
	inline int dis(node a,node b,int flag)
	{
		if(flag==0) ++a.x;
		if(flag==1) ++a.y;
		return abs(a.x-b.x)+abs(a.y-b.y)+(flag<=1);
	}
	inline int check(node a)
	{
		return max(a.x,a.y);
	}
	int g[333][2];
	inline int go(node st,node ed,int idx,int idy)
	{
		if(idx==idy) return dis(st,ed,2);
		// for(int i=0;i<=330;++i)
		// 	for(int t1=0;t1<=1;++t1) g[i][t1]=0;
		g[1][0]=dis(st,d[idx][0],2)+1;
		g[1][1]=dis(st,d[idx][1],2)+1;
		++idx;
		int num=1;
		while(idx<idy)
		{
			++num;
			int len=min(cnt,idy-idx);
			g[num][0]=min(g[num-1][0]+f[idx][len][0][0],g[num-1][1]+f[idx][len][1][0]);
			g[num][1]=min(g[num-1][0]+f[idx][len][0][1],g[num-1][1]+f[idx][len][1][1]);
			idx+=len;
		}
		//cout<<dis(d[2][0],d[2][0],0)<<"!!!!!!!!!"<<endl;
		//cout<<f[3][1][0][0]<<"!!!!!!!!!!"<<endl;
		//cout<<num<<"!!"<<endl;
		//cout<<g[2][0]<<' '<<g[2][1]<<"!!"<<endl;
		return min(g[num][0]+dis(d[idy-1][0],ed,0),g[num][1]+dis(d[idy-1][1],ed,1))-1;
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n;
		cnt=sqrt(n);
		for(int i=1;i<n;++i)
		{
			cin>>d[i][0].x>>d[i][0].y>>d[i][1].x>>d[i][1].y;
		}
		d[0][0]=(node){0,1};
		d[0][1]=(node){1,0};
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;++i)
		{
			for(int t=0;t<=1;++t) f[i][0][t][t]=0;
			for(int j=i+1;j<=i+cnt&&j<=n;++j)
			{
				for(int s=0;s<=1;++s)
				{
					for(int t=0;t<=1;++t)
					{
						f[i][j-i][s][t]=min(f[i][j-i-1][s][0]+dis(d[j-2][0],d[j-1][t],0),f[i][j-i-1][s][1]+dis(d[j-2][1],d[j-1][t],1));
						// if(i==3&&j==i+1)
						// {
						// 	cout<<d[j][0].x<<' '<<d[j][0].y<<"!!"<<endl;
						// 	cout<<dis(d[j-1][0],d[j][0],0)<<"!!"<<endl;
						// }
					}
				}
			}
		}
		cin>>m;
		for(int i=1;i<=m;++i)
		{
			node t1,t2;
			cin>>t1.x>>t1.y>>t2.x>>t2.y;
			int idx=check(t1),idy=check(t2);
			if(idx>idy)
			{
				swap(t1,t2);
				swap(idx,idy);
			}
			cout<<go(t1,t2,idx,idy)<<'\n';
		}

	}
}
signed main()
{
	red::main();
	return 0;
}
/*
4
1 1 1 1
2 1 2 2
3 2 1 3
1
2 2 4 4

*/