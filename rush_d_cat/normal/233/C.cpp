#include <iostream>
using namespace std;
const int NICO = 100;
int mp[NICO][NICO];
int main()
{
    int m; cin >> m;
    for(int i=0;i<NICO;i++)
    {
        int s = 0;
        for(int j=0;j<i&&s<=m;j++)
        {
            m -= s, s ++; 
            mp[i][j] = mp[j][i] = 1;
        }
    }
    printf("%d\n", NICO);
    for(int i=0;i<NICO;i++)
    {
        for(int j=0;j<NICO;j++)
        {
            printf("%d", mp[i][j]);
        }
        printf("\n");
    }
}