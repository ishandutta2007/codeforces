#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct seg
{
    int start;
    int end;
};

struct point
{
    int val;
    long long ways;
};

point num[400100];
seg bus[100100];
//long long dp[100100];
int loc[100100]; // 1-based
int fstart[100100];
int fend[100100]; // for bus a what dpval
int bin[30];
int n, m;
int p, dcount;

void update (int index, long long value) // adds value to element at index
{
     int cur = index + p;
     while (cur > 0)
     {
           num[cur].ways = (num[cur].ways + value + 1000000007) % 1000000007;
           cur /= 2;
     }
}

long long query (int x)
{
    for (int a = dcount - 1; a >= 0; a--)
    {
        bin[a] = x % 2;
        x /= 2;
    }
    int cur = 1;
    long long sum = 0;
    for (int a = 0; a < dcount; a++)
    {
        if (bin[a] == 1)
        {
           sum = (sum + num[2*cur].ways) % 1000000007;
           cur = 2 * cur + 1;
        }
        else
            cur = 2 * cur;
    }
    return sum;
}

inline bool operator < (seg left, seg right)
{
    if (left.end != right.end)
        return left.end < right.end;
    return left.start < right.start;
}

bool cmp (seg left, seg right)
{
    return left.start < right.start;
}

int main()
{
    cin >> n >> m;
    p = 1;
    dcount = 0;
    for (int a = 0; a < m; a++)
        cin >> bus[a].start >> bus[a].end;
    sort (bus, bus + m);
    int count = 0;
    loc[0] = 0;
    for (int a = 0; a < m; a++)
    {
        if (a > 0)
            if (bus[a].end == bus[a-1].end)
            {
                fend[a] = count;
                continue;
            }
        fend[a] = count + 1;
        loc[count+1] = bus[a].end;
        count++;
    }
    /*sort (bus, bus + m, cmp);
    int cur = 0;
    for (int a = 0; a < m; a++)
    {
        while (loc[cur] < bus[a].start)
            cur++;
        fstart[a] = 100050;
        if (loc[cur] == bus[a].start)
            fstart[a] = cur;
    }
    sort (bus, bus + m);*/
    int cur = 0;
    while (p < count + 1)
    {
        p *= 2;
        dcount++;
    }
    for (int a = 0; a < 2 * p; a++)
    {
        num[a].ways = 0;
        num[a].val = 0;
    }
    update (0, 1);
    for (int a = p + 1; a < p + 1 + count; a++)
        num[a].val = loc[a-p];
    for (int a = 0; a < m; a++)
    {
        int s, e; // s = first >= start, e = last < end
        int temp = bus[a].start;
        int lo = 0, hi = count;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (num[mid + p].val < temp)
                lo = mid + 1;
            else
                hi = mid;
        }
        s = lo;
        lo = 0; hi = count;
        temp = bus[a].end;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (num[mid + p].val < temp)
                lo = mid;
            else
                hi = mid - 1;
        }
        e = lo;
        long long add = query (e+1) - query (s);
        update (fend[a], add);
    }
    /*for (int a = 0; a <= count; a++)
        cout << query (a) << "\n";
    for (int a = 0; a <= count; a++)
        cout << num[p+a].val << "\n";
    for (int a = 0; a <= count; a++)
        cout << num[p+a].ways << "\n";*/
    if (bus[m-1].end == n)
        cout << num[p + count].ways << "\n";
    else
        cout << 0 << "\n";
    return 0;
}