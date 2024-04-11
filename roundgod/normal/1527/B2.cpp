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
string str;
int get_value(string &str)
{
    int cnt=0;
    for(int i=0;i<n;i++) if(str[i]=='0') cnt++;
    if((n&1)&&(str[n/2]=='0'))
    {
        if(cnt>1) return 1; else return -1;
    }
    else
    {
        if(cnt) return -2; else return 0;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        string tmp=str; reverse(tmp.begin(),tmp.end());
        int val=0;
        if(tmp==str) val=get_value(str);
        else
        {
            for(int i=0;i<n/2;i++)
                if(str[i]!=str[n-1-i]) {val++; str[i]=str[n-1-i]='1';}
            int res=get_value(str);
            val=max(val+res,val-2-res);
        }
        if(val>0) puts("ALICE"); else if(val<0) puts("BOB"); else puts("DRAW");
    }
    return 0;
}