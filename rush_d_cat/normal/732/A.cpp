#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 200000 + 10;
typedef long long ll;
int k, r;
int main()
{
    cin >> k >> r;
    int t = k%10;
    if(t==0) cout<<1<<endl;
    else{
        int i;
        for(i = 1; i <= 9; i++)
        {
            if((t*i) % 10 == r || (t*i)%10 == 0)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
}