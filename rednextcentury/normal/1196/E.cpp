#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ans;
bool solve(int x,int y,int a,int b)
{
    ans.clear();
    int cur=1;
    while(a||b)
    {
        if (cur)
        {
            if (!a)break;
            ans.push_back({x,y});
            a--;
        }
        else
        {
            if (b==0)break;
            ans.push_back({x,y});
            b--;
            if (a>b)
            {
                a--;
                ans.push_back({x-1,y});
            }
            if (a>b)
            {
                a--;
                ans.push_back({x+1,y});
            }

        }
        cur=1-cur;
        y++;
    }
    if (a||b)return 0;
    else return 1;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int w,b;
        scanf("%d%d",&b,&w);
        if (w>=b)
        {
            if (solve(2,2,w,b))
            {
                printf("YES\n");
                for (auto p:ans)
                    printf("%d %d\n",p.first,p.second);
            }
            else
                printf("NO\n");
        }
        else
        {
            if (solve(2,1,b,w))
            {
                printf("YES\n");
                for (auto p:ans)
                    printf("%d %d\n",p.first,p.second);
            }
            else
                printf("NO\n");
        }
    }
}