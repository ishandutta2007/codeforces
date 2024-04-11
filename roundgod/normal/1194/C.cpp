#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int q;
string s,t,p;
int cnt1[26],cnt2[26];
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        cin>>s;
        cin>>t;
        cin>>p;
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        bool f=true;
        for(int i=0;i<(int)s.size();i++) cnt1[s[i]-'a']--;
        for(int i=0;i<(int)t.size();i++) cnt1[t[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(cnt1[i]<0)
            {
                f=false;
                break;
            }
        }
        for(int i=0;i<(int)p.size();i++) cnt2[p[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(cnt1[i]>cnt2[i])
            {
                f=false;
                break;
            }
        }
        int now=0;
        for(int i=0;i<(int)s.size();i++)
        {
            while(now<(int)t.size()&&t[now]!=s[i]) now++;
            if(now>=(int)t.size())
            {
                f=false;
                break;
            }
            now++;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}