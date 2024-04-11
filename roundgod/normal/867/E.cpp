#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
typedef long long ll;
int n,p[MAXN];
multiset<int> s1,s2,s3;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    multiset<int>::iterator id,ip;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(s1.size()>0) id=s1.begin();
        if(s3.size()>0) ip=s3.begin();
        if((s3.size()>0&&p[i]>*ip&&s1.size()==0)||(s3.size()>0&&s1.size()>0&&p[i]>*ip&&*ip<*id))
        {
            s1.insert(*ip);
            s3.erase(ip);
            s3.insert(p[i]);
        }
        else if(s1.size()>0&&p[i]>*id)
        {
            s2.insert(*id);
            s3.insert(p[i]);
            s1.erase(id);
        }
        else s1.insert(p[i]);
    }
    for(id=s2.begin();id!=s2.end();id++)
        ans-=*id;
    for(id=s3.begin();id!=s3.end();id++)
        ans+=*id;
    printf("%I64d\n",ans);
    return 0;
}