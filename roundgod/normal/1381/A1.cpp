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
string a,b;
vector<int> ans;
void rev_prefix(string &str,int x)
{
    ans.push_back(x);
    string tmp=str.substr(0,x);
    reverse(tmp.begin(),tmp.end());
    for(int i=0;i<x;i++) str[i]='0'+'1'-tmp[i];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>a;
        cin>>b;
        ans.clear();
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]==b[i]) continue;
            else if(a[0]!=b[i])
            {
                rev_prefix(a,i+1);
            }
            else
            {
                rev_prefix(a,1);
                rev_prefix(a,i+1);
            }
        }
        assert(a==b);
        printf("%d ",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}