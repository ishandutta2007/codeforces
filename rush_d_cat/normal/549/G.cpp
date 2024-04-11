#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int NICO = 200000+10;

struct Item
{
    int val, pos;
} it[NICO];

bool cmp(Item A, Item B)
{
    /*
    if (A.val - 2*A.pos == B.val - 2*B.pos)
        return A.pos > B.pos;
    */
    
    return (A.val - B.val) > (B.pos - A.pos); 
}

int n;
vector<int> res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &it[i].val);
        it[i].pos = i;
    }

    sort(it + 1, it + 1 + n, cmp);

    
    int ok = 1;
    for (int i = 1; i <= n; i ++)
    {
        res.push_back( it[i].val - (n - i + 1 - it[i].pos) );
    }

    for (int i = 1; i < res.size(); i ++)
    {
        if (res[i] > res[i-1]) ok = 0;
    }

    if (!ok)
    {
        printf(":(\n");
        return 0;
    }

    for (int i = res.size() - 1; i>= 0; i --)
    {
        printf("%d ", res[i]);
    }
}