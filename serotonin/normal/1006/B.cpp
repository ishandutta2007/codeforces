#include<stdio.h>
#include<math.h>
const int c=1000000000;
int pa[50000],pb[50000],a[65600],b[65600],ab[65000];

sort(int a[],int b[], double N)
{
    int i,k=2,j,t,x,y;
    int f;
    while(k<=N) {
        x=0;
        t=0;
        for(;;) {
            y=(x*2+k)/2;
            i=x;
            j=y;
            for(f=0;f<k;f++) {
                if((a[i]<=a[j] && i<y) || j==x+k) {
                    b[t]=a[i];
                    pb[t]=pa[i];
                    i++;
                    t++;
                }
                else {
                    b[t]=a[j];
                    pb[t]=pa[j];
                    j++;
                    t++;
                }
                if(t==N) break;
            }
            x=x+k;
            if(t==N) break;
        }

        for(f=0;f<N;f++) {
            a[f]=b[f];
            pa[f]=pb[f];
        }
        k=k*2;
    }
}


int main()
{
    int t,h,ans=0,r=0;
    int n,k,w,i,x=0,y;
    double q,l,limit;

    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++) scanf("%d", &a[i]);

    l=log(n);
    q=ceil(l/log(2));
    limit=pow(2,q);
    for(i=n;i<limit+50;i++) a[i]=c;
    for(i=0;i<limit+50;i++) pa[i]=i;
    sort(a,b,limit);


    for(i=n-1;i>n-1-k;i--) {
        ans+=a[i];
        ab[r]=pa[i]+1;
        r++;
    }
    printf("%d\n", ans);

    l=log(r);
    q=ceil(l/log(2));
    limit=pow(2,q);
    for(i=r;i<limit+50;i++) ab[i]=c;
    sort(ab,b,limit);

    for(i=0;i<r;i++) {
        y=ab[i]-x;
        if(i<r-1) printf("%d ", y);
        else printf("%d\n", n-x);
        x=ab[i];
    }
}