#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
int x[MAXN];
int dir[MAXN];
bool isodd[MAXN];
int ans[MAXN],save[MAXN];
string str;
vector<int> odd,even;
vector<int> st;
struct node
{
    int pos,d,id;
}p[MAXN];
bool cmp(node x,node y)
{
    return x.pos<y.pos;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&p[i].pos);
        for(int i=0;i<n;i++)
        {
            cin>>str;
            if(str[0]=='L') p[i].d=0; else p[i].d=1;
            p[i].id=i;
        }
        sort(p,p+n,cmp);
        for(int i=0;i<n;i++) x[i]=p[i].pos,dir[i]=p[i].d,save[i]=p[i].id;
        odd.clear(); even.clear();
        for(int i=0;i<n;i++)
        {
            if(x[i]&1) odd.push_back(i);
            else even.push_back(i);
        }
        st.clear();
        for(int i=0;i<(int)odd.size();i++)
        {
            int id=odd[i];
            if(dir[id]==0)
            {
                if(st.size())
                {
                    int nid=st.back(); st.pop_back();
                    if(dir[nid]==0) ans[save[id]]=ans[save[nid]]=(x[nid]+(x[id]-x[nid])/2);
                    else ans[save[id]]=ans[save[nid]]=(x[id]-x[nid])/2;
                }
                else st.push_back(id);
            }
            else st.push_back(id);
        }
        while(st.size()>=2&&dir[st[st.size()-1]]==1&&dir[st[st.size()-2]]==1)
        {
            int id=st.back(); st.pop_back();
            int nid=st.back(); st.pop_back();
            ans[save[id]]=ans[save[nid]]=(m-x[id])+(x[id]-x[nid])/2;
        }
        if(st.size()==2)
        {
            int id=st.back(); st.pop_back();
            int nid=st.back(); st.pop_back();
            ans[save[id]]=ans[save[nid]]=m-(x[id]-x[nid])/2;
        }
        else if(st.size()==1) 
        {
            int id=st.back(); st.pop_back();
            ans[save[id]]=-1;
        }
        assert(st.empty());
        for(int i=0;i<(int)even.size();i++)
        {
            int id=even[i];
            if(dir[id]==0)
            {
                if(st.size())
                {
                    int nid=st.back(); st.pop_back();
                    if(dir[nid]==0) ans[save[id]]=ans[save[nid]]=(x[nid]+(x[id]-x[nid])/2);
                    else ans[save[id]]=ans[save[nid]]=(x[id]-x[nid])/2;
                }
                else st.push_back(id);
            }
            else st.push_back(id);
        }
        while(st.size()>=2&&dir[st[st.size()-1]]==1&&dir[st[st.size()-2]]==1)
        {
            int id=st.back(); st.pop_back();
            int nid=st.back(); st.pop_back();
            ans[save[id]]=ans[save[nid]]=(m-x[id])+(x[id]-x[nid])/2;
        }
        if(st.size()==2)
        {
            int id=st.back(); st.pop_back();
            int nid=st.back(); st.pop_back();
            ans[save[id]]=ans[save[nid]]=m-(x[id]-x[nid])/2;
        }
        else if(st.size()==1) 
        {
            int id=st.back(); st.pop_back();
            ans[save[id]]=-1;
        }
        for(int i=0;i<n;i++) printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
    return 0;
}