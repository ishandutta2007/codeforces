#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
bool cmp(string x,string y) {return x.size()<y.size();}
void ssrt(string &str)
{
    vector<char> vv;
    vv.clear();
    for(int i=0;i<(int)str.size();i++) vv.push_back(str[i]);
    sort(vv.begin(),vv.end());
    for(int i=0;i<(int)str.size();i++) str[i]=vv[i];
}
multiset<string> ask(int l,int r)
{
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int len=r-l+1;
    multiset<string> ret;
    for(int i=0;i<len*(len+1)/2;i++)
    {
        string str;
        cin>>str;
        ssrt(str);
        ret.insert(str);
    }
    return ret;
}
vector<string> v;
int cnt[26];
char getch(string x,string y)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<(int)y.size();i++) cnt[y[i]-'a']++;
    for(int i=0;i<(int)x.size();i++) cnt[x[i]-'a']--;
    for(int i=0;i<26;i++) if(cnt[i]) return (char)('a'+i);
    return 'a';
}
void answer(string str)
{
    printf("! %s\n",str.c_str());
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    multiset<string> s1,s2;
    if(n==1)
    {
        s1=ask(1,1);
        answer(*s1.begin());
    }
    s1=ask(1,n); s2=ask(2,n);
    for(auto x:s2) s1.erase(s1.find(x));
    for(auto x:s1) v.push_back(x);
    sort(v.begin(),v.end(),cmp);
    string ss=v[0];
    for(int i=1;i<(int)v.size();i++) ss+=getch(v[i-1],v[i]);
    answer(ss);
    return 0;
}