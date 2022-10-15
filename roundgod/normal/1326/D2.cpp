#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
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
vector<int> v;
int len[MAXN];
void manacher(string str)
{
    int n=(int)str.size();
    for(int i=0;i<(n<<1)-1;i++) len[i]=0;
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i)
    {
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]])
            ++len[i];
        if(q+len[i]-1>r)
            j=i;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        n=(int)str.size();
        int l=0,r=n-1;
        int st=0,llen=0;
        string s="";
        while(l<r&&str[l]==str[r]) {s+=str[l]; l++; r--;}
        str=str.substr(l,r-l+1);
        manacher(str);
        n=(int)str.size();
        for(int i=0;i<(n<<1)-1;i++)
        {
            int l=i-len[i]+1,r=i+len[i]-1;
            if(i%2==0)
            {
                int sz=2*len[i]-1;
                if(sz>llen&&(i/2-len[i]+1==0||i/2-len[i]+sz==n-1))
                {
                    llen=sz;
                    st=i/2-len[i]+1; 
                }
            }
            else
            {
                int sz=2*len[i];
                if(sz>llen&&(i/2-len[i]+1==0||i/2-len[i]+sz==n-1))
                {
                    llen=sz;
                    st=i/2-len[i]+1;
                }
            }
        }
        string t=str.substr(st,llen);
        string ss=s;
        reverse(ss.begin(),ss.end());
        s=s+t+ss;
        cout<<s<<endl;
    }
    return 0;
}