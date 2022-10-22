#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> >q;
int n,c,a[100100];
long long s,f[100100];
int main(){
    scanf("%d%d",&n,&c);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]),s+=a[i];
    f[0]=0;
    for (int i=1; i<=n; i++){
        q.push(make_pair(a[i],i));
        if (i>=c){
            while (!q.empty() && q.top().second<=i-c) q.pop();
            f[i]=max(f[i-1],f[i-c]+q.top().first);
        }
    }
    printf("%lld\n",s-f[n]);
    return 0;
}