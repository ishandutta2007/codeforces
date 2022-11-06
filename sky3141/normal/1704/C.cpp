#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100010;
int v1[N], v2[N];

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i=0;i<m;i++) scanf("%d", &v1[i]);
        sort(v1, v1 + m);
        for(int i=1;i<m;i++) v2[i] = v1[i] - v1[i-1] - 1;
        v2[0] = v1[0] + n - v1[m-1] - 1;
        sort(v2, v2+m, cmp);
        //for(int i=0;i<m;i++) cout << v2[i] <<endl;
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            if(v2[i] - 4*i <= 0) break;
            if(v2[i] - 4*i == 1) cnt += 1;
            else cnt += v2[i] - 4*i-1;
        }
        printf("%d\n", n - cnt);
    }
    return 0;
}