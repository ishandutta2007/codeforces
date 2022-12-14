#include<bits/stdc++.h>
using namespace std;
int BIT[1000000], mx=10040;
vector<int> clr;
void init()
{
    for(auto x:clr)BIT[x]=0;
    clr.clear();
}
void update(int x, int delta)
{
      for(; x <= mx; x += x&-x)
        BIT[x] += delta , clr.push_back(x);
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
vector<pair<int,pair<int,int> > > V,H;
vector<pair<int,int> >Q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=5001,y1+=5001,x2+=5001,y2+=5001;
        if (x1==x2)V.push_back({x1,{min(y1,y2),max(y1,y2)}});
        else H.push_back({y1,{min(x1,x2),max(x1,x2)}});
    }
    long long ret=0;
    for (int i=0;i<V.size();i++)
    {
        auto v = V[i];
        init();
        int x = v.first;
        int l = v.second.first-1;
        int r = v.second.second;
        Q.clear();
        for (int j=0;j<V.size();j++)if(V[j].first>x)
            Q.push_back({V[j].first,-j});
        for (int j=0;j<H.size();j++)
        {
            if (H[j].second.first<=x){
                update(H[j].first,1);
                Q.push_back({H[j].second.second,j+1});
            }
        }
        sort(Q.begin(),Q.end());
        for (auto q:Q)
        {
            int id = q.second;
            if (id>0)
            {
                id--;
                update(H[id].first,-1);
            }
            else
            {
                id=-id;
                int L = max(l,V[id].second.first-1);
                int R = min(r,V[id].second.second);

                long long num;
                if (R>=L)
                    num = query(R)-query(L);
                else num=0;
                ret+=((num-1)*num)/2;
            }
        }
    }
    cout<<ret<<endl;
}