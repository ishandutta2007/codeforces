#include <iostream>
#include <algorithm>

using namespace std;

struct point
{
    int index;
    int val;
    bool two;
};

point list[100100];

inline bool cmp (point a, point b)
{
    if (a.val != b.val)
        return a.val < b.val;
    return a.index < b.index;
}

inline bool cmp2 (point a, point b)
{
    if (a.val != b.val)
        return a.val < b.val;
    return a.index > b.index;
}

inline bool cmp3 (point a, point b)
{
    return a.index < b.index;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x == y)
    {
        for (int a = 0; a < x; a++)
            cout << 1 << " ";
        for (int a = 0; a < y; a++)
        {
            cout << 2;
            if (a != y - 1)
                        cout << " ";
        }
        return 0;
    }        
    for (int a = 0; a < 100100; a++)
    {
        list[a].index = a;
        list[a].two = false;
    }    
    for (int a = 0; a < n; a++)
        cin >> list[a].val;
    if (x > y)
    {
        sort (list, list + n, cmp);
        for (int a = n - y; a < n; a++)
                list[a].two = true;
    }    
    else
    {
        for (int a = 0; a < 100100; a++)
                list[a].two = true;
        sort (list, list + n, cmp2);
        for (int a = n - x; a < n; a++)
                list[a].two = false;
    }
    sort (list, list + n, cmp3);
    for (int a = 0; a < n; a++)
    {
        if (a > 0) cout << " ";
        if (list[a].two)
                cout << 2;
        else
                cout << 1;
    }
    cout << "\n";
    //system ("Pause");
    return 0;
}