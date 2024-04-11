#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
int v[MAXN];
set<int> s;
string str;
int cnt=0;
vector<int> id;
vector<P> p;
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    bool f=true;
    int tot=0;
    for(int i=0;i<2*n;i++)
    {
        cin>>str;
        if(str[0]=='+') {id.push_back(tot++); p.push_back(P(1,tot-1));}
        else
        {   
            int x;
            scanf("%d",&x);
            if(!id.size()) f=false;
            else
            {
                ans[id.back()]=x;
                id.pop_back();
            }
            p.push_back(P(2,x));
        }
    }
    if(!f) puts("NO");
    else
    {
        for(auto x:p)
        {
            if(x.F==1)
            {
                s.insert(ans[x.S]);
            }
            else
            {
                if(*s.begin()!=x.S) f=false;
                if(s.size()) s.erase(s.begin());
            }   
        }
        if(!f) puts("NO");
        else
        {
            puts("YES");
            for(int i=0;i<n;i++) printf("%d ",ans[i]);
        }
    }
    return 0;
}