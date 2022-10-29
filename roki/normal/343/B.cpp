#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

string s;

bool read()
{
    if(!(getline(cin,s)))
        return false;
    return true;
}

int d[100000];

void solve()    
{

    for (int i = s.size() - 1; i >= 0; --i)
    {
        if(i == s.size() - 1)
            d[i] = 1;
        else
        {
            if(s[i] == s[i + 1])
                d[i] = d[i + 1] + 1;
            else
                d[i] = 1;
        }
    }
    set<pair<int, int> > p;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if(i == 0 || s[i] != s[i - 1])
        {
            int val = d[i];
            if(s[i] == '-')
                val *= -1;
            p.insert(mp(i, val));
        }
    }

    for (set<pair<int, int> >::iterator it = p.begin(); it != p.end(); ++it)
    {
        pair<int, int> cur = *it;
        while(cur.second % 2 == 0)
        {
            if(it == p.begin())
            {
                p.erase(cur);
                if(p.empty())
                    break;
                it = p.begin();
                cur = *it;
                continue;
            }
            it--;
            p.erase(cur);
            set<pair<int, int>>::iterator it1 = it;
            it++;
            if(it == p.end())
                break;
            set<pair<int, int>>::iterator it2 = it;
            it++;
            if(it1->second * it2->second > 0)
            {
                cur = mp(it1->first, it1->second + it2->second);
                p.erase(it2);
                p.erase(it1);
                p.insert(cur);
                it--;
            }
            else
            {
                it--;
                it--;
            }
        }
        if(p.size() == 0)
            break;
    }

    if(p.size() == 0)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();
    
    return 0;
}