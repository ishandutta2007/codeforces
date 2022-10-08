#include<cstdio>
int n;
int main()
{
    scanf("%d",&n);
    if(n==1){printf("a\na\nb\nb\n");return 0;}
    if(n==2){printf("aa\nbb\ncc\ndd\n");return 0;}
    if(n==3){printf("aab\nzzb\nbaa\nbzz\n");return 0;}
    if(n==4){printf("yyzz\nbccb\nbxxb\nyyaa\n");return 0;}
    if(n%2==1)
    {
        for(int i=0;i<n/2;i++)printf("%s",(i%2==0)?"aa":"bb");puts("c");
        for(int i=0;i<n/2;i++)printf("%s",(i%2==1)?"aa":"bb");puts("c");
        printf("c");for(int i=0;i<n/2;i++)printf("%s",(i%2==1)?"dd":"ee");puts("");
        printf("c");for(int i=0;i<n/2;i++)printf("%s",(i%2==0)?"dd":"ee");puts("");
        return 0;
    }
    if(n%4==2)
    {
        for(int i=0;i<n/2;i++)printf("%s",(i%2==0)?"aa":"bb");puts("");
        for(int i=0;i<n/2;i++)printf("%s",(i%2==1)?"aa":"bb");puts("");
        printf("c");for(int i=1;i<n/2;i++)printf("%s",(i%2==0)?"dd":"ee");puts("c");
        printf("c");for(int i=1;i<n/2;i++)printf("%s",(i%2==1)?"dd":"ee");puts("c");
    }
    if(n%4==0)
    {
        for(int i=0;i<n/4;i++)printf("yyzz");puts("");
        printf("bxxe");for(int i=1;i<n/4-1;i++)printf("ecce");puts("eccb");
        printf("bppf");for(int i=1;i<n/4-1;i++)printf("fxxf");puts("fxxb");
        for(int i=0;i<n/4;i++)printf("yyaa");puts("");
    }
    return 0;
}