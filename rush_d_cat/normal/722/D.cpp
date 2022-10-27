                            
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int n, y[50000 + 20];
set <int> st;
int main()
{
    scanf("%d" ,&n);
    int i;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &y[i]);
        st.insert(y[i]);
    }
    while(1)
    {
        auto it = st.end();
        it--;
        int u = *it;
        int t;
        for(t = u; t >= 1; t/=2)
        {
            if(!st.count(t)) break;
        }
        if(t == 0)
        {
            for(auto it : st) printf("%d ", it);
            return 0;
        }
        st.erase(u);
        st.insert(t);
    }
}