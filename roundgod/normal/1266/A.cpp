#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
string str;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int sum=0,cnteven=0,cntzero=0;
        bool f=false;
        for(int j=0;j<(int)str.size();j++)
        {
            sum+=str[j]-(int)'0';
            cntzero+=(str[j]=='0');
            if((str[j]-(int)'0')%2==0) cnteven++;
        }
        if(sum%3==0&&cntzero&&cnteven>1) puts("red"); else puts("cyan");
    }
    return 0;
}