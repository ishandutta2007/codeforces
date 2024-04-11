#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define N 50000005
typedef long long LL;

int n , k;
bool f[N];
vector<int> res;
int p[5] = {2 , 3 , 5 , 7 , 11};
void work()
{
    int i , j ,  x , cnt[5] = {} , test = 0;
    cin >> k;
    if (k > 300) {



    f[2] = f[3] = f[5] = f[7] = f[11] = 1;
    for (i = 2 ; i <= k*k*2; ++ i) if (f[i])
    {
        res.push_back(i);
        //printf("%d\n" , i);
        if (i * 2 < N) f[i * 2] = 1;
        if (i * 3 < N) f[i * 3] = 1;
        if (i * 5 < N) f[i * 5] = 1;
        if (i * 7 < N) f[i * 7] = 1;
        if (i * 11 < N) f[i * 11] = 1;
    }


    for (i = upper_bound(res.begin() , res.end() , k * k * 2) - res.begin() - 1 ; ~i && test < k ; -- i)
    {
        printf("%d " , res[i]);
        ++ test;
       /* for (j = 0 ; j < 5 ; ++ j)
            if (res[i] % p[j] == 0)
                ++ cnt[j];*/
    }
    //for (i = 0 ; i < 5 ; ++ i)
    //    cout << cnt[i] << endl;
    //return;
}else{
    f[2] = f[3] = f[5] = 1;
    for (i = 2 ; i <= k*k*2; ++ i) if (f[i])
    {
        res.push_back(i);
        //printf("%d\n" , i);
        if (i * 2 < N) f[i * 2] = 1;
        if (i * 3 < N) f[i * 3] = 1;
        if (i * 5 < N) f[i * 5] = 1;
        //if (i * 7 < N) f[i * 7] = 1;
        //if (i * 11 < N) f[i * 11] = 1;
    }


    for (i = upper_bound(res.begin() , res.end() , k * k * 2) - res.begin() - 1 ; ~i && test < k ; -- i)
    {
        printf("%d " , res[i]);
        ++ test;
       /* for (j = 0 ; j < 4 ; ++ j)
            if (res[i] % p[j] == 0)
                ++ cnt[j];*/
    }
    //for (i = 0 ; i < 4 ; ++ i)
   //     cout << cnt[i] << endl;
}
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}