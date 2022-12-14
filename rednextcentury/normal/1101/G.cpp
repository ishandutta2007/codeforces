#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int msb(long long x){
    for(int bit = 30 ; bit >= 0 ; bit--){
        if( (x & (1ll << bit)) )
            return bit;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]=a[i]^a[i-1];
    if (a[n]==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector < pair < long long , long long > > gauss;
    for(int i=1;i<=n;i++)
    {
        long long x = a[i];
        for(auto pp : gauss)
        {
            int bit = pp.second;
            long long num = pp.first;
            if((x & (1ll << bit)))
                x ^= num;
        }
        if(x == 0) continue;
        int bit = msb(x);
        for(auto &pp : gauss)
            if((pp.first & (1ll << bit)))
                pp.first ^= x;
        gauss.push_back({x , bit});
    }
    cout<<gauss.size()<<endl;
}