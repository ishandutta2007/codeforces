#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long n,m,x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>m>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		ans=(n*m+1)/2;//white
		if((x1+y1)%2==0)
		{
//			cerr<<"add "<<(x2-x1+1)*(y2-y1+1)-((x2-x1+1)*(y2-y1+1)+1)/2<<endl;
			ans+=(x2-x1+1)*(y2-y1+1)-((x2-x1+1)*(y2-y1+1)+1)/2;
		}
		else
		{
//			cerr<<"add "<<((x2-x1+1)*(y2-y1+1)+1)/2<<endl;
			ans+=((x2-x1+1)*(y2-y1+1)+1)/2;
		}
		if((x3+y3)%2==0)
		{
//			cerr<<"sub "<<((x4-x3+1)*(y4-y3+1)+1)/2<<endl;
			ans-=((x4-x3+1)*(y4-y3+1)+1)/2;
		}
		else
		{
//			cerr<<"sub "<<(x4-x3+1)*(y4-y3+1)-((x4-x3+1)*(y4-y3+1)+1)/2<<endl;
			ans-=(x4-x3+1)*(y4-y3+1)-((x4-x3+1)*(y4-y3+1)+1)/2;
		}
		long long xmin=max(x3,x1),xmax=min(x2,x4),ymin=max(y3,y1),ymax=min(y2,y4);
		if(xmin>xmax||ymin>ymax);
		else
		{
			if((xmin+ymin)%2==0)
			{
//				cerr<<"sub "<<(xmax-xmin+1)*(ymax-ymin+1)-((xmax-xmin+1)*(ymax-ymin+1)+1)/2<<endl;
				ans-=(xmax-xmin+1)*(ymax-ymin+1)-((xmax-xmin+1)*(ymax-ymin+1)+1)/2;
			}
			else
			{
//				cerr<<"sub "<<((xmax-xmin+1)*(ymax-ymin+1)+1)/2<<endl;
				ans-=((xmax-xmin+1)*(ymax-ymin+1)+1)/2;
			}
		}
		cout<<ans<<' '<<n*m-ans<<endl;
	}
	return 0;
}