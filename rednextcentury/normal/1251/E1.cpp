#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> add[1000000];
int n;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        scanf("%d",&n);
        for (int i=0;i<=n;i++)add[i].clear();
        multiset<int> s;
        ll ret=0;
        for (int i=0;i<n;i++) {
            int p,m;
            scanf("%d%d",&m,&p);
            add[m].push_back(p);
            ret+=p;
        }
        for (int i=0;i<n;i++) {
            for (auto x:add[i])s.insert(x);
            if (s.size()){
                ret-=*(--s.end());
                s.erase(--s.end());
            }
        }
        printf("%lld\n",ret);

    }
}