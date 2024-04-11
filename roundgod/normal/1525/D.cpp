#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int s,n,m;
vector<P> v;
int main()
{
    scanf("%d",&s);
    n=0; m=0;
    for(int i=1;i<=s;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==0) {v.push_back(P(i,0)); n++;}
        else {v.push_back(P(i,1)); m++;}
    }
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int> > q1,q2;//engines and pumps
    //always matching to the left
    for(int i=1;i<=n;i++) q2.push(INF);
    ll ans=0;
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i].S==0)//pump
        {   
            if(q1.size()&&q1.top()+v[i].F<0)
            {
                ans+=q1.top()+v[i].F;
                q2.push(-q1.top()-v[i].F*2);//cost to revert back and make sign of i minus
                q1.pop();
            }
            else q2.push(-v[i].F);//make valid for matching
        }
        else//engine
        {
            ans+=q2.top()+v[i].F;
            q1.push(-q2.top()-v[i].F*2);//cost to revert back and make sign of i minus
            q2.pop();
        }
    }
    printf("%lld\n",ans);
    return 0;
}