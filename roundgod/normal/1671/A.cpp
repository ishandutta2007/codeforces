#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int cnt=1;
        bool f=true;
        for(int i=1;i<(int)str.size();i++)
        {
            if(str[i]==str[i-1]) cnt++;
            else {if(cnt==1) f=false; cnt=1;}
        }
        if(cnt==1) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}