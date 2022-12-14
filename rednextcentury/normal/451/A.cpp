#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int moves=min(n,m);
    if (moves%2!=0)
        cout<<"Akshat"<<endl;
    else
        cout<<"Malvika"<<endl;
}