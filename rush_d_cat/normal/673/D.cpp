#include<iostream>
using namespace std;
int n,k,a,b,c,d;
int l[1000+2],r[1000+2];
int main(){
    memset(l,0,sizeof(l));
    cin>>n>>k>>a>>b>>c>>d;
    if(n<=4||k<n+1){
        printf("-1\n");
        return 0;
    }
    printf("%d %d ",a,c);
    int pre=c;
    for(int i=1;i<=n;i++){
        if(i!=a&&i!=b&&i!=c&&i!=d)
        {
            r[pre]=i;
            pre=i;
            printf("%d ",i);
        }
    }
    printf("%d %d\n%d %d %d ",d,b,c,a,r[c]);
    pre=r[c];
    for(int i=1;i<=n-5;i++)
    {
        printf("%d ",r[pre]);
        pre=r[pre];
    }
    printf("%d %d\n",b,d);
    return 0;
}