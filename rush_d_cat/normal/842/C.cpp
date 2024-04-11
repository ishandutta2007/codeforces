#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int NICO = 2000000 + 10;

int n;
int a[NICO], val[NICO], gg[NICO], ans[NICO];
vector<int> G[NICO];
set<int> st;

int gcd(int x, int y)
{
    return  y==0? x: gcd(y, x%y);
}

void dfs(int x, int p)
{
    for(int i = 0; i < G[x].size(); i ++)
    {
        int u = G[x][i];
        if(u == p) continue; 

        val[u] = gcd(val[x], a[u]);

        vector<int> era;

        for(set<int>::iterator it = st.begin(); it != st.end(); it ++)
        {
            if(a[u] % *it != 0)
            {
                //printf("%d %d %d\n", u, *it, gg[*it]+1);
                gg[*it] ++;
                era.push_back(*it);
            }
        }
        
        int mx = 0;
        for(set<int>::iterator it = st.begin(); it != st.end(); it ++)
        {
            //printf("*it = %d gg[*it] = %d\n", *it, gg[*it]);
            if(gg[*it] <= 1) mx = *it;
        }

        //printf("mx = %d\n", mx);
        ans[u] = max(val[u], mx);
        dfs(u, x);

        for(int j = 0; j < era.size(); j ++)
        {
            gg[era[j]] --;
        }
    }
}

int main()
{

    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) 
    {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i < n; i ++)
    {
        int x, y; scanf("%d %d", &x, &y);
        G[x].push_back(y); G[y].push_back(x);
    }

    for(int i = 1; i <= a[1]; i ++)
    {
        if((a[1]%i) == 0) st.insert(i);
    }
    
    val[1] = 0;
    dfs(1, -1);
    ans[1] = a[1];
    
    for(int i = 1; i <= n; i ++)
    {
        printf("%d\n", ans[i]);
    }

}

/*
4
1 6 12 3
1 2
2 3
3 4

4
0 0 0 10
1 2
2 3
3 4

7
12 6 3 3 2 1 24
1 2
1 3
2 4
2 5
3 6
3 7

7
1 6 3 3 2 1 24
1 2
1 3
2 4
2 5
3 6
3 7

3
1 1 1
1 2
1 3

4
100 2 8 12
1 2
1 3
1 4

6
63 63 9 7 9 7
1 2
2 3
3 4
4 5
5 6



63 7 9[9, 1] 7

*/