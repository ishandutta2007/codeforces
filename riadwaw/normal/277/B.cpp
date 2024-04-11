/*
 * File:    main.cpp
 * Author:  Hrayr [HarHro94]
 * Problem: codeforces
 * IDE:     Visual C++ 2008
 */
//#pragma comment(linker, "/STACK:66777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define LL long long
#define LD long double

#define pi acos(-1.0)

vector<pair<int, int> > points;
int n, m;

bool ok(int x, int y)
{
    for(int i=0;i<points.size();++i)
    {
        for(int j=i+1;j<points.size();++j)
        {
            LD dx1=x-points[i].first;
            LD dy1=y-points[i].second;
            LD dx2=x-points[j].first;
            LD dy2=y-points[j].second;
            if (fabs(dx1*dy2-dx2*dy1) <= 1e-6)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double startTime=clock();
#endif
    
    int i;
    scanf("%d%d", &n, &m);
    if (n>4 && m==3)
    {
        cout << -1 << endl;
        return 0;
    }
    srand(time(NULL));
    LD R=1e7;
    LD fi=0.0;
    LD dfi=2*pi/m;
    for(i=0;i<m;++i)
    {
        LD x=R*cos(fi);
        LD y=R*sin(fi);
        int px=(int)x;
        int py=(int)y;
        points.pb(mp(px, py));
        while(!ok(px, py))
        {
            if (rand()&1)
            {
                px++;
            }
            else 
            {
                py++;
            }
        }
        cout << px << "  " << py << endl;
        fi+=dfi;
    }
    R=1e6;
    fi=34.7456137;
    dfi=2*pi/(n-m);
    for(i=0;i<n-m;++i)
    {
        LD x=R*cos(fi);
        LD y=R*sin(fi);
        int px=(int)x;
        int py=(int)y;
        points.pb(mp(px, py));
        while(!ok(px, py))
        {
            if (rand()&1)
            {
                px++;
            }
            else 
            {
                py++;
            }
        }
        cout << px << "  " << py << endl;
        fi+=dfi;
    }

#ifdef harhro94
    double endTime=clock();
    printf("\nExecution time = %.3lf s", (endTime-startTime)/1000.0);
#endif
    
    return 0;
}