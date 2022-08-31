#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100100;

struct walrus
{
    int index;
    int age;
};

walrus line[MAXN];
int n;
int ans[MAXN];

inline bool operator < (walrus a, walrus b)
{
    return a.index > b.index;
}

priority_queue <walrus> heap;

inline bool cmp (walrus a, walrus b)
{
    return a.age < b.age;
}

int main()
{
    cin >> n;
    for (int a = 0; a < n; a++)
    {
        line[a].index = n - 1 - a;
        cin >> line[a].age;
    }
    sort (line, line + n, cmp);
    int lequal = -1;
    ans[line[0].index] = -1;
    for (int a = 1; a < n; a++)
    {
        if (line[a].age > line[a-1].age)
        {
            for (int b = lequal + 1; b < a; b++)
                heap.push (line[b]);
            lequal = a - 1;
        }
        
        if (heap.empty())
            ans[line[a].index] = -1;
        else
        {
            //cout << a << " " << heap.top().index << " " << heap.top().age << "\n";
            ans[line[a].index] = max (line[a].index - heap.top().index - 1, -1);
        }
    }
    /*for (int a = 0; a < n; a++)
        cout << line[a].index << " " << line[a].age << "\n";*/
    for (int a = n - 1; a >= 0; a--)
    {
        cout << ans[a];
        if (a == 0)
            cout << "\n";
        else
            cout << " ";
    }
    return 0;
}