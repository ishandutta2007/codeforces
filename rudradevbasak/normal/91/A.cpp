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
    int n;
    char s1[10005];
    char s2[1000005];
    int pre[10005][26];



    void preprocess()
    {

    }

    void solve()
    {
           
            int l1=strlen(s1);
            int l2=strlen(s2);
			
           
            for(int i=0;i<26;i++)
            {
                    pre[l1][i]=-1;
                    for(int j=l1-1;j>=0;j--)
                    {
                            pre[j][i]=-1;
                            if(pre[j+1][i]>=0) pre[j][i]=pre[j+1][i];
                            if(s1[j]=='a'+i) pre[j][i]=j;
                    }
            }
           
            int i=0,j=0;
            int ans=1;
            for(;j<l2;j++)
            {
                    int c=s2[j]-'a';
                    if(pre[0][c]==-1)
                    {
                            ans=-1;
                            break;
                    }
                    int ind=pre[i][c];
                    if(ind==-1)
                    {
                            ans++;
                            i=0;
                            ind=pre[i][c];
                    }
                    i=ind+1;
            }
            printf("%d\n",ans);
                   
    }

    bool input()
    {
            scanf("%s",s1);
            scanf("%s",s2);
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