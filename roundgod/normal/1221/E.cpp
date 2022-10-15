#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,a,b,n;
string str;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        cin>>str;
        n=(int)str.size();
        int cnt1=0,cnta=0,cntb=0;
        int cnt=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='X')
            {
                if(cnt>=a) cnta++;
                if(cnt>=b) cntb++;
                if(cnt>=2*b) cnt1++;
                maxi=max(maxi,cnt);
                cnt=0;
            }
            else cnt++;
        }
        if(cnt>=a) cnta++;
        if(cnt>=b) cntb++;
        if(cnt>=2*b) cnt1++;
        maxi=max(maxi,cnt);
        //printf("%d %d %d %d\n",cnt1,cnta,cntb,maxi);
        if(cntb>cnta) {puts("NO"); continue;}
        if(cnt1>=2) {puts("NO"); continue;}
        if(cnt1)
        {
            bool f=false;
            for(int i=0;i<=maxi-a;i++)
            {
                int l=i,r=maxi-a-i;
                if(l>=2*b||r>=2*b) continue;
                if(l>=b&&l<a) continue;
                if(r>=b&&r<a) continue;
                int tmp=0;
                if(l>=a) tmp++;
                if(r>=a) tmp++;
                if((tmp+cnta-1)%2==0) {f=true; break;}
            }
            if(f) puts("YES"); else puts("NO");
            continue;
        }
        if(cnta&1) puts("YES"); else puts("NO");
    }
    return 0;
}