#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],dp[MAXN],odd[MAXN],even[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> st;
int calc(int l,int r,int now,int val)
{
    if(l>r) return 0;
    //printf("%d %d %d %d\n",l,r,now,val);
    int od=odd[r]; dec(od,odd[l-1]);
    int ev=even[r]; dec(ev,even[l-1]);
    int res;
    if(r%2==0) {res=ev; dec(res,od);}
    else {res=od; dec(res,ev);}
    if((now-r)&1) return 1LL*val*res%MOD; else return 1LL*val*(MOD-res)%MOD;
}
int main()
{
    scanf("%d",&n);
    a[0]=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0]=1;
    int coef=0;
    st.push_back(0);
    even[0]=1;
    for(int i=1;i<=n;i++)
    {
        while(st.size()>=2&&a[st.back()]>=a[i])
        {
            //
            dec(coef,calc(st[st.size()-2],st[st.size()-1]-1,i,a[st.back()]));
            st.pop_back();
        }
        add(coef,calc(st.back(),i-1,i,a[i]));
        st.push_back(i);
        dp[i]=coef;
        odd[i]=odd[i-1]; if(i&1) add(odd[i],dp[i]);
        even[i]=even[i-1]; if(i%2==0) add(even[i],dp[i]);
        coef=MOD-coef;
        //printf("%d %d\n",i,dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}