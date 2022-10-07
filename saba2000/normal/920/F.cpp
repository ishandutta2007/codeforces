#include<bits/stdc++.h>
using namespace std;
long long a[500000];
long long D[1000009];
long long p[1000009];
long long f[500009],n;
void upd(long long x,long long d)
{
    while(x <= n)
    {
        
        f[x] += d;
        x += (x&-x);
    }
}
long long cnt(long long r)
{
    long long ans = 0;
    while(r > 0)
    {
        ans+=f[r];
        r -=(r&-r);
    }
    return ans;
}
main()
{
    D[1]=1;
    for (long long i = 2; i <= 1000000; i++){
        if(p[i]==0)
        for (long long j = i; j <=1000000; j+=i)
        p[j]=i;
        long long x = i,k = 1;
        while(x%p[i]==0) x/=p[i],k++;
        D[i]=D[x]*k;
    }
    long long m;
    cin >> n >> m;
    for (long long i=1; i <= n; i++)
        {scanf("%d",&a[i]);
        upd(i,a[i]);}
    set <long long > S;
    for (long long i = 1; i <= n; i++)
        if(a[i]>2) S.insert(i);
    while(m--)
    {
      int t, l, r;
        scanf("%d%d%d",&t,&l,&r);
        if( t == 2 )  printf ("%lld\n",cnt(r) - cnt (l-1) );
        else
        {
            vector<long long> C;
            auto it = S.lower_bound(l);
            while(it!=S.end() && *it<=r){
            C.push_back(*it);
            it++;}
            for (long long i = 0; i < C.size(); i++)
            {
                long long x =C[i];
                long long d = D[a[x]]-a[x];
                
                upd(x,d);
                a[x] = D[a[x]];
                if(a[x]<=2)
                 S.erase(S.find(x));
            }
        }
    }
    
}