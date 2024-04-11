#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int n,k;
vector<pair<LL,int> > fact[MAXN];
bool ispr[MAXN];

vector<LL> dis;
LL x[MAXN];
int cntpr[20*MAXN];
int tmp[20*MAXN];
bool validnum[MAXN];
bool used[MAXN];
bool chosen[20*MAXN];
vector<LL> ans;
namespace pollardrho 
{
    ULL gcd(ULL a, ULL b) {return b ? gcd(b, a % b) : a;}

    ULL mulmod(ULL x,ULL y,ULL p)
    {
        ULL z=(long double)x/p*y;
        ULL res=(ULL)x*y-(ULL)z*p;
        return (res+p)%p;
    }

    ULL powmod(ULL b, ULL e, ULL m) 
    {
        ULL r = 1;
        while (e) 
        {
            if (e & 1) r = mulmod(r, b, m);
            b = mulmod(b, b, m);
            e >>= 1;
        }
        return r;
    }

    bool test(ULL n)
    {
        if (n < 3) return n==2;
        // ! The array a[] should be modified if the range of x changes.
        static const ULL a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,  ULLONG_MAX};
        ULL r = 0, d = n-1, x;
        while (~d & 1) d >>= 1, r++;
        for (int i=0; a[i] < n; i++)
        {
            x = powmod(a[i], d, n);
            if (x == 1 || x == n-1) goto next;
            for(int i=0;i<r;i++)
            {
                x = mulmod(x, x, n);
                if (x == n-1) goto next;
            }
            return false;
            next:;
        }
        return true;
    }

    map<ULL, int> mp;
    mt19937_64 gen(time(NULL));

    void PollardRho(ULL n) 
    {
        ULL c, x, y, d;
        while (n % 2 == 0) 
        {
            mp[2]++;
            n /= 2;
        }
        if (n == 1) return;

        if (test(n)) 
        {
            mp[n]++;
            return;
        }

        d = n;
        static int counter = 0;
        while (d == n) 
        {
            x = y = 2;
            d = 1;
            c = gen() % (n - 1) + 1;
            while (d == 1) 
            {
                counter++;
                x = (mulmod(x, x, n) + c) % n;
                y = (mulmod(y, y, n) + c) % n;
                y = (mulmod(y, y, n) + c) % n;
                d = gcd(x > y ? x - y : y - x, n);
            }
        }
        PollardRho(d);
        PollardRho(n / d);
    }

    void work(ULL n,int id) 
    {
        PollardRho(n);
        for(auto p:mp) fact[id].push_back(p);
        mp.clear();
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
        pollardrho::work(x[i],i);
        for(auto p:fact[i]) dis.push_back(p.F);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    
    int cntnum=0,cntpmin=0,cntpmax=0;
    for(int i=1;i<=n;i++)
    {
        if(fact[i].size()==1)
        {
            LL pr=fact[i][0].F;
            int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
            cntpr[id]++;
        }
    }
    for(int i=0;i<(int)dis.size();i++) if(cntpr[i]>=2) {cntpmin+=2; cntpmax+=cntpr[i];}
    for(int i=1;i<=n;i++)
    {
        validnum[i]=true;
        for(int j=0;j<(int)fact[i].size();j++)
        {
            LL pr=fact[i][j].F;
            int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
            if(cntpr[id]<2) validnum[i]=false;
        }
        if(validnum[i]) cntnum++;
    }
    if(k>cntnum||k<=1)
    {
        puts("0");
        return 0;
    }
    else if(k>=cntpmin&&k<=cntnum)
    {
        memset(used,false,sizeof(used));
        for(int i=1;i<=n;i++) 
            if(fact[i].size()==1)
            {
                LL pr=fact[i][0].F;
                int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
                if(cntpr[id]<2) continue;
                if(tmp[id]<2)
                {
                    tmp[id]++;
                    ans.push_back(x[i]);
                    used[i]=true;
                }
            }
        for(int i=1;i<=n;i++)
        {
            if((int)ans.size()==k) break;
            if(used[i]||!validnum[i]) continue;
            ans.push_back(x[i]);
            used[i]=true;
        }
        for(auto x:ans) printf("%lld ",x);
        puts("");
    }
    else if(k%2==0)
    {
        for(int i=0;i<(int)dis.size();i++) 
            if(cntpr[i]>=2)
            {
                chosen[i]=true;
                k-=2;
                if(!k) break;
            }
         for(int i=1;i<=n;i++) 
            if(fact[i].size()==1)
            {
                LL pr=fact[i][0].F;
                int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
                if(chosen[id]&&tmp[id]<2)
                {
                    tmp[id]++;
                    ans.push_back(x[i]);
                }
            }
        for(auto x:ans) printf("%lld ",x);
        puts("");
    }
    else 
    {
        int cid=-1;
        for(int i=0;i<(int)dis.size();i++) 
            if(cntpr[i]>2)
            {
                cid=i; 
                break;
            }
        if(k==2)
        {
            puts("0");
            return 0;
        }
        if(cid!=-1)
        {
            chosen[cid]=true;
            k-=3;
            for(int i=0;i<(int)dis.size();i++) 
            {
                if(!k) break;
                if(i!=cid&&cntpr[i]>=2)
                {
                    chosen[i]=true;
                    k-=2;
                }
            }
            for(int i=1;i<=n;i++) 
                if(fact[i].size()==1)
                {
                    LL pr=fact[i][0].F;
                    int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
                    if(id==cid)
                    {
                        if(tmp[id]<3)
                        {
                            tmp[id]++;
                            ans.push_back(x[i]);
                        }
                    }
                    else if(chosen[id]&&tmp[id]<2)
                    {
                        tmp[id]++;
                        ans.push_back(x[i]);
                    }
                }
            for(auto x:ans) printf("%lld ",x);
            puts("");
        }
        else
        {
            int minlen=INF,nid=-1;
            for(int i=1;i<=n;i++)
            {
                if(validnum[i]&&(int)fact[i].size()>1)
                {
                    if((int)fact[i].size()<minlen)
                    {
                        minlen=fact[i].size();
                        nid=i;
                    }
                }
            }
            if(2*minlen+1<=k)
            {
                k--;
                ans.push_back(x[nid]);
                for(int i=0;i<(int)fact[nid].size();i++)
                {
                    LL pr=fact[nid][i].F;
                    int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
                    chosen[id]=true; k-=2;
                }
                for(int i=0;i<(int)dis.size();i++) 
                {
                    if(!k) break;
                    if(cntpr[i]>=2&&!chosen[i])
                    {
                        chosen[i]=true;
                        k-=2;
                    }
                }
                 for(int i=1;i<=n;i++) 
                    if(fact[i].size()==1)
                    {
                        LL pr=fact[i][0].F;
                        int id=lower_bound(dis.begin(),dis.end(),pr)-dis.begin();
                        if(chosen[id]&&tmp[id]<2)
                        {
                            tmp[id]++;
                            ans.push_back(x[i]);
                        }
                    }
                for(auto x:ans) printf("%lld ",x);
                puts("");
            }
            else
            {
                puts("0");
                return 0;
            }
            
        }
    }
    
    return 0;
}