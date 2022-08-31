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
    int a[100005];
    int d[100005];
    vector<PII> stk;
    int top;
    int n;


    void preprocess()
    {

    }

    void solve()
    {
            top=0;
            fill(d,-1);
           
            for(int i=n-1;i>=0;i--)
            {
                    vector<PII>::iterator it=upper_bound(stk.begin(),stk.end(),mp(-a[i],n+1));
                    if(it==stk.end())
                    {
                            d[i]=-1;
                            stk.pb(mp(-a[i],i));
                    }
                    else
                    {
                            d[i]=(*it).second-i-1;
                    }
            }
            for(int i=0;i<n;i++)
                    printf("%d ",d[i]);
            printf("\n");
    }

    bool input()
    {
            s(n);
            for(int i=0;i<n;i++)
                    s(a[i]);
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