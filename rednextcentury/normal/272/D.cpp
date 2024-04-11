#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > vec;
int main()
{
    int n;
    long long ans=1;
    scanf("%d",&n);
    int MOD;
    for (int i=0;i<n;i++)
    {
        int s;
        scanf("%d",&s);
        vec.push_back(make_pair(s,i+1));
    }
    for (int i=0;i<n;i++)
    {
        int s;
        scanf("%d",&s);
        vec.push_back(make_pair(s,i+1));
    }
    sort(vec.begin(),vec.end());
    scanf("%d",&MOD);
    for (int i=0;i<2*n;)
    {
        int j=i;
        int num=0;
        while(j<2*n && vec[j].first==vec[i].first)
            num++,j++;
        for (;i<j;)
        {
            if (i+1<j && vec[i]==vec[i+1])
            {
                i++;
                if (num%2==0)
                    ans=(ans*(num/2))%MOD,ans=(ans*(num-1))%MOD;
                else
                    ans=(ans*((num-1)/2))%MOD,ans=(ans*(num))%MOD;
                num-=2;
            }
            else
                ans*=num,ans%=MOD,num--;
            i++;
        }
    }
    printf("%I64d\n",ans);
}