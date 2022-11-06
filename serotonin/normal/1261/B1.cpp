#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll sz=3e5+5;

typedef pair <int,int> pii;
vector < pii > d[sz];
int ans[sz], ca[sz];
pii a[sz];

#define ordered_set tree <ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set st;

bool cmp(pii x, pii y)
{
    if(x.first==y.first) return x.second<y.second;
    return x.first>y.first;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        scanf("%d", &ca[i]);
        a[i].first=ca[i];
        a[i].second=i;
    }

    sort(a, a+n, cmp);

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int k,pos;
        scanf("%d %d", &k, &pos);
        d[k-1].push_back(make_pair(pos-1,i));
    }

    for(int i=0; i<n; i++) {
        st.insert(a[i].second);
        for(int j=0; j<d[i].size(); j++) {
            int pos=d[i][j].first;
            int who=*st.find_by_order(pos);
            int qn=d[i][j].second;
            ans[qn]=ca[who];
        }
    }

    for(int i=0; i<q; i++) printf("%d\n", ans[i]);
}