#include <bits/stdc++.h>

using namespace std;
long long ret[]={0,1,1
,1
,5
,1
,21
,1
,85
,73
,341
,89
,1365
,1
,5461
,4681
,21845
,1
,87381
,1
,349525
,299593
,1398101
,178481
,5592405,1082401};
void sol(int n)
{
    int ret=0;
    for (int i=1;i<n;i++)
    {
        ret=max(ret,__gcd(n^i,n&i));
    }
    cout<<ret<<endl;
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        long long num=0;
        long long ok=0;
        int bits=0;
        for (int i=0;i<25;i++)
        {
            if ((1<<i)>x)break;
            if (((1<<i)&x)==0)
            {
                ok=1;
                num+=(1<<i);
            }
            else
                bits++;
        }
        if (ok)cout<<num+x<<endl;
        else cout<<ret[bits]<<endl;
    }

}