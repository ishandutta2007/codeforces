# include<bits/stdc++.h>
using namespace std;
long long p[100];
int main()
{
    long long a,b;
    cin>>a>>b;
    p[0]=1;
    for (int i=1;i<=61;i++)
        p[i]=p[i-1]*2;
    long long cur=0;
    long long ans=0;
    for (int i=0;i<=60;i++)
    {
        long long h=cur;
        int j=i+1;
        while(j<=60)
        {
            h+=p[j];
            if (h>=a && h<=b)
                ans++;
            j++;
        }
        cur+=p[i];
    }
    cout<<ans<<endl;
}