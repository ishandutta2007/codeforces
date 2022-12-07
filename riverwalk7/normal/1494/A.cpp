#include <iostream>
#include <fstream>
using namespace std;
int T;
string s;
bool check(string x, int i, int j, int k)
{
    char p, q, r;
    p = (i ? '\(': '\)');
    q = (j ? '\(': '\)');
    r = (k ? '\(': '\)');
    int N = x.size();
    for(int i=0; i<N; i++)
    {
        if(x[i] == 'A')
        {
            x[i] = p;
        }
        if(x[i] == 'B')
        {
            x[i] = q;
        }
        if(x[i] == 'C')
        {
            x[i] = r;
        }
    }
    int depth = 0;
    for(int i=0; i<N; i++)
    {
        if(x[i] == '(')
        {
            depth += 1;
        }
        else
        {
            depth -= 1;
        }
        if(depth < 0)
        {
            return false;
        }
    }
    return (depth == 0);
}
bool solve(string x)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                if(check(x, i, j, k))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>s;
        cout<<(solve(s) ? "YES": "NO")<<endl;
    }
}