#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int ans[MAXN];
vector<int> has[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        bool f=false;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                f=true;
                has[i/j].push_back(i);
                break;
            }
        }
        if(!f) has[1].push_back(i);
    }
    int tot=0,res=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)has[i].size();j++)
            ans[++tot]=res;
        res++;
    }
    for(int i=2;i<=n;i++) printf("%d ",ans[i]);
    puts("");
}