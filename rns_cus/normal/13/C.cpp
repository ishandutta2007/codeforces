///c
#include<stdio.h>
#include<algorithm>
using namespace std;

#define N 5500

int a[N],b[N];

__int64 ans[N],mns[N];
int main()
{
///    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b,b+n);
    int tot=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[tot])continue;
        b[++tot]=b[i];
    }
    tot++;
    for(int i=0;i<n;i++){

        for(int j=0;j<tot;j++){
            int rans=a[i]-b[j];
            if(rans<0)rans=-rans;
            ans[j]=rans+mns[j];
        }
        __int64 mn=ans[0];
        for(int j=0;j<tot;j++){
            if(mn>ans[j])mn=ans[j];
            mns[j]=mn;
        }
    }
    printf("%I64d\n",mns[tot-1]);
    return 0;
}