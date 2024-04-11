#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
bool used[MAXN];
int ask(vector<int> &v)
{
    printf("?");
    for(auto x:v) printf(" %d",x);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d%d",&n,&k);
    if(k%2==0&&(n%2==1))
    {
        printf("-1\n"); fflush(stdout);
        return 0;
    }
    int rem=n%k;
    if(rem)
    {
        if(rem&1) rem+=k;
        else if((rem+k)%2==0&&(rem+k<=(n-k)*2)) rem+=k;
        int now=1,tmp=rem; 
        ll ans=0;
        while(tmp)
        {
            int cur=min((n-k)*2,tmp);
            vector<int> v1,v2; v1.clear(); v2.clear();
            memset(used,false,sizeof(used));
            vector<int> v; v.clear();
            for(int i=now;i<=now+cur-1;i++) {v.push_back(i); used[i]=true;}
            for(int i=1;i<=n;i++)
            {
                if(v.size()==k+cur/2) break;
                if(!used[i]) {v.push_back(i); used[i]=true;}
            }
            for(auto i:v) 
            {
                if(i>=now&&i<=now+cur-1)
                {
                    if(i&1) v1.push_back(i); else v2.push_back(i);
                }
                else {v1.push_back(i); v2.push_back(i);}
            }
            sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
            ans^=ask(v1)^ask(v2);
            tmp-=cur;
            now+=cur;
        }
        for(int i=now;i<=n;i+=k)
        {
            vector<int> v; v.clear();
            for(int j=i;j<=i+k-1;j++) v.push_back(j);
            ans^=ask(v);
        }
        answer(ans);
    }
    else
    {
        int ans=0;
        for(int i=1;i<=n;i+=k)
        {
            vector<int> v; v.clear();
            for(int j=i;j<=i+k-1;j++) v.push_back(j);
            ans^=ask(v);
        }
        answer(ans);
    }
}