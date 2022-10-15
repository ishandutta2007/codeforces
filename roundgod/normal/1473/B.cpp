#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str[2];
int sz0,sz1;
bool check(string &s,string &t)
{
    int szs=(int)s.size(),szt=(int)t.size();
    if(szs%szt) return false;
    for(int i=0;i<szs;i++) if(s[i]!=t[i%szt]) return false;
    return true; 
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str[0];
        cin>>str[1];
        int ans=-1;
        string res="";
        for(int len=1;len<=20;len++) 
        {
            string s="";
            for(int j=0;j<len;j++) s+=str[0];
            string t=str[1];
            if(check(s,t)) {ans=len; res=s; break;}
        }
        if(ans==-1) puts("-1"); else cout<<res<<endl;
    }
    return 0;
}