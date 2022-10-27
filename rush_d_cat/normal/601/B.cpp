#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int NICO = 100002;
int a[NICO];
int d[NICO];
int pre[NICO], nxt[NICO];
int n, q;
int l, r;
stack<int> st;
vector<int> vec;
int main()
{
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        d[i+1] = abs(a[i+1] - a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d", &l, &r);
        if(r-l<=0)
        {
            printf("0\n");
            continue;
        }
        vec.clear();
        for(int j=l+1;j<=r;j++) vec.push_back(abs(a[j]-a[j-1]));
        int sz = vec.size();
        while(!st.empty()) st.pop();
        pre[0] = -1;st.push(0);
        for(int j=1;j<sz;j++)
        {
            while(!st.empty() && vec[j]>=vec[st.top()])
            {
                //cout << st.top() << endl;
                st.pop();
            }
            if(st.empty()) pre[j] = -1;
            else pre[j] = st.top();

            st.push(j);
            //cout << j << " " << pre[j] << endl;
        }
        while(!st.empty()) st.pop();
        nxt[sz-1] = sz;st.push(sz-1);
        for(int j=sz-2;j>=0;j--)
        {
            while (!st.empty() && vec[j]>vec[st.top()])
            {
                st.pop();
            }
            if(st.empty()) nxt[j] = sz;
            else nxt[j] = st.top();
            //cout << j << " " << nxt[j] << endl;
            st.push(j);
        }
        long long res = 0;
        for(int j=0;j<sz;j++)
        {
            res += (long long)(nxt[j]-j)*(j-pre[j])*vec[j];
        }
        cout << res << endl;
    }
}