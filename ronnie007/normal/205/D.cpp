#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
set<int> s;
set<int>::iterator it;
int n,a[100005],b[100005],i,l=0,r=0,ans=-1,j;
struct card
    {
    int x,y,id;
    bool operator <(const card q) const {
    return x==q.x?y<q.y:x<q.x;
    }
    card(int x=-1,int y=-1,int id=-1)
    :x(x),y(y),id(id) {}
    };
vector<card> v;
int main()
    {
    cin>>n;
    for(i=1;i<=n;i++)
        {
        cin>>a[i]>>b[i];
        s.insert(a[i]);
        s.insert(b[i]);
        v.push_back(card(a[i],0,i));
        if(a[i]!=b[i]) v.push_back(card(b[i],1,i));
        }
    v.push_back(card());
    sort(v.begin(),v.end());
    for(it=s.begin();it!=s.end();it++)
        {
        while(l<v.size() && v[l].x<*it) l++;
        if(l>0) l--;
        while(r<v.size() && v[r].x<=*it) r++;
        r--;
        if(r-l>=n/2+n%2)
        {
            j=l+1;
            while(v[j].x==v[r].x && v[j].y==0) j++;
            if(ans==-1) ans=1000000000;
            ans=min(ans,max(0,(n/2+n%2)-(j-l-1)));
            }
        }
    cout<<ans;
    return 0;
    }