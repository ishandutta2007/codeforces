#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const int maxn = 128;

char str[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int B;
    scanf("%s", str);
    scanf("%d", &B);
    int A;
    if (str[0] == 'f') {
        A = 0;
    } else {
        A = 1;
    } 
    B --;
    if (A == B)
        puts("L");
    else
        puts("R");
}