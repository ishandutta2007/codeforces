#include<iostream>
using namespace std;
int t,x1,y1,z1,x2,y2,z2,minn;
int main()
{
    scanf("%d",&t);
    while(t--)
	{
        scanf("%d %d %d\n%d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
        minn=min(x1,z2);
        x1-=minn;
		z2-=minn;
        minn=min(z1,z2);
        z1-=minn;
		z2-=minn;
        cout<<(min(z1,y2)-min(y1,z2))*2<<endl;
    }
    return 0;
}