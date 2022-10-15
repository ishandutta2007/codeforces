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
char str[MAXN];
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
vector<int> id;
int tot;
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    int l=1,r=n;
    while(l<=r)
    {
        if(str[l]=='('&&str[r]==')')
        {
            id.push_back(l); id.push_back(r);
            l++; r--;
        }
        else if(str[l]==')') l++;
        else r--;
    }
    if(!id.size()) puts("0");
    else
    {
        puts("1");
        printf("%d\n",(int)id.size());
        sort(id.begin(),id.end());
        for(auto x:id) printf("%d ",x);
        puts("");
    }
    return 0;
}