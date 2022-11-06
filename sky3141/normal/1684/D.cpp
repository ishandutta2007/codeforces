#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200010;
bool n_c[N];
struct Node
{
    int idx, dam, val;
    bool operator<(const Node &W)
    {
        return val > W.val;
    }
} node[N], back_up[N];


int main(void)
{
    int T ;
    scanf("%d", &T);
    while(T --)
    {
        memset(n_c, 0, sizeof n_c);
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &node[i].dam);
            node[i].val = node[i].dam - (n-1-i);
            node[i].idx = i;
        }
        memcpy(back_up, node, sizeof back_up);
        
        sort(node, node+n);
        //for(int i=0;i<n;i++) cout << node[i].val << ' ' <<endl;
        for(int i=0;i<n && k;i++)
        {
            //if(node[i].val <= 0) break;
            n_c[node[i].idx] = true; 
            k --;
        }
        // int r = n-1;
        // while(k && r >=0)
        // {
        //     if(n_c[r] == 0)
        //     {
        //         n_c[r] = true;
        //         k --;
        //     } 
        //     r --;
        // }
        
        LL res = 0;
        int bon = 0;
        for(int i=0;i<n;i++)
        {
            if(n_c[i]) bon ++;
            else res += back_up[i].dam + bon;
        }
        
        printf("%lld\n", res);
    }
    return 0;
}