#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,a[MAXN][5];
queue<int> que;
vector<int> ans;
bool check(int x,int y,int z)
{
    int res=(a[y][0]-a[x][0])*(a[z][0]-a[x][0])+(a[y][1]-a[x][1])*(a[z][1]-a[x][1])+(a[y][2]-a[x][2])*(a[z][2]-a[x][2])+(a[y][3]-a[x][3])*(a[z][3]-a[x][3])+(a[y][4]-a[x][4])*(a[z][4]-a[x][4]);
    return res>0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++) que.push(i);
    ans.clear();
    while(que.size()>2)
    {
        int x=que.front();
        que.pop();
        int y=que.front();
        que.pop();
        int z=que.front();
        que.pop();
        if(!check(x,y,z)) que.push(x);
        if(!check(y,z,x)) que.push(y);
        if(!check(z,x,y)) que.push(z);
    }
    while(que.size())
    {
        int x=que.front();
        que.pop();
        bool f=true;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if(i!=x&&j!=x&&check(x,i,j)) {f=false; break;}
            if(!f) break;
        }
        if(f) ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]+1);
    return 0;
}