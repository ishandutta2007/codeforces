#include <iostream>
#include <queue>
using namespace std;
const int N = 1010;
int a[N];

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        priority_queue<int, vector<int>, greater<int> > heap;
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        if(n == 1)
        {
            puts("-1");
            continue;
        }
        for(int i = 1;i<=n;i++) heap.push(i);
        for(int i=1;i<=n-2;i++)
        {
            int t1 = heap.top(); heap.pop();
            int t2 = heap.top(); heap.pop();
            if(t1 != a[i])
            {
                printf("%d ", t1);
                heap.push(t2);
            }
            else
            {
                printf("%d ", t2);
                heap.push(t1);
            }
        }
        int t1 = heap.top(); heap.pop();
        int t2 = heap.top(); heap.pop();
        if(t1 == a[n-1] || t2 == a[n]) printf("%d %d", t2, t1);
        else printf("%d %d", t1, t2);
        puts("");
    }
    return 0;
}