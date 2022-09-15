#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    li n,m,s;
    cin>>n>>m>>s;
    cout<<(n%s?(n%s*(n/s+1)):n)*(m%s?(m%s*(m/s+1)):m);
    return 0;
}