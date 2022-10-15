#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str[MAXN];
map<string,int> minp,maxp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        minp.clear(),maxp.clear();
        bool f=false;
        for(int i=0;i<n;i++) 
        {
            cin>>str[i];
            if(!minp[str[i]]) minp[str[i]]=maxp[str[i]]=i+1;
            else maxp[str[i]]=i+1;
            if(str[i][0]==str[i][str[i].size()-1]) f=true;
        }
        for(int i=0;i<n;i++)
        {
            if(str[i].size()>=2)
            {
                string t=str[i];
                reverse(t.begin(),t.end());
                if(minp.count(t)) f=true;
            }
            if(str[i].size()==3)
            {
                string t=str[i];
                reverse(t.begin(),t.end());
                t.pop_back();
                if(minp.count(t)&&minp[t]<i+1) f=true;
                t="";
                t+=str[i][1]; t+=str[i][0];
                if(maxp.count(t)&&maxp[t]>i+1) f=true;
            }
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}