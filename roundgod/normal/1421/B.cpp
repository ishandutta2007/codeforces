#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) cin>>str[i];
        int cnt0=0,cnt1=0;
        cnt0+=(str[0][1]!='0')+(str[1][0]!='0')+(str[n-1][n-2]!='1')+(str[n-2][n-1]!='1');
        cnt1+=(str[0][1]!='1')+(str[1][0]!='1')+(str[n-1][n-2]!='0')+(str[n-2][n-1]!='0');
        v.clear();
        if(cnt0<=2)
        {
            if(str[0][1]!='0') v.push_back(P(1,2));
            if(str[1][0]!='0') v.push_back(P(2,1));
            if(str[n-1][n-2]!='1') v.push_back(P(n,n-1));
            if(str[n-2][n-1]!='1') v.push_back(P(n-1,n));
        }
        else
        {
            assert(cnt1<=2);
            if(str[0][1]!='1') v.push_back(P(1,2));
            if(str[1][0]!='1') v.push_back(P(2,1));
            if(str[n-1][n-2]!='0') v.push_back(P(n,n-1));
            if(str[n-2][n-1]!='0') v.push_back(P(n-1,n));
        }
        printf("%d\n",(int)v.size());
        for(auto p:v) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}