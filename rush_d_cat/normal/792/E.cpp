#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
vector<LL> v;
LL n, a[502];
set<LL> st;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int x=1;;x++)
    {
        if(a[1]%x == 0&&a[1]!=x)st.insert(a[1]/x-1);
        if(a[1]/x > 0)st.insert(a[1]/x);
        if(x*(x+1) > a[1]) 
        {
            for(int i=1;i<=x;i++)
            {
                st.insert(i);
            }
            break;
        }
    }
    set<LL>::iterator it;   
    for(int i=2;i<=n;i++)
    {
        for(it=st.begin();it!=st.end();it++)
        {
            if((*it+1)*(a[i]/(*it)) < a[i])
            {
                v.push_back(*it);
            }
        }
        for(int j=0;j<v.size();j++)
        {
            st.erase(v[j]);
        }
        v.clear();
    }
    int t = *st.rbegin();
    //cout << t << endl;
    LL ans = 0;
    for(int i=1;i<=n;i++)
    {
        //printf("%.7f %.7f\n", (double)a[i]/t, (double)a[i]/(t+1));
        LL r = a[i]%(t+1);
        ans += a[i]/(t+1) + (r?1:0);
    }
    cout << ans << endl;
}