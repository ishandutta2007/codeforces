#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str[MAXN];
map<string,int> cnt;
vector<pair<string,string> >v;
string ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        cin>>str[i];
        cnt[str[i]]++;
    }
    for(auto p:cnt)
    {
        string s=p.F;
        string t=s;
        reverse(t.begin(),t.end());
        while(s==t&&cnt[s]>=2)
        {
            cnt[s]-=2;
            v.push_back(make_pair(s,t));
        }
        while(s!=t&&cnt[s]&&cnt[t])
        {
            cnt[s]--;
            cnt[t]--;
            v.push_back(make_pair(s,t));
        }
    }
    ans="";
    for(auto p:cnt)
    {
        string s=p.F;
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t&&cnt[s])
        {
            ans=s;
            break;
        }
    }
    for(auto p:v)
    {
        ans=ans+p.S;
        ans=p.F+ans;
    }
    printf("%d\n",(int)ans.size());
    cout<<ans<<endl;
    return 0;
}