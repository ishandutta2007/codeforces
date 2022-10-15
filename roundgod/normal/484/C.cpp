#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,d;
string str;
vector<int> p;
vector<int> conp(vector<int> &a,vector<int> &b)
{
    vector<int> c(n);
    for(int i=0;i<n;i++) c[i]=b[a[i]];
    return c;
}
vector<int> get_pow(vector<int> a,int i)
{
    vector<int> s(n);
    for(int j=0;j<n;j++) s[j]=j;
    while(i)
    {
        if(i&1) s=conp(s,a);
        a=conp(a,a);
        i>>=1;
    }
    return s;
}
vector<int> shift,revshift;
vector<int> q;
int main()
{
    cin>>str;
    n=(int)str.size();
    p.resize(n); shift.resize(n); revshift.resize(n);
    for(int i=0;i<n;i++) p[i]=i;
    for(int i=0;i<n;i++) shift[i]=(i+1)%n;
    for(int i=0;i<n;i++) revshift[i]=(i+n-1)%n;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&k,&d);
        q.clear();
        for(int i=0;i<d;i++)
            for(int j=i;j<k;j+=d)
                q.push_back(j);
        for(int j=k;j<n;j++) q.push_back(j);
        vector<int> trans=conp(shift,q);
        trans=get_pow(trans,n-k+1);
        vector<int> rev=get_pow(revshift,n-k+1);
        p=conp(trans,p);
        p=conp(rev,p);
        for(int i=0;i<n;i++) printf("%c",str[p[i]]);
        printf("\n");
    }
    return 0;
}