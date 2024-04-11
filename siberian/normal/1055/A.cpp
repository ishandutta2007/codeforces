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


using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

#define int long long
int n, s;
vector <int> a, b;
void read()
{
    cin >> n >> s; s--;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
}

void run()
{
    if (!a[s] && !b[s])
        cout << "NO\n";
    else if (!a[0])
        cout << "NO\n";
    else if (a[s])
        cout << "YES\n";
    else
    {
        for (int i = s + 1; i < n; i++)
        {
            if (b[i] && a[i])
            {
                cout << "YES\n";
                exit(0);
            }
        }
        cout << "NO\n";
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