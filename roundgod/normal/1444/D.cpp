#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000 
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
vector<int> h,v;
typedef bitset<1000001> bs; 
vector<int> half_sum(vector<int> &v)
{
    int n=(int)v.size(),s=0;
    for(int i=0;i<n;i++) s+=v[i];
    if(s&1) return vector<int>{-1};
    bs b[n+1];
    b[0].set(0);
    for(int i=0;i<n;i++) b[i+1]=b[i]|(b[i]<<v[i]);
    if(!b[n].test(s/2)) return vector<int>{-1};
    int cur=s/2;
    vector<int> tmp;
    for(int i=n-1;i>=0;i--)
    {
        if(cur>=v[i]&&b[i].test(cur-v[i]))
        {
            tmp.push_back(i);
            cur-=v[i];
        }
    }
    return tmp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        h.clear(); v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) 
        {
            int x;
            scanf("%d",&x);
            h.push_back(x);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++) 
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        if(n!=m) {puts("No"); continue;}
        vector<int> lh=half_sum(h);
        vector<int> lv=half_sum(v);
        if(lh[0]==-1||lv[0]==-1) {puts("No"); continue;}
        vector<int> rh,rv;
        sort(lh.begin(),lh.end());
        sort(lv.begin(),lv.end());
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(cur<(int)lh.size()&&lh[cur]==i) cur++;
            else rh.push_back(i);
        }
        cur=0;
        for(int i=0;i<m;i++)
        {
            if(cur<(int)lv.size()&&lv[cur]==i) cur++;
            else rv.push_back(i);
        }
        puts("Yes");
        if(lv.size()>rv.size()) swap(lv,rv);
        if(lh.size()<rh.size()) swap(lh,rh);
        for(int i=0;i<(int)lv.size();i++) lv[i]=v[lv[i]];
        for(int i=0;i<(int)rv.size();i++) rv[i]=v[rv[i]];
        for(int i=0;i<(int)lh.size();i++) lh[i]=h[lh[i]];
        for(int i=0;i<(int)rh.size();i++) rh[i]=h[rh[i]];
        sort(lv.begin(),lv.end(),greater<int>());
        sort(lh.begin(),lh.end());
        sort(rv.begin(),rv.end(),greater<int>());
        sort(rh.begin(),rh.end());
        assert(lv.size()+rv.size()==lh.size()+rh.size());
        int nx=0,ny=0;
        for(int i=0;i<(int)lv.size();i++)
        {
            ny+=lv[i];
            printf("%d %d\n",nx,ny);
            nx+=lh[i];
            printf("%d %d\n",nx,ny);
        }
        for(int i=0;i<(int)lh.size()-(int)lv.size();i++)
        {
            ny-=rv[i];
            printf("%d %d\n",nx,ny);
            nx+=lh[i+(int)lv.size()];
            printf("%d %d\n",nx,ny);
        }
        for(int i=0;i<(int)rh.size();i++)
        {
            ny-=rv[i+(int)lh.size()-(int)lv.size()];
            printf("%d %d\n",nx,ny);
            nx-=rh[i];
            printf("%d %d\n",nx,ny);
        }
    }
    return 0;
}