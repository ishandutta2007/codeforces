#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define PB push_back

using namespace std;

int main()
{
    int a1,a2,a3,a4;
    cin >> a1 >> a2 >> a3 >> a4;
    if (abs(a3-a4)>1) {cout<<"-1";return 0;}
    if (a1<max(a3,a4) || a2<max(a3,a4)) {cout<<"-1";return 0;}
    if (a1 == a2 && a1 == a3 && a1==a4) {cout<<"-1";return 0;}
    vector <int> res;
    if (a3==a4){
                if (a1==a3){
                            res.PB(7);
                            FOR(i,0,a3)
                            {res.PB(4);res.PB(7);}
                            FOR(i,0,a2-a3-1)
                            res.PB(7);
                }
                else{
                FOR(i,0,a1-a3-1)
                              res.PB(4);
                FOR(i,0,a3){res.PB(4);res.PB(7);}
                FOR(i,0,a2-a4)
                              res.PB(7);
                res.PB(4);}
    }
    if (a3==a4+1){
                FOR(i,0,a1-a3)
                              res.PB(4);
                FOR(i,0,a3){res.PB(4);res.PB(7);}
                FOR(i,0,a2-a4-1)
                              res.PB(7);
    }
     if (a3==a4-1){
                   res.PB(7);
                   FOR(i,0,a1-a3)
                              res.PB(4);
                FOR(i,0,a3-1){res.PB(7);res.PB(4);}
                FOR(i,0,a2-a4+1)
                              res.PB(7);
                res.PB(4);
    }
    FOR(i,0,res.size())
    printf("%d",res[i]);
    //system("pause");
    return 0;
}