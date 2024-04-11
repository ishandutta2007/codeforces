#include<stdio.h>
#include<string.h>
#include<math.h>

sort(long int a[], long int b[], double N)
{

    long int i,k=2,j,t,x,y;
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
                    i++;
                    t++;
                }
                else {
                    b[t]=a[j];
                    j++;
                    t++;
                }
                if(t==N) break;
            }
            x=x+k;
            if(t==N) break;
        }

        for(f=0;f<N;f++) a[f]=b[f];
        k=k*2;
    }
}

int main()
{
    long int n,i,j,x,t,a[220000],b[220000],l,h,m,ans=0;
    scanf("%ld", &n);
    for(i=0;i<n;i++) scanf("%ld", &a[i]);

    double q,p,limit;
    p=log(n);
    q=ceil(p/log(2));
    limit=pow(2,q);
    for(i=n;i<limit+50;i++) a[i]=2000000000;
    sort(a,b,limit);

    for(i=0;i<n;i++) {
        t=1;
        for(j=1;j<33;j++) {
            t=t*2;
            x=t-a[i];
            if(x>a[n-1]) {
                ans++;
                break;
            }
            if(x<=0) continue;

            l=0;
            h=n-1;
            m=(l+h)/2;
            for(;;) {
                if(a[m]==x) break;
                if(a[m]<x) l=m+1;
                if(a[m]>x) h=m;
                m=(l+h)/2;
                if(h<=l) break;
            }

            if(a[m]==x) {
                if(m!=i) break;
                if((m>0 && a[m-1]==a[m]) || a[m]==a[m+1]) break;
            }
        }
        if(j==33) ans++;
    }

    printf("%ld\n", ans);
}