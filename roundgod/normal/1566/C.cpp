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
string s[2];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s[0]; cin>>s[1];
        int last=1,ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=(s[0][i]=='1')+(s[1][i]=='1');
            if(cnt==1) 
            {
                if(last==0) ans++;
                ans+=2; last=1;
            }
            else if(cnt==0)
            {
                if(last==2) {ans+=2; last=1;}
                else if(last==0) {ans++; last=0;}
                else last=0;
            }
            else
            {
                if(last==0) {ans+=2; last=1;}
                else last=2;
            }
        }
        if(last==0) ans++;
        printf("%d\n",ans);
    }
    return 0;
}