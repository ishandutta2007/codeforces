#include<stdio.h>
#include<math.h>

long int a[300000],b[300000];

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
    long int N,w,i,k;
    double q,l,limit;

    scanf("%ld %ld", &N, &k);
    for(i=0;i<N;i++) {
        scanf("%ld", &a[i]);
    }
    l=log(N);
    q=ceil(l/log(2));
    limit=pow(2,q);
    for(i=N;i<limit+50;i++) a[i]=1000000000;
    sort(a,b,limit);

    if(k==0) {
        if(a[0]!=1) printf("1\n");
        else printf("-1\n");
        goto end;
    }
    if(k==N) {
        printf("%ld\n", a[k-1]);
        goto end;
    }

    if(a[k-1]==a[k]) printf("-1\n");
    else printf("%ld\n", a[k-1]);

    end: ;
}