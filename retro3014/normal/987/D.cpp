#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
#define MAX_N 100000
#define MAX_K 100

int N, M, K, S;
vector<int> gp[MAX_N+1];
int arr[MAX_N+1];
int t;
bool visited[MAX_N+1];
vector<int> type[MAX_K+1];
vector<int> ans[MAX_N+1];
deque<int> dq;

int main()
{
    cin>>N>>M>>K>>S;
    for(int i=1; i<=N; i++)
    {
        cin>>arr[i];
        type[arr[i]].push_back(i);
    }
    for(int i=1; i<=M; i++)
    {
        int x, y;
        cin>>x>>y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    for(int i=1; i<=K; i++)
    {
        for(int j=1; j<=N; j++)
        {
            visited[j]=false;
        }
        for(int j=0; j<type[i].size(); j++)
        {
            dq.push_back(type[i][j]);
            visited[type[i][j]]=true;
        }
        int cnt=0;
        int sz=(int)dq.size();
        while(!dq.empty())
        {
            if(sz==0){
                sz=(int)dq.size();
                cnt++;
            }
            int now=dq.front();
            dq.pop_front();
            sz--;
            ans[now].push_back(cnt);
            for(int j=0; j<gp[now].size(); j++)
            {
                if(!visited[gp[now][j]])
                {
                    visited[gp[now][j]]=true;
                    dq.push_back(gp[now][j]);
                }
            }
        }
    }
    for(int i=1; i<=N; i++)
    {
        int answer=0;
        sort(ans[i].begin(), ans[i].end());
        for(int j=0; j<S; j++)
        {
            answer+=ans[i][j];
        }
        cout<<answer<<" ";
    }
    return 0;
}