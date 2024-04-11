#include <iostream>
#include <algorithm>
using namespace std;
const int NICO = 200002;
const int INF = 1e9 + 7;
int n, s;
int a[NICO];
int num[NICO];
int res = INF;
int main()
{
    scanf("%d %d", &n, &s);
    int add = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i]==0 && i!=s) a[i] = NICO-1;
        if(a[i]!=0 && i==s) a[i] = 0, add = 1;
        num[a[i]] ++;
    }
    int sum = 1; 
    int sup = 0;
    int empty = 0;    
    for(int i=1;i<=n;i++) // enum_ rank
    {
        if(!num[i]) empty++;
        sum += num[i];
        sup += max(num[i]-1, 0);
        if(n-sum>=empty)
        {
            res = min(res, n-sum);
        } else {
            int need = empty-(n-sum);
            if(need > sup) continue;
            res = min(res, n-sum+need);
        }
    }
    if(res==INF)
    {
        res = num[NICO-1];
    }
    cout << res+add << endl;
}