#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
string str;
vector<int> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        cin>>str;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(str[i]==str[i-1]) cnt++;
            else
            {
                v.push_back(cnt);
                cnt=1;
            }   
        }
        v.push_back(cnt);
        if(v.size()>1&&str[0]==str[n-1])
        {
            v[v.size()-1]=v[0]+v.back();
            v[0]=0;
        }
        if(v.size()==1) 
        {
            if(v[0]<3) puts("0");
            else printf("%d\n",1+(v[0]-1)/3);
        }
        else
        {
            int ans=0;
            for(int i=0;i<(int)v.size();i++) ans+=v[i]/3;
            printf("%d\n",ans);
        }
    }
    return 0;
}