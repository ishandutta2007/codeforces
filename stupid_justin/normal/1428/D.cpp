
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

 
int n,H,cnt;
int a[N];
int c[N],r[N];
int que2[N],que3[N],h[N];
int hd2=1,tl2=0,hd3=1,tl3=0;
void add(int x,int y){c[++cnt]=x;r[cnt]=y;}//
void add2(int x){que2[++tl2]=x;}//2
void add3(int x){que3[++tl3]=x;}//3
signed main()
{
	cin>>n;
	H=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) continue;
		if (a[i]==1)
		{
			//23 
			if (hd2<=tl2)
			{
				int x=que2[hd2];
				add(i,h[x]);hd2++;
			}
			else if (hd3<=tl3)
			{
				H++;
				int x=que3[hd3];
				add(i,h[x]);
				add(i,H);
				hd3++;
			}
			else
			{
				H++;
				add(i,H);
			}
		}
		if (a[i]==2)
		{
			//33 
			//
			if (hd3<=tl3)
			{
				H++;
				int x=que3[hd3];
				add(i,h[x]);add(i,H);hd3++;
				add2(i);h[i]=H;
			}
			else
			{
				H++;
				add(i,H);
				add2(i);h[i]=H;
			}
		}
		if (a[i]==3)
		{
			//33
			// 
			if (hd3<=tl3)
			{
				H++;
				int x=que3[hd3];
				add(i,h[x]);add(i,H);hd3++;
				add3(i);h[i]=H;
			}
			else
			{
				H++;
				add(i,H);
				add3(i);h[i]=H;
			}		
		}
	}
	if (hd2<=tl2 || hd3<=tl3) //23-1
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++) printf("%d %d\n",r[i],c[i]);
}