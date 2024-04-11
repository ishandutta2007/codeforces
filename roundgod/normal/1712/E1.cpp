#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,l,r;
vector<int> divi[MAXN];
int main()
{
    for(int i=1;i<=400000;i++) 
        for(int j=i;j<=400000;j+=i)
            divi[j].push_back(i);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        int len=(r-l+1);
        ll ans=1LL*len*(len-1)*(len-2)/6;
        for(int i=l+2;i<=r;i++)
        {
            int cnt=0;
            for(auto x:divi[i])
            {
                if(x>=i||x<l) continue;
                cnt++;
            }
            ans-=1LL*cnt*(cnt-1)/2;
            if((i%3==0)&&(i%2==0)&&(i/3*2>=l)&&(i/2>=l)) ans--;
            if((i%3==0)&&(i%5==0)&&(i/3*2>=l)&&(i/5*2>=l)) ans--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}