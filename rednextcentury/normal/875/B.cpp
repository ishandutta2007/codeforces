#include<bits/stdc++.h>
using namespace std;
int p[3000000];
set<int> st;
int main()
{
    int n;
    scanf("%d",&n);
    int ret=1;
    printf("%d",ret);
    for (int i=1;i<=n;i++)
        st.insert(i);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        st.erase(st.find(p[i]));
        if (st.size()==0)
            printf(" 1");
        else
        {
            printf(" %d",i+1-(n-*st.rbegin()));
        }

    }
    printf("\n");
}