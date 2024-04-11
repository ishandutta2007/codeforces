#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
namespace io{
    #define re register
    #define ll long long
    #define inf 0x3f3f3f3f
    #define il inline 
    #define in1(a) read(a)
    #define in2(a,b) in1(a),in1(b)
    #define in3(a,b,c) in2(a,b),in1(c)
    #define in4(a,b,c,d) in2(a,b),in2(c,d)
    il void readl(ll &x){
        x=0;ll f=1;char c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
        x*=f;
    }
    il void read(int &x){
        x=0;int f=1;char c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
        x*=f;
    }
}using namespace io;
#define N 200005
int n;
int a[N],b[N];
map <pair<int,int>,int> cnt;
int main(){
    int ans=0,res=0;
    read(n);
    for(re int i=1;i<=n;i++) read(a[i]);
    for(re int i=1;i<=n;i++){
        read(b[i]);
        if(a[i]==0){
            if(b[i]==0) res++;
            continue;
        }
        int gcd=__gcd(a[i],b[i]);
        ans=max(ans,++cnt[make_pair(a[i]/gcd,b[i]/gcd)]);
    }
    printf("%d",ans+res);
    return 0;
}