#include<bits/stdc++.h>
using namespace std;
int s[12000023],d[20000099],j;
main()
{

    for (int i=2; i<=10000000; i++)
    {
        if(s[i]==0)
        {
            s[i]=i;
            for (j=(i<<1); j<=10000000; j+=i)
                if(s[j]==0) s[j]=i;
        }

    }
    int n,m;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        while(x>1)
    {
        d[s[x]]++;
        int t=s[x];
        while(x%t==0) x/=t;
    }
    }
    cin>>m;
    for (int i=2; i<=1e7; i++)
    {d[i]+=d[i-1];
    //cout<<d[i]<<endl;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        if(l>1e7) printf("0\n");
        else {r=min(r,(int)1e7);
        printf("%d\n",d[r]-d[l-1]);}
    }

}
//2^4*5^3