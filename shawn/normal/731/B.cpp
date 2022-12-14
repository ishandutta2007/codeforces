#include<stdio.h>  
#include<string.h>  
using namespace std;  
int a[2004000];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        for(int i=0;i<n;i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        int flag=0;  
        for(int i=n-1;i>=0;i--)  
        {  
            if(a[i]<0)  
            {  
                flag=0;break;  
            }  
            if(i!=0)  
            {  
                if(a[i]%2==1)  
                {  
                    a[i-1]-=1;  
                }  
            }  
            else if(a[i]%2==0)flag=1;  
            else flag=0;  
        }  
        if(flag==1)printf("YES\n");  
        else printf("NO\n");  
    }  
}