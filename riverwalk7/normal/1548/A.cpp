#include <iostream>
#include <fstream>
#define MAXN 200200
using namespace std;
int N, M, Q, u, v;
int higher_friends[MAXN];
int cur_ans;
int query_type;
void add_friend(int u, int v)
{
    if(u > v)
    {
        swap(u, v);
    }
    ++higher_friends[u];
    if(higher_friends[u] == 1) --cur_ans;
}
void remove_friend(int u, int v)
{
    if(u > v)
    {
        swap(u, v);
    }
    --higher_friends[u];
    if(higher_friends[u] == 0) ++cur_ans;
}
int main()
{
    cin>>N>>M;
    cur_ans = N;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v;
        add_friend(u, v);
    }
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>query_type;
        if(query_type == 1)
        {
            cin>>u>>v;
            add_friend(u, v);
        }
        if(query_type == 2)
        {
            cin>>u>>v;
            remove_friend(u, v);
        }
        if(query_type == 3)
        {
            cout<<cur_ans<<endl;
        }
    }
}