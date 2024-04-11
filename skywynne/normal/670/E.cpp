#include<bits/stdc++.h>
using namespace std;
int n, m, k, c, t, r;
string s, C;
stack < char > S, T, P;
int main()
{
    cin >> n >> m >> k >> s >> C;
    for (int i = 0; i < k; i++)
    {
        S.push(s[i]);
    }
    for (int i = s.size()-1; i >= k; i--)
    {
        T.push(s[i]);
    }
    for (int i = 0; i < C.size(); i++)
    {
        if (T.size() == 0 && C[i] == 'R')
        {
            continue;
        }
        if (S.size() == 1 && C[i] == 'L')
        {
            continue;
        }
        if (C[i] == 'L')
        {
            T.push(S.top());
            S.pop();
            continue;
        }
        if (C[i] == 'R')
        {
            S.push(T.top());
            T.pop();
            continue;
        }
        if (S.top() == '(')
        {
            t = 0;
            r = 1;
            while (t != r)
            {
                if (T.top() == ')')
                {
                    t ++;
                }
                else
                {
                    r ++;
                }
                T.pop();
            }
            S.pop();
            if (T.size() > 0)
            {
                S.push(T.top());
                T.pop();
            }
        }
        else
        {
            t = 1;
            r = 0;
            S.pop();
            while (t != r)
            {
                if (S.top() == '(')
                {
                    r ++;
                }
                else
                {
                    t ++;
                }
                S.pop();
            }
            if (T.size() > 0)
            {
                S.push(T.top());
                T.pop();
            }
        }
    }
    while (S.size() > 0)
    {
        T.push(S.top());
        S.pop();
    }
    while (T.size() > 0)
    {
        cout << T.top();
        T.pop();
    }
    return (0);
}