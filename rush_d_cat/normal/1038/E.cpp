#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
const int N=500008;
vector<int>a[6];
int ans,n,b[4];
int maxx(int x,int y){if(x>y)y=x;return y;}
int main(void)
{
	std::ios::sync_with_stdio(false);
	int i,j,k,n,p0,p1,p2,p3,p4,p5,q[6];
	int f1,f2,f3,f4,ans,s1,s2,s3,s4;
	scanf("%d",&n);ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&p1,&p3,&p2);
		if(p1==p2){b[p1-1]+=p3;}
		else
		{
			if(p1>p2){k=p1;p1=p2;p2=k;}
			if(p1==1&&p2==2)a[0].push_back(-p3);
			if(p1==1&&p2==3)a[1].push_back(-p3);
			if(p1==1&&p2==4)a[2].push_back(-p3);
			if(p1==2&&p2==3)a[3].push_back(-p3);
			if(p1==2&&p2==4)a[4].push_back(-p3);
			if(p1==3&&p2==4)a[5].push_back(-p3);
		}
	}
	ans=maxx(maxx(b[0],b[1]),maxx(b[2],b[3]));
	for(i=0;i<=5;i++)if(!a[i].empty())
	{
		sort(a[i].begin(),a[i].end());
		a[i][0]=-a[i][0];
		for(j=1;j<(int)a[i].size();j++)a[i][j]=a[i][j-1]-a[i][j];
	}
	for(i=0;i<=5;i++)q[i]=(int)a[i].size();
	for(p0=0;p0<=q[0];p0++)
	for(p1=0;p1<=q[1];p1++)
	for(p2=0;p2<=q[2];p2++)
	for(p3=0;p3<=q[3];p3++)
	for(p4=0;p4<=q[4];p4++)
	for(p5=0;p5<=q[5];p5++)
	{
		f1=f2=f4=0;
		if(p0>0){f4+=a[0][p0-1];f1|=3;if(f2==0)f2=3;else if(f2&3)f2|=3;}
		if(p1>0){f4+=a[1][p1-1];f1|=5;if(f2==0)f2=5;else if(f2&5)f2|=5;}
		if(p2>0){f4+=a[2][p2-1];f1|=9;if(f2==0)f2=9;else if(f2&9)f2|=9;}
		if(p3>0){f4+=a[3][p3-1];f1|=6;if(f2==0)f2=6;else if(f2&6)f2|=6;}
		if(p4>0){f4+=a[4][p4-1];f1|=10;if(f2==0)f2=10;else if(f2&10)f2|=10;}
		if(p5>0){f4+=a[5][p5-1];f1|=12;if(f2==0)f2=12;else if(f2&12)f2|=12;}
		if(p3>0){f1|=6;if(f2==0)f2=6;else if(f2&6)f2|=6;}
		if(p4>0){f1|=10;if(f2==0)f2=10;else if(f2&10)f2|=10;}
		if(f1!=f2)continue;
		f3=((s1=p0+p1+p2)&1)+((s2=p0+p3+p4)&1)+((s3=p1+p3+p5)&1)+((s4=p2+p4+p5)&1);
		if(f3==0||f3==2);else continue;
		if(s1)f4+=b[0];
		if(s2)f4+=b[1];
		if(s3)f4+=b[2];
		if(s4)f4+=b[3];
		ans=maxx(ans,f4);
	}
	cout<<ans;
	return 0;
}