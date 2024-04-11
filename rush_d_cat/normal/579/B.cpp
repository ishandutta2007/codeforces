    #include<cstdio>  
    #include <cstring>  
    #include<cmath>  
    #include<iostream>  
    #include<algorithm>  
    #include<vector>  
    #include <map>  
    using namespace std;  
      
    int a[1000005][2],ans[1000];  
      
    int main()  
    {  
        int n,i,j,x;  
        scanf("%d",&n);  
        for( i=1;i<=2*n;i++)  
        {  
            for(j=1;j<i;j++)  
            {  
                scanf("%d",&x);  
                a[x][0]=i;  
                a[x][1]=j;  
            }  
        }  
        for(i=1000000;i>0;i--)  
        {  
            if(ans[a[i][0]]==0 && ans[a[i][1]]==0)  
            {  
                ans[a[i][0]]=a[i][1];  
                ans[a[i][1]]=a[i][0];  
            }  
        }  
        for(int i=1;i<=2*n;i++)  
        {  
            printf("%d ",ans[i]);  
        }  
        printf("\n");  
        return 0;  
    }