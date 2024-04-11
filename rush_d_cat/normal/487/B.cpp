#include <iostream>
#include <set>
using namespace std;
const int NICO = 100000 + 10;
int n, l, s, a[NICO], dp[NICO];
multiset<int> st, ret;
int main()
{
    cin >> n >> s >> l;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1,j=1;i<=n;i++)
    {
        st.insert(a[i]);
        for(;*st.rbegin()-*st.begin() > s;j++)
        {
            st.erase(st.find(a[j]));
            if(i - j >= l)
            {
                ret.erase(ret.find(dp[j-1]));
            }
        } 
        if(i-j+1>=l) ret.insert(dp[i-l]);
        if(ret.size() == 0) dp[i] = NICO;
        else dp[i] = *ret.begin() + 1;
    }
    printf("%d\n", (dp[n]>=NICO)?-1:dp[n]);
}