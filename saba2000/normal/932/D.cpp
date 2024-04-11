#include<bits/stdc++.h>
using namespace std;
long long P[400009][23];
long long M[400009][23];
long long  P1[400009][23];
long long S[400009][23];
main()
{
    long long q;
    cin >> q;
    long long c=2;
    long long last=0;
    while(q--)
    {
        long long t;
        scanf("%lld",&t);
        long long R,X;
        scanf("%lld%lld",&R,&X);
        R^=last;
        X^=last;
        if(t==1)
        {
            P[c][0]=R;
            M[c][0]=X;
            S[c][0]=X;
            long long x = P[c][0];
            for (long long i= 1; i<23; i++)

                P[c][i]=P[P[c][i-1]][i-1],
                M[c][i]=max(M[c][i-1],M[P[c][i-1]][i-1]);
            for (long long i= 22; i>=0; i--)
            {
                if(M[x][i] < X) x=P[x][i];
            }
            P1[c][0]=x;
            for (long long i=1; i<23; i++){
                P1[c][i]=P1[P1[c][i-1]][i-1],
                S[c][i]=S[c][i-1]+S[P1[c][i-1]][i-1];
                }

            c++;
        }
        else
        {
            long long s = 0,L = 0,L1=0;
            long long c  = R;
            long long C =c;
            for (long long i =22; i>=0; i--)
            {
                if(P1[c][i]!=0 && s+S[c][i]<=X) L+=(1<<i),s+=S[c][i],c=P1[c][i];
            }
            if(s+S[c][0]<=X) L++;
            printf("%lld\n",L);
            last=L;
        }
    }
}