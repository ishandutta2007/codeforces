    //Data Structure includes
    #include<vector>
    #include<stack>
    #include<set>
    #include<map>
    #include<queue>
    #include<deque>
    #include<string>


    //Other Includes
    #include<iostream>
    #include<algorithm>
    #include<cstring>
    #include<cassert>
    #include<cstdlib>
    #include<cstdio>
    #include<cmath>

    using namespace std;

    #define FOR(i,a,b)                                      for(int i=a;i<b;i++)
    #define REP(i,n)                                        FOR(i,0,n)
    #define pb                                                      push_back
    #define mp                                                      make_pair
    #define s(n)                                            scanf("%d",&n)
    #define sl(n)                                           scanf("%lld",&n)
    #define sf(n)                                           scanf("%lf",&n)
    #define ss(n)                                           scanf("%s",n)
    #define fill(a,v)                                       memset(a, v, sizeof a)
    #define sz                                                      size()
    #define INF                                                     (int)1e9
    #define EPS                                                     1e-9
    #define bitcount                                        __builtin_popcount
    #define all(x)                                          x.begin(), x.end()
    #define gcd                                                     __gcd
    #define maX(a,b)                                        (a>b?a:b)
    #define miN(a,b)                                        (a<b?a:b)

    typedef vector<int> VI;
    typedef vector<vector<int> > VVI;
    typedef long long LL;
    typedef pair<int, int > PII;

    /*Main code begins now */
    int testnum;
    const int maxn=100005;
    int par[maxn];
    int size[maxn];

    int find(int u)
    {
            if(par[u]==u) return u;
            return par[u]=find(par[u]);
    }

    bool unify(int u,int v)
    {
            int cu=find(u),cv=find(v);
            if(cu==cv) return true;
           
            if(size[cu]>size[cv])
            {
                    par[cv]=cu;
                    size[cu]+=size[cv];
            }
            else
            {
                    par[cu]=cv;
                    size[cv]+=size[cu];
            }
            return false;
    }

    int n,m;

    void preprocess()
    {
            for(int i=0;i<maxn;i++)
            {
                    par[i]=i;
                    size[i]=1;
            }
    }
    LL mod=1000000009;
    void solve()
    {
            int a,b;
            LL ans=1;
            for(int i=0;i<m;i++)
            {
                    s(a); s(b);
                    bool z=unify(a,b);
                    if(z)
                    {
                            ans = (ans+ans)%mod;
                    }
                    cout<<(ans-1)<<endl;
            }
           
    }

    bool input()
    {
            s(n); s(m);
            return true;
    }


    int main()
    {
            preprocess();
            int T=1;
            for(testnum=1;testnum<=T;testnum++)
            {
                    if(!input()) break;
                    solve();
            }
    }