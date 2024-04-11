#include <stdio.h>
#include <vector>

using namespace std;
#define MAX_N 100000

int N;
char C1[MAX_N+3];
char C2[MAX_N+3];
bool b[30][30];
vector<int> gp[30];
bool visited[30];
struct S{
    int c1, c2;
};
vector<S> v;

void DFS(int x)
{
    visited[x]=true;
    for(int i=0; i<gp[x].size(); i++)
    {
        if(!visited[gp[x][i]])
        {
            v.push_back({gp[x][i], x});
            DFS(gp[x][i]);
        }
    }
}


int main()
{
    scanf("%d", &N);
    scanf("%s", C1);
    scanf("%s", C2);
    for(int i=0; i<N; i++)
    {
        if(C1[i]!=C2[i])
        {
            if(!b[C1[i]-'a'][C2[i]-'a'])
            {
                b[C1[i]-'a'][C2[i]-'a']=true;
                b[C2[i]-'a'][C1[i]-'a']=true;
                gp[C1[i]-'a'].push_back(C2[i]-'a');
                gp[C2[i]-'a'].push_back(C1[i]-'a');
            }
        }
    }
    for(int i=0; i<'z'-'a'; i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    printf("%d\n", (int)v.size());
    for(int i=0; i<v.size(); i++)
    {
        printf("%c %c\n", v[i].c1+'a', v[i].c2+'a');
    }
    return 0;
}