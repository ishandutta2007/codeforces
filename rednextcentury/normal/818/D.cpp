#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > s;
int num[1000009];
int main()
{
    int n,A;
    scanf("%d%d",&n,&A);
    int need=0;
    for (int i=1;i<=1000000;i++)
        if (i!=A)
            s.insert(make_pair(0,i));
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==A)
        {
            need++;
            while(!s.empty() && (*s.begin()).first<need)
                s.erase(s.begin());
            if (s.empty())
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            pair<int,int> p = make_pair(num[x],x);
            if (s.find(p)!=s.end())
            {
                s.erase(s.find(p));
                p.first++;
                s.insert(p);
            }
        }
        num[x]++;
    }
    if (s.empty())
        printf("-1\n");
    else
        printf("%d\n",(*s.begin()).second);
}