#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> now;
int guess(int l,int r)
{
    printf("? %d",r-l+1);
    for(int i=l;i<=r;i++) printf(" %d",now[i]);
    printf("\n");
    fflush(stdout);
    string str;
    cin>>str;
    if(str=="YES") return 1; else return 0;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    string str;
    cin>>str; if(str==":)") exit(0);
}
void solve()
{
    int sz=(int)now.size();
    int lb=sz/3,rb=sz*2/3; //[0,lb) [lb,rb) [rb,sz) 
    vector<int> v1;
    if(!guess(0,lb-1))
    {
        if(!guess(0,lb-1))
        {
            for(int i=lb;i<sz;i++) v1.push_back(now[i]);
            swap(now,v1); v1.clear();
            return;
        }
        else
        {
            if(guess(lb,rb-1))
            {
                for(int i=0;i<rb;i++) v1.push_back(now[i]);
                swap(now,v1); v1.clear();
                return;
            }
            else
            {
                for(int i=0;i<lb;i++) v1.push_back(now[i]);
                for(int i=rb;i<sz;i++) v1.push_back(now[i]);
                swap(now,v1); v1.clear();
                return;
            }
        }
    }
    else
    {
        if(guess(lb,rb-1))
        {
            for(int i=0;i<rb;i++) v1.push_back(now[i]);
            swap(now,v1); v1.clear();
            return;
        }
        else
        {
            for(int i=0;i<lb;i++) v1.push_back(now[i]);
            for(int i=rb;i<sz;i++) v1.push_back(now[i]);
            swap(now,v1); v1.clear();
            return;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) now.push_back(i);
    if(n==1) {answer(1);}
    while(now.size()>2) solve();
    answer(now[0]); answer(now[1]);
    return 0;
}