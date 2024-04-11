#include <bits/stdc++.h>
using namespace std;
int d[100009];
int e[100009];

int main()
{
    int n;
   cin>>n;

    stack<int> s;
    int k = 0;
    int f = 1;

    for(int i=1; i<=n; i++)
    {
       cin>>e[i];
        d[e[i]] = 1;
        while(s.size()>0 && s.top() < e[i])
        {
            d[e[i]] = max(d[e[i]],d[s.top()] + 1);
            s.pop();
        }
        if(s.size()==0) d[e[i]] = 0;
        s.push(e[i]);
    }
for(int i=1; i<=n; i++)
        k = max(k,d[i]);
cout<<k<<endl;
}