//{{{
#include <bits/stdc++.h>
using namespace std;
//types
typedef long long ll;
typedef pair<int,int> pii;
//input
bool SR(int &x){return scanf("%d",&x)==1;}bool SR(ll &x){return scanf("%lld",&x)==1;}
bool SR(double &x){return scanf("%lf",&x)==1;}bool SR(char *s){return scanf("%s",s)==1;}
bool RI(){return true;}
template<typename I,typename... T>bool RI(I &x,T&... tail){return SR(x) && RI(tail...);}
//output
void SP(const int x){printf("%d",x);}void SP(const ll x){printf("%lld",x);}
void SP(const double x){printf("%.16lf",x);}void SP(const char *s){printf("%s",s);}
void PL(){puts("");}
template<typename I,typename... T>void PL(const I x,const T... tail)
{SP(x);if(sizeof...(tail)) putchar(' ');PL(tail...);}
//macro
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
#define pb push_back
#define mkp make_pair
#define F first
#define S second
//debug
#ifdef darry140
template<typename I>
void _DOING(const char *s,I&& x){cerr<<s<<"="<<x<<endl;}//without ','
template<typename I,typename... T>
void _DOING(const char *s,I&& x,T&&... tail)//with ','
{
    int c=0;
    static const char bra[]="({[";
    static const char ket[]=")}]";
    while(*s!=',' || c!=0)//eg. mkp(a,b)
    {
        if(strchr(bra,*s)) c++;
        if(strchr(ket,*s)) c--;
        cerr<<*s++;
    }
    cerr<<"="<<x<<", ";
    _DOING(s+1,tail...);
}
#define debug(...) do{\
    fprintf(stderr,"%s:%d - ",__PRETTY_FUNCTION__,__LINE__);\
    _DOING(#__VA_ARGS__,__VA_ARGS__);\
}while(0)
template<typename It>
ostream& _OUTC(ostream &s,It b,It e)//container
{
    s<<"{";
    for(auto it=b;it!=e;it++) s<<(it==b?"":" ")<<*it;
    s<<"}";
    return s;
}
template<typename A,typename B>
ostream& operator <<(ostream&s, const pair<A,B> &p){return s<<"("<<p.F<<","<<p.S<<")";}
template<typename A,typename B>
ostream& operator <<(ostream&s, const map<A,B> &c){return _OUTC(s,ALL(c));}
template<typename T>
ostream& operator <<(ostream&s, const set<T> &c){return _OUTC(s,ALL(c));}
template<typename T>
ostream& operator <<(ostream&s, const vector<T> &c){return _OUTC(s,ALL(c));}
#else
#define debug(...)
#endif
//}}}
const int maxn=5e5+5;
struct SA
{
    char s[maxn];
    int n;
    int _r[2][2*maxn],*rnk;
    int sa[maxn];
    void init(char *t,int _n)
    {
        n=_n;
        REP(i,n) s[i]=t[i];
        REP(i,2*n+1) _r[0][i]=_r[1][i]=0;
    }
#define PER1(i,a,b) for(int i=a;i>=b;i--)
    int r1(int *cur)
    {
        static int cnt[maxn];
        int hi=*max_element(s,s+n);
        memset(cnt,0,sizeof(int)*(hi+1));
        REP(i,n) cnt[cur[i]=s[i]]++;
        REP(i,hi) cnt[i+1]+=cnt[i];
        PER1(i,n-1,0) sa[cnt[cur[i]]--]=i;
        return hi;
    }
    bool det(int *prv,int i,int j,int k)
    {return prv[i]!=prv[j]||prv[i+k]!=prv[j+k];}
    int rk(int *prv,int *cur,int k,int siz)
    {
        static int tmp[maxn],cnt[maxn];
        int pt=0;
        REP1(i,n-k,n-1) tmp[++pt]=i;
        REP1(i,1,n) if(sa[i]>=k) tmp[++pt]=sa[i]-k;

        memset(cnt,0,(siz+1)*sizeof(int));
        REP(i,n) cnt[prv[i]]++;//REP1(i,1,n) cnt[prv[tmp[i]]]++;
        REP(i,siz) cnt[i+1]+=cnt[i];
        PER1(i,n,1) sa[cnt[prv[tmp[i]]]--]=tmp[i];

        int tot=cur[sa[1]]=1;
        REP1(i,2,n)
        {
            if(det(prv,sa[i-1],sa[i],k)) tot++;
            cur[sa[i]]=tot;
        }
        return tot;
    }
    int h[maxn];
    void build()
    {
        int *prv=_r[0],*cur=_r[1];
        int siz=r1(cur);
        for(int k=1;;k*=2)
        {
            swap(prv,cur);
            siz=rk(prv,cur,k,siz);
            if(siz==n) break;
        }

        rnk=cur;
        REP(i,n) sa[i]=sa[i+1];
        REP(i,n) rnk[i]--;

        REP(i,n)
        {
            int &me=h[rnk[i]];
            if(rnk[i]==0) me=0;
            else
            {
                if(i==0) me=0;
                else me=max(0,h[rnk[i-1]]-1);//ERR!
                while(s[i+me]==s[sa[rnk[i]-1]+me]) me++;
            }
        }
    }
} sa;
char s[maxn];
int n;
void read()
{
    RI(n,s);
}
typedef unsigned long long ull;
ull v[maxn];
ull myrand()
{
    ull ret=0;
    REP(i,8) ret=(ret<<8)^rand();
    return ret;
}
ull _res[maxn],*res;
void build()
{
    srand(time(0));
    REP(i,n) v[i]=myrand();
    sa.init(s,n);
    sa.build();

    vector<int> id;
    vector<char> st;
    res=_res+1;
    ull cur=0;
    REP(i,n)
    {
        if(SZ(st) && st.back()=='(' && s[i]==')')
        {st.pop_back();cur^=v[id.back()];id.pop_back();}
        else {st.pb(s[i]);id.pb(i);cur^=v[id.back()];}
        res[i]=cur;
    }
}
void sol()
{
    vector<pii> q;
    REP(i,n) q.pb(mkp(i-1,i+sa.h[sa.rnk[i]]));//i-1
    sort(ALL(q),[&](pii a,pii b){return a.S>b.S;});
    int pt=n;ll ans=0;
    map<ull,int> mp;
    for(auto cur:q)
    {
        while(pt>cur.S) mp[res[--pt]]++;
        ans+=mp[res[cur.F]];
    }
    PL(ans);
}
int main()
{
    read();
    build();
    sol();
    return 0;
}