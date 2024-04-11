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
int n,k,a[MAXN];
string str;
string ans;
char ch[]={'a','e','i','o','u'};
int main()
{
    scanf("%d",&k);
    for(int i=5;i*i<=k;i++)
    {
        if(k%i) continue;
        if(k/i>=5)
        {
            str="";
            for(int j=0;j<i;j++) str+=ch[j%5];
            for(int j=0;j<k/i;j++)
            {
                ans+=str;
                str=str.substr(1)+str[0];
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}