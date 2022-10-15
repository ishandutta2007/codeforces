#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
string str;
string ss="abacaba";
int check(string str)
{
    int cnt=0;
    for(int i=0;i<n-6;i++)
    {
        if(str.substr(i,7)==ss) cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cin>>str;
        int cnt=0;
        if(check(str)>1) {puts("No"); continue;}
        bool flag=false;
        for(int i=0;i<n-6;i++)
        {
            bool f=true;
            string tmp=str;
            for(int j=i;j<i+7;j++) if(str[j]!='?'&&str[j]!=ss[j-i]) {f=false; break;}
            if(f)
            {
                for(int j=i;j<i+7;j++) tmp[j]=ss[j-i];
                if(check(tmp)==1)
                {
                    flag=true;
                    puts("Yes");
                    for(int j=0;j<n;j++) if(tmp[j]=='?') tmp[j]='d';
                    cout<<tmp<<endl;
                    break;
                }
            }
        }
        if(!flag) puts("No");
    }
    return 0;
}