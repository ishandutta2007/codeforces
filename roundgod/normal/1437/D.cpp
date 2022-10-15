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
queue<int> que;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        while(que.size()) que.pop();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        int cur=2,cnt=1;
        que.push(0);
        while(cur<=n)
        {
            while(cur+1<=n&&a[cur+1]>=a[cur]) cur++,cnt++;
            int dep=que.front()+1;
            que.pop();
            ans=max(ans,dep);
            for(int i=0;i<cnt;i++) que.push(dep);
            cur++;
            cnt=1;
        }
        printf("%d\n",ans);
    }
}