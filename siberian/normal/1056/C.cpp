#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <stdio.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

#define int long long

int n, m;
vector <int> x;
vector <pair <int, int> > a;
int t;
void read()
{
    cin >> n >> m;
    x.resize(2 * n + 1, -1e9);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> x[i];
    }
    
    a.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
        if (x[a[i].first] < x[a[i].second])
            swap(a[i].first, a[i].second);
    }
    cin >> t;
}

void run()
{
    if (t == 2)
    {
        int cnt = 0;
        for (int i123 = 0; i123 < n; i123++)
        {
            int hod_prot;
            cin >> hod_prot;
            x[hod_prot] = -1e9;
            bool flag = false;
            
            for (int j = 0; j < m; j++)
            {
                if (a[j].first == hod_prot)
                {
                    flag = true;
                    cout << a[j].second << endl;
                    cout.flush();
                    x[a[j].second] = -1e9;
                    cnt++;
                    a[j] = { -1,-1 };
                    break;
                }

                if (a[j].second == hod_prot)
                {
                    flag = true;
                    cout << a[j].first << endl;
                    cout.flush();
                    cnt++;
                    x[a[j].first] = -1e9;
                    a[j] = { -1, -1 };
                    break;
                }
            }
            if (flag)
                continue;

            if (cnt != m)
            {
                int pos = 0;
                int maxm = 0;
                int i1 = 0;
                for (int i = 0; i < m; i++)
                {
                    if (a[i].first == -1)
                        continue;
                    if (maxm < x[a[i].first])
                    {
                        maxm = x[a[i].first];
                        pos = a[i].first;
                        i1 = i;
                    }
                }
                cout << pos << endl;
                x[pos] = -1e9;
                a[i1] = { -1, -1 };
                cnt++;
                cout.flush();
                continue;
            }

            int pos = 0;
            int maxm = 0;
            for (int i = 0; i < 2 * n + 1; i++)
            {
                if (x[i] > maxm)
                {
                    maxm = x[i];
                    pos = i;
                }
            }

            cout << pos << endl;
            cout.flush();
            x[pos] = -1e9;
        }
    }
    else
    {
        int cnt = 0;
        for (int i123 = 0; i123 < n; i123++)
        {
            
            if (cnt != m)
            {
                int pos = 0;
                int maxm = 0;
                int i1 = 0;
                for (int i = 0; i < m; i++)
                {
                    if (a[i].first == -1)
                        continue;

                    if (maxm < x[a[i].first])
                    {
                        maxm = x[a[i].first];
                        pos = a[i].first;
                        i1 = i;
                    }
                }
                cout << pos << endl;
                x[pos] = -1e9;
                a[i1] = { -1, -1 };
                cout.flush();
                int hod_prot;
                cin >> hod_prot;
                x[hod_prot] = -1e9;
                cnt++;
                continue;
            }

            int pos = 0;
            int maxm = 0;
            for (int i = 0; i < 2 * n + 1; i++)
            {
                if (x[i] > maxm)
                {
                    maxm = x[i];
                    pos = i;
                }
            }

            cout << pos << endl;
            cout.flush();
            x[pos] = -1e9;
            int hod_prot;
            cin >> hod_prot;
            x[hod_prot] = -1e9;
        }
    }
}

void write()
{

}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}