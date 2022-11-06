#include<stdio.h>
#include<math.h>


int sort(int a[], int b[], double N)
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
    int n,odd=0,even=0,i,j,x,a[150],b[150];
    scanf("%d", &n);
    for(i=0;i<n/2;i++) scanf("%d", &a[i]);
    int N=n/2;

    double q,l,limit;
    l=log(N);
    q=ceil(l/log(2));
    limit=pow(2,q);
    for(i=N;i<limit+50;i++) a[i]=100000000;
    sort(a,b,limit);


    for(i=1;i<=n/2;i++) {
        x=a[i-1];
        even+=fabs(x-2*i);
        odd+=fabs(x-2*i+1);
    }
    if(odd>even) printf("%d\n", even);
    else printf("%d\n", odd);
}