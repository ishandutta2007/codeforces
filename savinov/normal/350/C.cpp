#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <list>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
/**
 * @author: Shamir14 -- Amirhossein Shapoori
 * lordamir14@gmail.com
 * ACM team: AnotherChorMangz
 * Tehran, Iran
 * Still listening to Mark Knopfler...
 * :P
 */
 

typedef long long ll;
#define pii pair<int, int>
#define pB push_back
#define mP make_pair
#define X first
#define Y second
#define SP system("pause");
#define assert(x) {cerr << (#x) << ": " << (x) << "\n";}
const double EPS=1e-9, PI=2*acos(0.0);
const int maxn=2*100000+10, MOD=1000*1000*1000+7, INF=1000*1000*1000;


vector <pii> sec[4];

int main(){
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int i, n, x, y, move;

    while(cin >> n){
        for(i=0;i<4;i++)
            sec[i].clear();
        move=0;
        for(i=0;i<n;i++){
            cin >> x >> y;
            if(x==0 || y==0) move+=4;
            else move+=6;
            if(x>=0 && y>=0)
                sec[0].pB(mP(x, y));
            if(x<0 && y>=0)
                sec[1].pB(mP(-x, y));
            if(x<0 && y<0)
                sec[2].pB(mP(-x, -y));
            if(x>=0 && y<0)
                sec[3].pB(mP(x, -y));
        }

        cout << move << "\n";

        sort(sec[0].begin(), sec[0].end());
        for(i=0;i<sec[0].size();i++){
            x=sec[0][i].X; y=sec[0][i].Y;
            if(x)
                cout << 1 << " " << x << " R" << "\n";
            if(y)
                cout << 1 << " " << y << " U" << "\n";
            cout << 2 << "\n";
            if(y)
                cout << 1 << " " << y << " D" << "\n";
            if(x)
                cout << 1 << " " << x << " L" << "\n";
            cout << 3 << "\n";
        }

        sort(sec[1].begin(), sec[1].end());
        for(i=0;i<sec[1].size();i++){
            x=sec[1][i].X; y=sec[1][i].Y;
            if(x)
                cout << 1 << " " << x << " L" << "\n";
            if(y)
                cout << 1 << " " << y << " U" << "\n";
            cout << 2 << "\n";
            if(y)
                cout << 1 << " " << y << " D" << "\n";
            if(x)
                cout << 1 << " " << x << " R" << "\n";
            cout << 3 << "\n";
        }


        sort(sec[2].begin(), sec[2].end());
        for(i=0;i<sec[2].size();i++){
            x=sec[2][i].X; y=sec[2][i].Y;
            if(x)
                cout << 1 << " " << x << " L" << "\n";
            if(y)
                cout << 1 << " " << y << " D" << "\n";
            cout << 2 << "\n";
            if(y)
                cout << 1 << " " << y << " U" << "\n";
            if(x)
                cout << 1 << " " << x << " R" << "\n";
            cout << 3 << "\n";
        }

        sort(sec[3].begin(), sec[3].end());
        for(i=0;i<sec[3].size();i++){
            x=sec[3][i].X; y=sec[3][i].Y;
            if(x)
                cout << 1 << " " << x << " R" << "\n";
            if(y)
                cout << 1 << " " << y << " D" << "\n";
            cout << 2 << "\n";
            if(y)
                cout << 1 << " " << y << " U" << "\n";
            if(x)
                cout << 1 << " " << x << " L" << "\n";
            cout << 3 << "\n";
        }



    }


    return 0;
}