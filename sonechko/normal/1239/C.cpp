#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

ll t[N],ans[N];
int v[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    v[i]=v[i+i]+v[i+i+1];
}

int sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return sum(i+i,l,mid,tl,tr)+sum(i+i+1,mid+1,r,tl,tr);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll p;
    cin>>n>>p;
    set<int> wait;
    set<pair<ll,int> > all;
    deque<int> q;
    for (int i=1; i<=n; i++)
    {
        cin>>t[i];
        all.insert(mp(t[i],i));
        update(1,1,n,i,1);
    }
    ll timee=-1,next_take=-1;
    while (all.size()>0||wait.size()>0||q.size()>0)
    {
        /**
        cout<<timee<<endl;
        cout<<"in queue: ";
        for (int j=0; j<q.size(); j++)
            cout<<q[j]<<" ";
        cout<<endl;
        cout<<"waiting: ";
        for (auto it=wait.begin(); it!=wait.end(); it++)
            cout<<(*it)<<" ";
        cout<<endl;
        cout<<"don't want to go: ";
        for (auto it=all.begin(); it!=all.end(); it++)
            cout<<(*it).ss<<" ";
        cout<<endl;
        cout<<"next take is: "<<next_take<<endl;
        **/

        if (next_take==-1)
        {
            pair<ll,int> p=*all.begin();
            timee=p.ff;
        } else
        if ((int)all.size()==0)
        {
            timee=next_take;
        } else
        {
            pair<ll,int> p=*all.begin();
            timee=min(next_take,p.ff);
        }

        ///cout<<"new time: "<<timee<<endl;

        if (next_take!=-1&&next_take<=timee)
        {
            int pos=q.front();
            ans[pos]=next_take;
            q.pop_front();
            ///cout<<pos<<" yes"<<endl;
            update(1,1,n,pos,1);
            if (q.size()>0) next_take=timee+p; else
                    next_take=-1;
        }

        while (all.size()>0)
        {
            pair<ll,int> p=*all.begin();
            if (p.ff<=timee)
            {
                all.erase(p);
                ///cout<<p.ss<<" want to go"<<endl;
                wait.insert(p.ss);
            } else break;
        }

        if (wait.size()>0)
        {
            int pos=*wait.begin();
            if (sum(1,1,n,1,pos-1)==pos-1)
            {
                ///cout<<pos<<" is going to queue"<<endl;
                wait.erase(pos);
                q.push_back(pos);
                if ((int)q.size()==1) next_take=timee+p;
                update(1,1,n,pos,0);
            }
        }
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}