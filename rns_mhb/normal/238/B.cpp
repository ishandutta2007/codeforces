#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101010
typedef pair<int,int> PII;
#define X first
#define Y second
PII a[N];
int col[N];
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
int main(){
	//freopen("in.txt","r",stdin);
    int n,h;
    while(scanf("%d%d",&n,&h)>0){
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&a[i].X);
            a[i].Y=i;
            col[i]=1;
        }
        sort(a,a+n);
        int res=a[n-1].X+a[n-2].X-a[0].X-a[1].X;
        int mn=a[0].X+a[1].X+h;
        if(n>2) mn=MIN(mn,a[1].X+a[2].X);
        int mx=a[0].X+a[n-1].X+h;
        if(n>2) mx=MAX(mx,a[n-1].X+a[n-2].X);
        if(res>mx-mn)
        {
            res=mx-mn;
            col[a[0].Y]=2;
        }
        printf("%d\n",res);
        for(i=0;i<n;i++)
            printf("%d%c",col[i],i<n-1?' ':'\n');
    }
    return 0;
}