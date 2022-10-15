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
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int n=(int)str.size();
        bool one=false;
        int zero=0;
        for(int i=0;i<n;i++) 
        {
            if(str[i]=='0') 
            {
                if(i==0||str[i-1]!='0') zero++;
            }
            if(str[i]=='1') one=true;
        }
        if(!zero) {puts("0"); continue;}
        if(zero==1||!one) {puts("1"); continue;}
        puts("2");
    }
    return 0;
}