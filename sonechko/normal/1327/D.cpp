#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],b[N],p[N],c[N];
int use[N];
vector<int> vs;

int get()
{
    int p=vs.size();
    vector<int> ps;
    for (int j=1; j*j<=p; j++)
    {
        if (p%j==0) {ps.pb(j); ps.pb(p/j);}
    }
    int ans=p;
    for (int jj=0; jj<ps.size(); jj++)
    {
        int j=ps[jj];
        if (j>=ans) continue;
        for (int t=0; t<j; t++)
        {
            int c=1;
            for (int d=t; d<vs.size(); d+=j)
                if (vs[d]!=vs[t]) {c=0; break;}
            if (c==1) {ans=j; break;}
        }
    }
    return ans;
}

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>p[i];
    for (int i=1; i<=n; i++)
        cin>>c[i];
    for (int i=1; i<=n; i++)
        use[i]=0;
    int ans=n;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
        {
            vs.clear();
            int t=i;
            while (use[t]==0)
            {
                use[t]=1;
                vs.pb(c[t]);
                t=p[t];
            }
            ans=min(ans,get());
        }
    cout<<ans<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}
/**

7 4 5 6 1 8 3 2
1: 7 4 5 6 1 8 3 2  : 1->7->3->5   2->4->6->8
2: 3 6 1 8 7 2 5 4  : 1->3   2->6   4->8   5->7
3: 5 8 7 2 3 4 1 6  : 1->5->3->7   2->8->6->4
4: 1 2 3 4 5 6 7 8  : 1   2   3   4   5   6   7   8
5: 7 4 5 6 1 8 3 2  : 1->7->3->5   2->4->6->8
6: 3 6 1 8 7 2 5 4  : 1->3   2->6   4->8   5->7
7: 5 8 7 2 3 4 1 6  : 1->5->3->7   2->8->6->4
8: 1 2 3 4 5 6 7 8  : 1   2   3   4   5   6   7   8
9: 7 4 5 6 1 8 3 2  : 1->7->3->5   2->4->6->8
10: 3 6 1 8 7 2 5 4  : 1->3   2->6   4->8   5->7

7->3->5->1

1 4 6

**/