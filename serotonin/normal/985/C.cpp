#include<stdio.h>
#include<math.h>
long long int a[150000],b[150000];

sort(long long int a[], long long int b[], double N)
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


main()
{
    long long int i,j,x,y,n,k,l,N,ans=0;
    scanf("%I64d %I64d %I64d", &n, &k, &l);
    for(i=0;i<n*k;i++) scanf("%I64d", &a[i]);

    double q,p,limit;
    N=n*k;
    p=log(N);
    q=ceil(p/log(2));
    limit=pow(2,q);
    for(i=N;i<limit+50;i++) a[i]=2000000000;
    sort(a,b,limit);

    x=a[0]+l;
    if(a[N-1]<=x) y=N-1;
    else {
        long long int L=0,H=N;
        for(;;) {
            y=(L+H)/2;
            if(a[y]<=x && x<a[y+1]) break;
            if(a[y]>x) H=y;
            if(x>=a[y+1]) L=y;
        }
    }

    if(y+1<n) {
        printf("0\n");
        goto end;
    }

    for(i=0,j=0;i<=y;i+=k) {
        ans+=a[i];
        a[i]=0;
        j++;
    }

    for(i=y;j<n;i--) {
        ans+=a[i];
        if(a[i]!=0) j++;
    }

    printf("%I64d\n", ans);
    end: ;
}