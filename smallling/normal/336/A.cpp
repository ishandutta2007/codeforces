#include<cstdio>
#include<cmath>

using namespace std;

int x,y,mid;

int main()
{
	scanf("%d%d",&x,&y);
	mid=abs(x)+abs(y);
	if(x>0)  
    {  
        if(y>0)  
            printf("0 %d %d 0",mid,mid);  
        else  
            printf("0 -%d %d 0",mid,mid);  
    }  
    else  
    {  
        if(y>0)
            printf("-%d 0 0 %d",mid,mid);  
        else  
            printf("-%d 0 0 -%d",mid,mid);  
    }  
}