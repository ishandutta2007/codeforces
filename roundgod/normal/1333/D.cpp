#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
char str[MAXN+1];
vector<vector<int> >ans;
vector<vector<int> >fans;
ll sum=0;
bool go()
{
    vector<int> tmp;
    for(int i=1;i<=n-1;i++)
    {
        if(str[i]=='R'&&str[i+1]=='L') tmp.push_back(i);
    }
    if(!tmp.size()) return false;
    else
    {
        for(auto i:tmp) swap(str[i],str[i+1]);
        ans.push_back(tmp);
        sum+=(int)tmp.size();
        return true;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    while(go());
    if((int)ans.size()>k||sum<k) puts("-1");
    else
    {
        int need=k-(int)ans.size();
        for(auto &x:ans)
        {
            reverse(x.begin(),x.end());
            int tot=min((int)x.size()-1,need);
            need-=tot;
            for(int i=0;i<tot;i++) 
            {
                vector<int> tmp;
                tmp.push_back(x.back());
                x.pop_back();
                fans.push_back(tmp);
            }
            fans.push_back(x);
        }
        for(auto x:fans)
        {
            printf("%d",(int)x.size());
            for(auto y:x) printf(" %d",y);
            puts("");
        }
    }
    return 0;
}