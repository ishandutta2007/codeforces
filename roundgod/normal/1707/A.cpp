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
int t,n,q,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        int tmp=q;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(a[i]>tmp) tmp--;}
        if(tmp>=0) {for(int i=0;i<n;i++) printf("1"); puts(""); continue;}
        tmp=0;
        string ans="";
        for(int i=n;i>=1;i--)
        {
            if(a[i]<=tmp) ans+='1';
            else if(tmp==q) ans+='0';
            else {ans+='1'; tmp++;}
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}