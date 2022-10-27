#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
#define N (300000+10)

int n, a[N]; 
multiset<int> st;

int main()
{
    scanf("%d", &n);
    
    LL ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        st.insert(a[i]); st.insert(a[i]);
        ans += a[i];
        
        int x = *st.begin();
        st.erase( st.lower_bound(x) );
        
        ans -= x;
    }

    cout << ans << endl;
}