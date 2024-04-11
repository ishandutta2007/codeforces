#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

set<pii> st;
set<int> node;

int n, m, k;
int x, y;
int finish = 0;

set<int>::iterator it;

void dfs(int x, int p)
{
    //printf("%d\n", x);
    if (node.size()) node.erase(x);

    vector<int> tmp;
    tmp.clear();
    
    for (it = node.begin(); it != node.end(); it ++)
    {
        tmp.push_back(*it);
    }

    for (int i = 0; i < tmp.size(); i ++)
    {
        int nxt = tmp[i];
        if (nxt == p || st.count( make_pair(nxt, x) ))
        {
            continue;
        } 
        node.erase(nxt);
    }

    for (int i = 0; i < tmp.size(); i ++)
    {
        int nxt = tmp[i];
        if (nxt == p || st.count( make_pair(nxt, x) ))
        {
            continue;
        } 
        dfs(nxt, x);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i ++)
    {
        scanf("%d %d", &x, &y);
        st.insert(make_pair(x, y));
        st.insert(make_pair(y, x));
    }

    int cmp = 0, can = 0;
    int isconnect = 0;

    for (int i = 1; i <= n; i ++)
    {
        node.insert(i);
    }

    dfs(1, -1);

    if (node.size() != 0)
    {
        printf("impossible\n");
        return 0;
    }

    node.clear();
    for (int i = 2; i <= n; i ++)
    {
        node.insert(i);
    }

    for (int i = 2; i <= n; i ++)
    {
        if (node.count(i)) 
        {
            cmp ++;
        }
        dfs(i, -1);
    }

    for (int i = 2; i <= n; i ++)
    {
        if (! st.count( make_pair(1, i) ))
        {
            can ++;
        }
    }


    if (cmp <= k && k <= can)
    {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }

}