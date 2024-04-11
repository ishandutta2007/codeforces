#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
char s[100000+10];
int pre[100000+10], nxt[100000+10];
stack<int> st;


int main() 
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '[') pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1];
        
        if (s[i] == '(' || s[i] == '[') 
            st.push(i);
        else {
            if ( st.size() ) {
                int pos = st.top(); st.pop();
                if (s[pos] == '(' && s[i] == ')') {
                    nxt[pos] = i;
                } else
                if (s[pos] == '[' && s[i] == ']') {
                    nxt[pos] = i;
                } else {
                    while (st.size()) st.pop();
                }
            }
        }
    }

    int ans = 0, l, r;
    for (int i = 1; i <= n; i ++) 
    {
        int cur = i, L = i, R, sum = 0;
        
        while (cur <= n && nxt[cur] > 0) 
        {
            R = nxt[cur];
            cur = nxt[cur] + 1;
        }
        if (R > L) sum = pre[R] - pre[L - 1];
        if (sum > ans) ans = sum, l = L, r = R; 
    }

    printf("%d\n", ans);
    for (int i = l; i <= r; i ++) {
        printf("%c", s[i]);
    }

}