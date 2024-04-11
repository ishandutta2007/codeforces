#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 2020
using namespace std;
vector<int> children[MAXN];
vector<int> numbers[MAXN];
int parent[MAXN];
int c[MAXN];
int x[MAXN];
int R, N;
bool flag;
int counter;
void shift(int node, int num)
{
    if(x[node] >= num) ++x[node];
    for(int i=0; i<children[node].size(); i++)
    {
        shift(children[node][i], num);
    }
}
void dfs(int node)
{
    if(children[node].size() > 0)
    {
        for(int i=0; i<children[node].size(); i++)
        {
            dfs(children[node][i]);
            for(int j=0; j<numbers[children[node][i]].size(); j++)
            {
                numbers[node].push_back(numbers[children[node][i]][j]);
            }
        }
        if(!numbers[node].empty()) sort(numbers[node].begin(), numbers[node].end());
        if(numbers[node].size() < c[node])
        {
            flag = true;
            return;
        }
        else if(numbers[node].size() == c[node])
        {
            x[node] = numbers[node][c[node]-1]+1;
            numbers[node].push_back(x[node]);
        }
        else
        {
            x[node] = numbers[node][c[node]];
            for(int i=c[node]; i<numbers[node].size(); i++)
            {
                numbers[node][i]++;
            }
            numbers[node].push_back(x[node]);
            for(int i=0; i<children[node].size(); i++)
            {
                shift(children[node][i], x[node]);
            }
        }
    }
    else if(c[node] == 0)
    {
        ++counter;
        x[node] = counter*MAXN;
        numbers[node].push_back(counter*MAXN);
    }
    else
    {
        flag = true;
        ++counter;
        numbers[node].push_back(counter*MAXN);
        return;
    }
}
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>parent[i]>>c[i];
        if(parent[i] == 0)
        {
            R = i;
        }
        else
        {
            children[parent[i]].push_back(i);
        }
    }
    dfs(R);
    if(!flag)
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=N; i++)
        {
            cout<<x[i]<<" ";
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
}