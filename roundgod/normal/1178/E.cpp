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
int s[3];
char get()
{
    for(char ch='a';ch<='c';ch++) if(s[ch-'a']>1) return ch;
    return 'a';
}
int main()
{
    cin>>str;
    n=(int)str.size();
    string t="";
    if(n&1)
    {
        int pos=n/2;
        t+=str[pos];
        int l=pos-1,r=pos+1;
        while(l-1>=0)
        {
            s[0]=s[1]=s[2]=0;
            s[str[l]-'a']++;
            s[str[l-1]-'a']++;
            s[str[r]-'a']++;
            s[str[r+1]-'a']++;
            char ch=get();
            t+=ch;
            l-=2;
            r+=2;
        }
        for(int i=(int)t.size()-1;i>=0;i--) cout<<t[i];
        for(int i=1;i<(int)t.size();i++) cout<<t[i];
    }
    else
    {
        int l,r,pos=0;
        if(n%4==0) {l=n/2-1,r=l+1;}
        else
        {
            pos=n/2-1;
            l=pos-1;
            r=pos+2;
        }
        while(l-1>=0)
        {
            s[0]=s[1]=s[2]=0;
            s[str[l]-'a']++;
            s[str[l-1]-'a']++;
            s[str[r]-'a']++;
            s[str[r+1]-'a']++;
            char ch=get();
            t+=ch;
            l-=2;
            r+=2;
        }
        for(int i=(int)t.size()-1;i>=0;i--) cout<<t[i];
        if(n%4==2) cout<<str[pos];
        for(int i=0;i<(int)t.size();i++) cout<<t[i];
    }
    return 0;
}