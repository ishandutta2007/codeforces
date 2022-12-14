# include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k,l,r;
    cin>>l>>r>>k;
    long long x=1;
    bool p=0;
    while(1)
    {
        if (x>=l && x<=r)
            p=1,printf("%I64d ",x);
        if (r/x<k)
            break;
        x*=k;
    }
    if (!p)
    {
        printf("-1\n");
    }
}