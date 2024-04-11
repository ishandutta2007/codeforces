#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
char s[1000];int tag,i;
int main()  
{  
    scanf("%s",s);  
    int l=strlen(s);  
    if(s[0]=='h')  
    {  
        printf("http://");  
        tag=4;  
    }  
    else if(s[0]=='f')  
    {  
        printf("ftp://");  
        tag=3;  
    }  
    for(i=tag;i<l;i++)  
    {  
        if(i!=tag&&s[i]=='r'&&s[i+1]=='u')  
            break;  
        printf("%c",s[i]);  
    }  
    printf(".ru");  
    if(i+2!=l)  
    printf("/%c",s[i+2]);  
    for(int j=i+3;j<l;j++)  
    {  
        printf("%c",s[j]);  
    }  
    printf("\n");  
    return 0;  
}