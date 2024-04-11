#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
int n, m;
char s[52][52];
set<int> st;

int chk(int x, int y)
{
    set<int> tmp;
    tmp.insert(s[x][y]); tmp.insert(s[x][y+1]); tmp.insert(s[x+1][y]); tmp.insert(s[x+1][y+1]);
    if (tmp == st) return 1;
    return 0;
}

int main()
{
    cin >> n >> m; st.insert('f'); st.insert('a'); st.insert('c'); st.insert('e');
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s", s[i] + 1);
    }
    int ans = 0;
    for (int i = 1; i < n; i ++)
    {
        for (int j = 1; j < m; j ++)
        {
            ans += chk(i, j);
        }
    }
    cout << ans << endl;
}