#include <iostream>
#include <fstream>
#define MAXN 8
using namespace std;
int N, M;
bool conn[MAXN][MAXN];
int a, b;
int v[MAXN];
int cur;
bool used[MAXN][MAXN];
int best, cur2, cur3, cur4, ans;
int main()
{
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        cin>>a>>b;
        conn[a][b] = conn[b][a] = true;
    }
    for(int i=0; i<279936; i++)
    {
        cur = i;
        for(int j=0; j<6; j++)
        {
            for(int k=0; k<6; k++)
            {
                used[j][k] = false;
            }
        }
        for(int j=0; j<7; j++)
        {
            v[j] = cur % 6;
            cur /= 6;
        }
        cur2 = 0;
        for(int j=1; j<=N; j++)
        {
            for(int k=j+1; k<=N; k++)
            {
                if(conn[j][k])
                {
                    cur3 = v[j]; cur4 = v[k];
                    if(cur3 > cur4)
                    {
                        swap(cur3, cur4);
                    }
                    if(!used[cur3][cur4])
                    {
                        ++cur2;
                        used[cur3][cur4] = true;
                    }
                }
            }
        }
        ans = max(ans, cur2);
    }
    cout<<ans<<endl;
}