#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int n=str.size();
        int l=0,r=n-1;
        while(str[l]=='0'&&l<=r) l++;
        while(str[r]=='0'&&l<=r) r--;
        int ans=0;
        for(int i=l;i<=r;i++) if(str[i]=='0') ans++;
        printf("%d\n",ans);
    }
    return 0;
}