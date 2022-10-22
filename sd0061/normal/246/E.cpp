#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;
#define N 100005
int n , m , pre[N] , mcnt , a[N] , cnt;
struct edge
{
    int x , next;
}e[N];
map<string , int> hash;
vector< pair<int , int> > Q[N];
int ans[N];

struct Treap
{
    int nodecnt , priority[N] , child[N][2];
    pair<int , int> key[N] ;
    int Size[N] , cnt[N];
    int del[N] , rs;
    void clear()
    {
        nodecnt = 1;
        priority[0] = -1 << 30;
        child[0][0] = child[0][1] = 0;
        cnt[0] = 0 , Size[0] = 0;
        rs = 0;
    }
    int size(int x)
    {
        return Size[x];
    }
    void update(int x)
    {
        Size[x] = Size[child[x][0]] + Size[child[x][1]] + cnt[x];
    }
    int newnode(pair<int , int> val)
    {
        int x;
        if (rs)
            x = del[rs --];
        else
            x = nodecnt ++;
        key[x] = val , cnt[x] = 1 , child[x][0] = child[x][1] = 0;
        priority[x] = rand() << 15 | rand();
        return x;
    }
    void rotate (int& x , int t)
    {
        int y = child[x][t];
        child[x][t] = child[y][t ^ 1];
        child[y][t ^ 1] = x;
        update(x) , update(y);
        x = y;
    }
    void insert(int& x , pair<int , int> k)
    {
        if (x)
        {
            if (key[x] != k)
            {
                int t = key[x] < k;
                insert(child[x][t] , k);
                if (priority[child[x][t]] > priority[x])
                    rotate(x , t);
            }
        }
        else
            x = newnode(k);
        update(x);
    }
    void erase(int& x , pair<int , int> k)
    {
        if (key[x] == k)
        {
            {
                if (!child[x][0] && !child[x][1])
                {
                    del[++ rs] = x;
                    -- cnt[x] , x = 0;
                    return;
                }
                int t = priority[child[x][0]] < priority[child[x][1]];
                rotate(x , t) , erase(x , k);
            }
        }
        else
            erase(child[x][key[x] < k] , k);
        update(x);
    }
    int Rank(int& x , pair<int , int> k)
    {
        if(!x) return 0;
        if (k < key[x])
            return Rank(child[x][0] , k);
        int Rk = Size[child[x][0]] + cnt[x];
        if (k > key[x])
            Rk += Rank(child[x][1] , k);
        return Rk;
    }
    int lower_bound(int x , pair<int , int> val , int opt)
    {
        if(!x) return opt;
        if (key[x] >= val)
            return lower_bound(child[x][0] , val , x);
        else
            return lower_bound(child[x][1], val , opt);
    }
    void merge(int& X , int& x)
    {
        if (child[x][0]) merge(X , child[x][0]);
        if (child[x][1]) merge(X , child[x][1]);
        insert(X , key[x]);
        erase(x , key[x]);
        //x = 0;
    }
    void print(int x)
    {
        if (child[x][0]) print(child[x][0]);
        printf("%d %d\n" , key[x].first , key[x].second);
        if (child[x][1]) print(child[x][1]);
    }
}T;

int dfs(int x , int dep)
{
    int P = 0;
    if (x) T.insert(P , make_pair(dep , a[x]));
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        int R = dfs(y , dep + 1);
        if (T.size(P) < T.size(R))
            swap(P , R);
        if(x) T.merge(P , R);
    }
    for (int i = 0 ; i < (int) Q[x].size() ; ++ i)
    {
        int K = Q[x][i].first , j = Q[x][i].second;
        ans[j] = T.Rank(P , make_pair(dep + K , 1 << 30)) - T.Rank(P , make_pair(dep + K , -1 << 30));
    }
    //if(x)printf("************\n");
    //if(x)printf("%d: \n" , x);
    //    if(x)T.print(P);
    return P;
}

void work()
{
    int i , x , y , j;
    char str[30];
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%s%d",str,&x);
        if (!hash[str])
            a[i] = hash[str] = ++ cnt;
        else
            a[i] = hash[str];
        e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
    }
    scanf("%d",&m) , T.clear();
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d",&x,&y) , Q[x].push_back(make_pair(y , i));
    dfs(0 , 0);
    for (i = 0 ; i < m ; ++ i)
        printf("%d\n" , ans[i]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}