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
int n;
string str;
string add(string str1,string str2)
{
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int n=max(str1.size(),str2.size());
    string ret="";
    int carry=0,res=0;
    for(int i=0;i<n;i++)
    {
        res=carry+(i>=(int)str1.size()?0:str1[i]-'0')+(i>=(int)str2.size()?0:str2[i]-'0');
        ret=(char)(res%10+'0')+ret;
        carry=res/10;
    }
    if(carry) ret="1"+ret;
    return ret;
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    int id1=-1,id2=-1;
    int res1=n-1,res2=n+1;
    for(int i=1;i<=n-1;i++)
    {
        if(str[i]=='0') continue;
        int val=max(i,n-i);
        int dif=val-(n/2);
        if(dif<res1)
        {
            res2=res1;
            id2=id1;
            res1=dif;
            id1=i;
        }
        else if(dif<res2)
        {
            res2=dif;
            id2=i;
        }
    }
    string str1=add(str.substr(0,id1),str.substr(id1));
    if(id2!=-1)
    {
        string str2=add(str.substr(0,id2),str.substr(id2));
        if(str1.size()>str2.size()) str1=str2; else if(str1.size()==str2.size()) str1=min(str1,str2);
    }
    cout<<str1<<endl;
    return 0;
}