#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
string str;
vector<int> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        cin>>str;
        v.clear();
        int last=-INF,ans=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='W')
            {
                if(last==i-1) ans+=2; else {if(last!=-INF) v.push_back(i-last-1); ans++;}
                last=i;
            }
        }
        if(last==-INF)
        {
            printf("%d\n",k==0?0:2*k-1);
            continue;
        }
        sort(v.begin(),v.end());
        int s=0;
        for(int i=0;i<n;i++) if(str[i]=='L') s++;
        if(s<=k) 
        {
            printf("%d\n",2*n-1);
            continue;
        }
        ans+=2*k;
        int sum=0;
        for(int i=0;i<(int)v.size();i++)
        {
            sum+=v[i];
            if(sum>k) break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}