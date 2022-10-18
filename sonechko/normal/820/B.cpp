#include<bits/stdc++.h>
using namespace std;
#define ld long double

main()
{
    ld n;
    ld a;
    cin>>n>>a;
    ld b=180/n;
    ld ans=1000000000000000000;
    int res=0;
    cout.precision(10);
    cout<<fixed;
    for(int i=3;i<=(int)n;++i)
    {
        ld p=(ld)(n-i+1)*b;
        if(abs(p-a)-ans<0.00000000001)
        {
            ans=abs(p-a);
            res=i;
        }
    }
    cout<<1<<" "<<2<<" "<<res;
}